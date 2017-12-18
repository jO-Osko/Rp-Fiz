/*Sestavi program, ki bo za dani niz preveril, ali je palindrom. Niz je palindrom, če se z obeh strani enako prebere. Ignoriraj vse znake, ki niso črke angleške abecede, in ne ločuj med malimi in velikimi črkami.

Vnesi niz: Ali se bo Gordana na drog obesila?
Niz je palindrom. */

#include <stdio.h>
#include <string.h>
#include <ctype.h> //za isalnum() in tolower()

# define MAX 100 //ali pa samo napises v niz[]

int main(void) {

    //zajem podatkov
    char niz[MAX];

    printf("Vnesi niz: ");
    gets(niz);


    //ciscenje niza
    int i, j = 0;

    while (niz[i]) { //dokler ne pridemo do konca, torej do  niz[i] = '\0'
        if (!isalnum(niz[i])) ++i;
        else {
            niz[j] = tolower(niz[i]); //seveda obstaja tudi toupper()
            ++j;
            ++i;
        }
    }

    niz[j] = '\0';


    //preverimo, kaj smo do sedaj naredili
    i = 0;
    while (niz[i]) {
        printf("%c", niz[i]);
        ++i;
    }


    //ali je niz palindrom?
    i = 0;
    j = strlen(niz) - 1;

    int palindrom = 2; //stikalo

    while (i < j) {
        palindrom = 1;

        if (niz[i] != niz[j]) {
            printf("\nNiz ni palindrom.");
            palindrom = 0;
            break;
        }

        ++i;
        --j;
    }

    if (palindrom == 1) printf("\nNiz je palindrom.");

    return 0;
}



