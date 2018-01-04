#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabele.h"

// Nalogo bomo rešili nekoliko bolj pametno (vedno bomo vedeli, kako velika bo naslednja beseda).

int main(void) {
    int n;
    char zacetna[] = "L";
    printf("Vnesi n: ");
    scanf("%d", &n);
    int stL = 1;
    int dolzina = strlen(zacetna);
    char *trenutna = malloc((dolzina + 1) * sizeof(trenutna));
    strcpy(trenutna, zacetna);
    printf("%s\n", trenutna);
    printf("%s\n", zacetna);
    --n;
    while (n) {
        int t = dolzina;
        dolzina = dolzina + stL;
        stL = t;
        char *nova = malloc((dolzina + 1) * sizeof(*nova));
        int ind = 0;
        for (int j = 0; trenutna[j]; ++j) {
            if (trenutna[j] == 'L') {
                nova[ind] = 'L';
                nova[ind + 1] = 'S';
                ind += 2;
            } else { // trenutna[j] == 'S'
                nova[ind] = 'L';
                ind += 1;
            }
        }
        nova[dolzina] = '\0';
        free(trenutna);
        trenutna = nova;
        --n;
    }
    printf("%s\n", trenutna);
    return 0;
}