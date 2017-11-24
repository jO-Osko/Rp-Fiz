#include <stdio.h>

// Tudi za to nalogo v resnici ne potrebujemo tabele, saj se lahko po stevilih sprehajamo kar zaporedoma

// Ideja: če želimo, da je tabela urejena nepadajoče, potem mora za 0 <= i < N-1 veljati t[i] <= t[i+1]
// Zaporedoma s sprehajamo po vhodnih podatkih in si hranimo zadnji prebran element, naslednji mora biti vecji ali enak,
// nato pa posodobimo zadnji element.

#define MAX 100

int main(void) {

    int n;
    printf("Vnesi stevilo elementov (med 2 in %d): ", MAX);
    scanf("%d", &n);

    int trenutni;
    int i = 0;
    printf("%d. element: ", i + 1);
    scanf("%d", &trenutni);
    ++i;

    int preverjaj = 1; // sli smo ze nasli napako

    for (; i < n; ++i) {
        int naslednji;
        printf("%d. element: ", i + 1);
        scanf("%d", &naslednji);
        if (preverjaj) {
            if (naslednji < trenutni) {
                preverjaj = 0;
            }
            trenutni = naslednji;
        }
        // Drugace se zgolj sprehodimo cez vhodne podatke do konca
    }

    if (preverjaj) {
        printf("Tabela je nepadajoce urejena.\n");
    } else {
        printf("Tabela ni nepadajoce urejena.\n");
    }

    return 0;
}