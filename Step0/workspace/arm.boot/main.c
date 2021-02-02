#include "main.h"

/*
 * Define ECHO_ZZZ to have a periodic reminder that this code is polling
 * the UART, actively. This means the processor is running continuously.
 * Polling is of course not the way to go, the processor should halt in
 * a low-power state and wake-up only to handle an interrupt from the UART.
 * But this would require setting up interrupts...
 */
#define ECHO_ZZZ

/**
 * This is the C entry point, upcalled once the hardware has been setup properly
 * in assembly language, see the startup.s file.
 */
void c_entry() {
  //TODO : 
  //on appelle a irqs_setup() pour 
  //appel a irqs_enable()

  int i = 0;
  int count = 0;
  int first_char_arrow= 0;
  int second_char_arrow = 0;
  int first_char_del = 0;
  uart_send_string(UART0, "\nHello world!\n");
  uart_send_string(UART0, "\nQuit with \"C-a c\" and then type in \"quit\".\n");
  while (1) {
    unsigned char c;
#ifdef ECHO_ZZZ
    while (0 == uart_receive_blocking(UART0, &c)) {
      count++;
      if (count > 50000000) {
        uart_send_string(UART0, "\n\rZzzz....\n\r");
        count = 0;
      }
    }
#else
    if (0==uart_receive_blocking(UART0,&c))
    continue;
#endif
    if (c == 13) {
      uart_send(UART0, '\r');
      uart_send(UART0, '\n');
    } 
    else if (c == 51) { //DELETE
      first_char_del = 1;
    } 
    else if (first_char_del && c == 126) { //DELETE
      kprintf("DEL \n", c);
      first_char_del = 0;
    } 
    else if (c == 127) { //BACKSPACE
      kprintf("BACKSPACE \n", c);
    } 
    else if (c == 27) {
      first_char_arrow = 1;
    } 
    else if (first_char_arrow == 1 && c == 91) {
      second_char_arrow = 1;
    }
    else if (second_char_arrow ==1 && c == 68) {
      kprintf("fleche gauche \n", c);
      first_char_arrow=0;
      second_char_arrow=0;
    }
    else if (second_char_arrow ==1 && c == 67) {
      kprintf("fleche droite \n", c);
      first_char_arrow=0;
      second_char_arrow=0;
    }
    else {
      //uart_send(UART0, c);
      kprintf("code lu : %d \n", c);
      first_char_arrow=0;
      second_char_arrow=0;
      first_char_del = 0;
    }
  }
}
