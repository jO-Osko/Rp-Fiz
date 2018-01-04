#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


//funkcija ki v nizu izbrise dolocen znak in vrne stevilo znakov ki jih je izbrisal
int strElChar(char niz[MAX], char a) {
    //stejemo izbrisane znake
    int cnt = 0;
    //stejemo kje smo po novem v nizu
    int j = 0;

    for (int i = 0; i < (strlen(niz) + 1); i++) { //prebrati moramo tudi znak '\0'

        //za vsak znak v nizu pregledamo ce je enak nasemu znaku a
        if (niz[i] == a) {
            //ce je poiscemo naslednji znak ki je od a razlicen
            while (1) {
                i++;
                cnt++;
                if (niz[i] != a) break;
            }
        }

        //ko najdemo od a razlicen znak prepisujem niz
        niz[j] = niz[i];
        if (niz[j] == '\0') break;
        j++;
    }

    return cnt;
}

int main(void) {
    char niz[MAX];
    printf("Vnesi niz: ");
    fflush(stdin);
    gets(niz);

    char a;
    printf("Vnesi znak: ");
    scanf("%c", &a);

    int n = strElChar(niz, a);

    printf("Stevilo odstranjenih znakov: %d\n", n);
    printf("Predelan niz: %s", niz);

    return 0;
}