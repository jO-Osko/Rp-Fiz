/*
Sestavi program, kjer bo v danem nizu vse velike črke pretvoril v ustrezne male črke, in obratno. 
* Vse druge znake naj pusti nespremenjene.

Vnesi niz: abc+XYZ
Predelan niz: ABC+xyz */

#include <stdio.h>
#include <string.h>

int main(void) {

    char niz[100];
    printf("Vnesi niz: ");
    gets(niz);

    int razlika = 'a' - 'A'; //

    for (int i = 0; niz[i] != '\0'; ++i) {
        
        if (niz[i] >='a'  && niz[i] <= 'z') printf("%c", niz[i]-razlika);         //male crke //  znak lahko oznacimo tako: 'znak'
        else if ( niz[i] >= 64 && niz[i] <= 90) printf("%c", niz[i]+razlika);          //velike crke // ali pa z ASCII kodo 64--> 'A', 90--->'Z'
        else printf("%c", niz[i]); // ostali znaki
    }
   
    return 0;
}
