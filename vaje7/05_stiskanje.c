/* Sestavi program, ki bo iz danega niza sestavil nov niz tako, da ga bo stisnil. Pri stiskanju naj več zaporednih pojavitev istega znaka nadomesti s tem znakom in številom njegovih pojavitev (predpostaviš lahko, da bo zaporednih pojavitev istega znaka vedno manj kot 10). Program nato dopolni še z obratno operacijo, ki bo iz stisnjega niza izdelala nazaj prvotni niz.

         Vnesi niz: aaabba cccddddd
         Stisnjen niz: a3b2a c3d5
         Prvotni niz: aaabba cccddddd */

#include <stdio.h>
#include <string.h>

#define MAX 100

int main(void) {

    char niz[MAX];
    printf("Vnesi niz: ");
    gets(niz);

    int i;

    int stevec;
    stevec = 1;

    printf("Stisnjen niz: ");

    //stiskanje

    for (i = 0; niz[i] != '\0'; i++) {

        if (niz[i] == niz[i + 1]) stevec += 1;

        else if (niz[i] != niz[i + 1] && stevec > 1) {
            printf("%c%d", niz[i], stevec);
            stevec = 1;
        } else if (niz[i] != niz[i + 1] && stevec == 1) {
            printf("%c", niz[i]);
            stevec = 1;
        }

    }

    //obratna operacija


    return 0;
}



