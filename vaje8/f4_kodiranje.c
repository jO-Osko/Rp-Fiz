#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

//funkcija: ciklicna permutacija angleskih crk za periodo
char cycleengchar(char a, int perioda) {
    //poenostavimo vnos periode
    if (perioda > 26 || perioda < -26) {
        perioda = perioda % 26;
    }

    //b inicializiramo kot a, za primer ce a ni angleska crka.
    char b = a;
    if (a >= 'a' && a <= 'z') {
        b += perioda;
        if (b < (int) 'a') { //(int)'a' je enak 97
            b += 26;
        } else if (b > (int) 'z') {  //(int)'z' je enak 122
            b -= 26;
        }
    } else if (a >= 'A' && a <= 'Z') {
        b += perioda;
        if (b < (int) 'A') {  //(int)'A' je enak 65
            b += 26;
        } else if (b > (int) 'Z') {  //(int)'Z' je enak 90
            b -= 26;
        }
    }

    return b;
}

//funkcija: kodiranje angleskih crk v nizu z funkcijo cyclechar
void zakodirajniz(char niz[MAX], int perioda) {
    for (int i = 0; i < strlen(niz); i++) {
        niz[i] = cycleengchar(niz[i], perioda);
    }
}

//preverimo delovanje funkcij
int main(void) {
    char niz[MAX];
    printf("Vnesi niz: ");
    fflush(stdin);
    gets(niz);

    int premik;
    printf("Vnesi premik: ");
    scanf("%d", &premik);

    zakodirajniz(niz, premik);
    printf("Zakodiran niz: %s", niz);

    return 0;
}


/* OP: Pri kodiranju nizov bi bilo smiselno kot parameter podajati funkcijo (glej fdod_parameterfunkcija), ki izvaja doloceno preslikavo znakov!
Preslikave znakov v grobem lahko razdelimo na simetrične(bijektivne) in asimetrične. */