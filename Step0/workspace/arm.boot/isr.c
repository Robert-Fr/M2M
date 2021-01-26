#include "isr.h"


   void irq_handler(){
       //TODO : coder les fonctions manquantes + definir UART0_IRQ (voir doc) :
       /*
       void irq_handler(void) {
            for (;;) {
                int irq = pic_next_raised_irq();
                switch (irq) {
                    case -1:
                    pic_enable_all_irqs();
                    return;
                    case UART0_IRQ:
                    uart0_isr();
                    break;
                }
            }
        }
       */
   }

   void irqs_setup(){
    /* TODO : 
    //init uart : soft ( buffer ) + hard (autoriser à lever exception etc)
    //init vic : hard  ( autoriser l'uart a reveiller )
    */
}

   void irqs_enable(){
       //TODO : appel a irqs_enable (exception.s) ?
   }

   void irqs_disable(){
       //TODO : appel a irqs_disable (exception.s) ?
   }