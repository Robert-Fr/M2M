#include "isr.h"

    /*
     Cette fonction est appelé par la fonction _irq_handler de exception.s :
     Quand le PIC demande au processeur de traiter une exception IRQ, et que le 
     processeur décide de la traiter, on arrive ici.
     - Il faut donc commencer par savoir quelle est la source de l'exception,
     si c'est l'UART0 (celui odnt on veut s'occuper ici) on appelle la routine
     associée afin de traiter l'exception.  
    */
   void irq_handler(){
       //irqs_disable();
       //uart_send_string(UART0, "\n\rIRQ_HANDLER\n\r");
       //TODO : coder les fonctions manquantes + definir UART0_IRQ (voir doc) :
        for (;;) {
            int irq = pic_next_raised_irq();
            switch (irq) {
                case -1:
                    //pic_enable_all_irqs();
                    //_irqs_enable();
                    return;
                case UART0_IRQ:
                    uart0_isr();
                    break;
                }
         }
   }
   
   /* 
    Cette fonction est appelé au lancement de notre "kernel", elle permet de 
    mettre en place tout ce qui est nécessaire à la gestion des exceptions IRQ :
    - Il faut autoriser l'UART a lever des exceptions :
    -> Pour ce faire : voir dans la doc de la board l'adresse du registre UART IMSC 0
    et voir quel bit il faut mettre à 1 pour signifier que l'UART0 peut lever des exceptions IRQ
    - Il faut définir l'adresse de la pile (stack) que notre programme va utiliser quand il sera
    en mode IRQ (les différents mode de processeur ne partageant pas tous les registres,
    c'est le cas ici pour r13 (le stack-pointer) et r14 (le link register) par ex ) :
    -> Pour ce faire : appel a la fonction _irqs_setup qui nous est fournie. 
    (Note : il a fallut définir dasn le linker script un espace pour cette nouvelle stack)
    - Il faut initialiser un buffer circulaire dans lequel on va mettre les caractères 
    que l'on peut lire dans l'UART0
    -> Pour ce faire on implémente une structure de buffer circulaire
    - Il faut autoriser l'UART0 à lever des exceptions au niveau du PIC :
    -> Pour ce faire je sais pas encore (voir doc) mais il faut passer un bit a 1 dans un mask (VICINTENABLE ou VICINTENCLEAR)
    */
   void irqs_setup(){
       //uart_send_string(UART0, "\n\rIRQ_SETUP\n\r");
       // Appel a la fonction copy_vector qui nous est fourni
       _copy_vector();
        //On met en place le stack du mode IRQ :
        _irqs_setup(); 
        // On autorise les interruptions au niveau de l'UART :
        int* pt = UART0IMSC;
        *pt=RXIM; //on met les 4ème bit à 1
        //On autorise les interruptions au niveau du VIC
        pt = VICINTENABLE;
        *pt= VIC_UART0_LINE; //on met le bit à 1
        //appel a irqs_enable()
        irqs_enable();
    }

    /*
     Cette fonction autorise les exceptions au niveau du processeur 
     en modifiant le CPSR. Le code est fournie dans la fonction _irqs_enable
     dans exceptions.s. 
    */
   void irqs_enable(){
       //uart_send_string(UART0, "\n\rIRQ_ENABLE\n\r");
       _irqs_enable();
   }
    /*
     Cette fonction désactive les exceptions au niveau du processeur 
     en modifiant le CPSR. Le code est fournie dans la fonction _irqs_enable
     dans exceptions.s.
     Pendant que le processeur ne gère plus les exceptions, le PIC lui continue 
     de le faire, ainsi, si on réactive les exceptions le processeur gerera les 
     exceptions qui ont été mise "en attente " le temps ou les exceptions étaient
     désactivés à ce niveau.
    */
   void irqs_disable(){
       //uart_send_string(UART0, "\n\rIRQ_DISABLE\n\r");
       _irqs_disable();
   }
    /*   Cette fonction est appelée lorsqu'une exception à été levée et que le processeur est passée en mode IRQ
     - Il faut renvoyer un entier qui permet d'identifier qui a levé l'exception 
     TODO : voir doc de la board pour savoir ou regarder en mémoire
    */
  int pic_next_raised_irq(){
      int i=0;
      int* pt= VICIRQSTATUS;
      for(i=0;i<31;i++){
          if(*pt & (1<<i))
            return i;
      }
      return -1;
   }
   
   /*   Cette fonction est appelé lorsque la valeur -1 est renvoyé par la fonction pic_next_raised_irq()
     - Il ne faut rien faire dans le contexte dans l'architecture dans laquelle on est
    */
   /*void pic_enable_all_irqs(){
       //Nothing
   }*/