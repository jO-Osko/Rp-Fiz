#include <stdio.h>


#define MAX 100

int main(void) {
    int tab[MAX];

    int n;
    printf("Vnesi dolizino tabele: ");
    scanf("%d", &n);

    for (int j = 0; j < n; ++j) {
        printf("Vnesi %d. element: ", j + 1);
        scanf("%d", &tab[j]);
    }

    // Shranimo, si, kje smo naslo prvi par, ki se ujema
    int ind_j = -1;
    int ind_i = -1;
    for (int j = 0; j < n; ++j) {
        // Dovolj je, da pregledujemo zgolj vse naslednje elemente
        for (int i = j + 1; i < n; ++i) {
            if (tab[i] == tab[j]) { // Ce najdemo ponovitev si to shranimo in koncamo s pregledovanjem
                ind_i = i;
                ind_j = j;
                break;
            }
        }
        if (ind_j != -1) { // Nasli in zapisali smo ponovitev
            break;
        }
    }
    if (ind_i != -1) {
        printf("V tabeli sta si %d. in %d. element enaka.\n", ind_j + 1, ind_i + 1);
    } else {
        printf("V tabeli so paroma razlicna stevila.\n");
    }

    return 0;
}