#include "uart.h"

/**
 * Receive a character from the given uart, this is a non-blocking call.
 * Returns 0 if there are no character available.
 * Returns 1 if a character was read.
 */
int uart_receive(int uart, unsigned char *s) {
  unsigned short* uart_fr = (unsigned short*) (uart + UART_FR);
  unsigned short* uart_dr = (unsigned short*) (uart + UART_DR);
  if (*uart_fr & UART_RXFE)
    return 0;
  *s = (*uart_dr & 0xff);
  return 1;
}

/**
 * Receive a character from the given uart, this is a blocking call.
 * Returns 1 when a character was read.
 */
int uart_receive_blocking(int uart, unsigned char *s) {
  unsigned short* uart_fr = (unsigned short*) (uart + UART_FR);
  unsigned short* uart_dr = (unsigned short*) (uart + UART_DR);
  while (*uart_fr & UART_RXFE)
  ;
  *s = (*uart_dr & 0xff);
  return 1;
}

/**
 * Sends a character through the given uart, this is a blocking call.
 * The code spins until there is room in the UART TX FIFO queue to send
 * the character.
 */
void uart_send(int uart, unsigned char s) {
  unsigned short* uart_fr = (unsigned short*) (uart + UART_FR);
  unsigned short* uart_dr = (unsigned short*) (uart + UART_DR);
  while (*uart_fr & UART_TXFF)
    ;
  *uart_dr = s;
}

/**
 * This is a wrapper function, provided for simplicity,
 * it sends a C string through the given uart.
 */
void uart_send_string(int uart, const unsigned char *s) {
  while (*s != '\0') {
    uart_send(uart, *s);
    s++;
  }
}

//On définit le buffer circulaire dont on se sert pour communiquer entre le mode IRQ et le programme principal
#define MAX_CHARS 256
volatile char buffer[MAX_CHARS];
volatile int head = 0;
volatile int tail = 0;

/*
     Cette fonction est appelée pour répondre à une exception levée par l'UART0 :
     - Il faut d'abord récupérer les caractères au niveau de l'UART tant qu'il y en a pour
     remplir le buffer circulaire (ou jusqu'a ce que le buffer soit plein)
     - Il faut une fois finit mettre 1 dans le registre UART Interrupt Clear, pour dire à
     l'UART que l'on a finit de traiter son exception pour qu'il puisse en lever de nouveau s'il en a besoin (Se fait tout seul si on lit dans la FIFO)
*/
void uart0_isr(){
  uart_send_string(UART0, "\n\rUART 0 ISR\n\r");
  char code;
  int is_next = uart_receive(UART0,&code);
  while (is_next) {
    int next = (head + 1) % MAX_CHARS;
    if (next==tail) //si le buffer est plein
      return; 
    //sinon on ajoute le caractère
    buffer[head] = code;
    head = next;
    is_next = uart_receive(UART0,&code);
  }
   //on dit a l'UART que son interruption a été traité
    unsigned short* pt = (unsigned short*) (UART0ICR);
    *pt= *pt | RXIC; //on met le bit à 1
}

//TODO :
int read_buffer(char* c){
  if (head == tail)
    return 0;
  else {
    *c = buffer[tail];
    tail++;
    return 1;
  }
}

