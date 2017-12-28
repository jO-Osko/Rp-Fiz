#include <stdio.h>
#include <stdlib.h>

// Za dodatno preverjanje vključimo header file, da se tipi zagotovo ujemajo
#include "tabele.h"

// Uporaba:
// int* tabela = vnosTabele("Vnesi stevilo elementov: ", "Vnesi %d. element tabele: ", &n);

int *vnosTabele(char vnosDolzine[], char vnosElementa[], int *n) {
    printf(vnosDolzine);
    scanf("%d", n);

    int *seznam = malloc(*n * sizeof(*seznam));

    for (int j = 0; j < *n; ++j) {
        printf(vnosElementa, j + 1);
        scanf("%d", &seznam[j]);
    }

    return seznam;
}

// Uporaba:
// izpisTabele("Kumulativne vsote:", tabela, n);

void izpisTabele(char opis[], int *tabela, int n) {
    printf(opis);
    for (int j = 0; j < n; ++j) {
        printf(" %d", tabela[j]);
    }
    printf("\n");
}
