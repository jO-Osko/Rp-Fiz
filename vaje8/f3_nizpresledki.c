#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

//funkcija vzame niz in zamenja vse presledke s pomisljaji, vrne stevilo presledkov
//DN: kako bi naredili funkcijo, ki v splosnem zamenja katerakoli dva znaka?
int nizpresledki(char niz[MAX]) {
    //stejemo presledke
    int n = 0;

    //za vsak znak v nizu preverimo ce je presledek
    for (int i = 0; i < strlen(niz); i++) {
        if (niz[i] == ' ') {
            n++;
            niz[i] = '-';
        }
    }

    return n;
}


//preverimo delovanje funkcije
int main(void) {
    char niz[MAX];
    printf("Vnesi niz: ");
    fflush(stdin);
    gets(niz);

    printf("Stevilo presledkov: %d\n", nizpresledki(niz));
    printf("Predelan niz: %s", niz);

    return 0;
}