#include <stdio.h>
#include <stdlib.h>

#include "tabele.h"

int main(void) {
    int n;
    int *tabela = vnosTabele("Vnesi dolzino table: ", "Vnasi %d. element tabele: ", &n);
    int k;
    printf("Vnesi k: ");
    scanf("%d", &k);
    // Pri tej nalogi ne potrebujemo tabele (rezultatov), saj lahko posamezne rezultate računamo sproti.
    // Prav tako ne potrebujemo vsakič ponovno sešteti vseh k zaporednih števil.
    // Še več, če bi lahko k prebrali pred celotno tabelo bi (ob malo več igranja) potrebovali le tabelo k(+1) elementov
    // Razmislek kako storiti to je namenjen domači nalogi (in zagtovo pride prav pri predmetu, kjer boste kakorkoli
    // preučevali algoritme)
    // Namig: Circular queue
    if (k > n) {
        printf("Tole pa nisi najbolje razmislil?");
        return 0;
    }
    int dolzina = n - k + 1;
    int trenutna_vsota = 0;
    int *zaporedne_vsote = malloc(dolzina * sizeof(*zaporedne_vsote));
    for (int j = 0; j < k; ++j) {
        trenutna_vsota += tabela[j];
    }
    zaporedne_vsote[0] = trenutna_vsota;
    for (int j = 0; j < dolzina; ++j) {
        trenutna_vsota = trenutna_vsota + tabela[j + k] - tabela[j];
        zaporedne_vsote[j + 1] = trenutna_vsota;
    }
    izpisTabele("Vsote:", zaporedne_vsote, dolzina);

    return 0;
}