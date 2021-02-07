/*
 * uart.h
 *
 *  Created on: Jan 26, 2021
 *      Author: Francois Robert
 */

#ifndef UART_H_
#define UART_H_

//#include <stddef.h>

/**
 * Look at the document describing the Versatile Application Board:
 *
 *    Versatile Application Baseboard for ARM926EJ-S (HBI-0118)
 *
 * Also referenced as DUI0225, downloadable from:
 *
 *  http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0225d/I999714.html
 *
 * Look at the memory map, section 4.1, page 137, to find the base addresses for all
 * the devices. We only use here the UARTs.
 */
#define UART0 0x101f1000
#define UART1 0x101f2000
#define UART2 0x101f3000

/**
 * PL011_T UART
 *     http://infocenter.arm.com/help/topic/com.arm.doc.ddi0183f/DDI0183.pdf
 *
 * UARTDR: Data Register   (0x00)
 *    To read received bytes
 *    To write bytes to send
 *    Bit Fields:
 *      15:12 reserved
 *      11:08 error flags
 *       7:0  data bits
 * UARTFR:  Flag Register  (0x18)
 *    Bit Fields:
 *      7:  TXFE  transmit FIFO empty
 *      6:  RXFF  receive FIFO full
 *      5:  TXFF  transmit FIFO full
 *      4:  RXFE  receive FIFO empty
 *      3:  BUSY  set when the UART is busy transmitting data
 */

#define UART_DR 0x00
#define UART_FR 0x18

#define UART_TXFE (1<<7)
#define UART_RXFF (1<<6)
#define UART_TXFF (1<<5)
#define UART_RXFE (1<<4)
#define UART_BUSY (1<<3)

/**
 * Receive a character from the given uart, this is a non-blocking call.
 * Returns 0 if there are no character available.
 * Returns 1 if a character was read.
 */
int uart_receive(int uart, unsigned char *s);

/**
 * Receive a character from the given uart, this is a blocking call.
 * Returns 1 when a character was read.
 */
int uart_receive_blocking(int uart, unsigned char *s) ;

/**
 * Sends a character through the given uart, this is a blocking call.
 * The code spins until there is room in the UART TX FIFO queue to send
 * the character.
 */
void uart_send(int uart, unsigned char s);

/**
 * This is a wrapper function, provided for simplicity,
 * it sends a C string through the given uart.
 */
void uart_send_string(int uart, const unsigned char *s);

#define UART0IMSC UART0+0x38 // l'adresse du registre UART_IMSC de l'uart 0 (doc de l'UART)
#define RXIM (1<<4) //le 4ème bit du registre UARTIMSC : Receive interrupt mask (doc de l'UART)
#define UART0ICR UART0+0x44 //l'adresse du registre UART_ICR de l'uart 0 (doc de l'UART)
#define RXIC (1<<4) //le 4ème bit du registre UART_ICR : Receive interrupt clear (doc de l'UART)

#define VIC_BASE_ADDRESS 0x10140000 //adresse de base du VIC (trouvé dans la doc de la board : chapitre "interrupt controllers")
#define VICINTENABLE 0x10140010 //l'adresse du registre VICINTENABLE (trouvé sur la doc du VIC )
#define VICIRQSTATUS VIC_BASE_ADDRESS+0x000//l'adresse du registre VICIRQSTATUS (trouvé sur la doc du VIC )
#define VIC_UART0_LINE (1<<12) //Doc de la board section sur l'UART : il est dit que pour UART 0 c'est le 12ème bit pour les interruptions

#define UART0_IRQ 12

/*
     Cette fonction est appelée pour répondre à une exception levée par l'UART0 :
     - Il faut d'abord récupérer les caractères au niveau de l'UART tant qu'il y en a pour
     remplir le buffer circulaire (ou jusqu'a ce que le buffer soit plein)
     - Il faut une fois finit mettre 1 dans le registre UART Interrupt Clear, pour dire à
     l'UART que l'on a finit de traiter son exception pour qu'il puisse en lever de nouveau s'il en a besoin (Se fait tout seul si on lit dans la FIFO)
*/
void uart0_isr();

//TODO :
int read_buffer(char* c);

#endif /* UART_H_ */
