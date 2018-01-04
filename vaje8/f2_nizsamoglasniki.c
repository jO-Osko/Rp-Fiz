#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

//iz knjiznice string.h bomo uporabili naslednje funkcije
/* 
strlen(niz) vzame niz in vrne njegovo dolzino brez posebnega znaka '\0',
strchr(niz, znak) vrne NULL ce znaka ni v nizu, drugace pa kazalec na prvo pojavitev znaka v nizu,
*/

//globalno definiramo niz samoglasnikov (lahko tudi znotraj funkcije lokalno)
char samoglasniki[] = "aeiouAEIOU";

//funkcija vzame za parameter niz in vrne stevilo samoglasnikov v nizu
int nizsamoglasniki(char niz[MAX]) {
    //stejemo samoglasnike
    int n = 0;

    //za vsak znak v nizu preverimo ce je samoglasniki,
    //ce je znak samoglasnik potem je ta znak v nizu samoglasnik,
    for (int i = 0; i < strlen(niz); i++) {
        if (strchr(samoglasniki, niz[i]) != NULL) {
            n++;
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

    printf("Stevilo samoglasnikov: %d", nizsamoglasniki(niz));

    return 0;
}