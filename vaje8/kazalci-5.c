#include <stdio.h>
#include <stdlib.h>

#include "tabele.h"

// Pri tej nalogi prav tako ne potrebujemo tabele (niti vhodne niti izhodne)...
// Vendar si bomo iz pedagoških razlogov pogledali, kako to rešimo s tabelo.

int main(void) {
    int n;
    int *tabela = vnosTabele("Vnesi dolzino table: ", "Vnasi %d. element tabele: ", &n);
    int dolzina = 0;
    for (int j = 0; j < n; ++j) {
        if (tabela[j] % 2 == 0) {
            // Soda stevila bi lahko izpisali ze tukaj
            ++dolzina;
        }
    }
    int *sode = malloc(dolzina * sizeof(*sode));
    // Zapomnimo, kje smov tabeli sode
    int ind = 0;
    for (int j = 0; j < n; ++j) {
        if (tabela[j] % 2 == 0) {
            sode[ind] = tabela[j];
            ++ind;
        }
    }
    izpisTabele("Sodi elementi:", sode, dolzina);

    return 0;
}