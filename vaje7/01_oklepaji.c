/*Sestavi program, ki bo za dani niz preveril, ali so oklepaji v njem pravilno gnezdeni. Omejiš se lahko samo na okrogle oklepaje. Oklepaji so pravilno gnezdeni, če oklepaji in zaklepaji nastopaji v parih in število zaklepajev nikoli ne preseže števila oklepajev, ko jih štejemo od leve proti desni.

Vnesi niz: (a)xy((14+4(t))x(32))u
Oklepaji so pravilno gnezdeni. */

#include <stdio.h>
#include <string.h>

int main(void) {

    char niz[100];
    int oklepaji = 0;

    printf("Vnesi niz: ");
    gets(niz);

    for (int i = 0; niz[i] != '\0'; ++i) {

        if (niz[i] == '(') ++oklepaji;
        else if (niz[i] == ')') --oklepaji;
        if (oklepaji < 0) break;
    }

    if (oklepaji == 0) printf("Oklepaji so pravilno gnezdeni.");
    else printf("Oklepaji niso gnezdeni pravilno.");

    return 0;
}
