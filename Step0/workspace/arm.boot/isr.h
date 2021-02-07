/*
 * isr.h
 *
 *  Created on: Jan 26, 2021
 *      Author: Francois Robert
 */

#ifndef ISR_H_
#define ISR_H_

#include "uart.h"
/*
     Cette fonction est appelé par la fonction _irq_handler de exception.s :
     Quand le PIC demande au processeur de traiter une exception IRQ, et que le 
     processeur décide de la traiter, on arrive ici.
     - Il faut donc commencer par savoir quelle est la source de l'exception,
     si c'est l'UART0 (celui odnt on veut s'occuper ici) on appelle la routine
     associée afin de traiter l'exception.  
*/
void irq_handler();

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
    -> Pour ce faire on implémente une structure de buffer circulaire et on l'instancie en mémoire
    - Il faut autoriser l'UART0 à lever des exceptiosn au niveau du PIC :
    -> Pour ce faire il faut passer un bit a 1 dans un mask (VICINTENABLE)
*/
void irqs_setup();

/*
     Cette fonction autorise les exceptions au niveau du processeur 
     en modifiant le CPSR. Le code est fournie dans la fonction _irqs_enable
     dans exceptions.s. 
*/
void irqs_enable();

/*
     Cette fonction désactive les exceptions au niveau du processeur 
     en modifiant le CPSR. Le code est fournie dans la fonction _irqs_enable
     dans exceptions.s.
     Pendant que le processeur ne gère plus les exceptions, le PIC lui continue 
     de le faire, ainsi, si on réactive les exceptions le processeur gerera les 
     exceptions qui ont été mise "en attente " le temps ou les exceptions étaient
     désactivés à ce niveau.
*/
void irqs_disable();

/*   Cette fonction est appelée lorsqu'une exception à été levée et que le processeur est passée en mode IRQ
     - Il faut renvoyer un entier qui permet d'identifier qui a levé l'exception
*/
  int pic_next_raised_irq();

/*   Cette fonction est appelé lorsque la valeur -1 est renvoyé par la fonction pic_next_raised_irq()
     - Il ne faut rien faire dans le contexte dans l'architecture dans laquelle on est
*/
  //void pic_enable_all_irqs(){



 //je définis les fonctions ici même si elles osnt déclarés dans exception.s pour ne pas avoir de warning a la compilation
  void _irqs_setup(void);
  void _irqs_enable(void);
  void _irqs_disable(void);
  void _copy_vector(void);
  void _wfi(void);

#endif /* ISR_H_ */