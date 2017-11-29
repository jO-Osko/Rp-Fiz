#include <stdio.h>


#define MAX 100

int main(void) {
    int vec_a[MAX];
    int vec_b[MAX];

    int n;
    printf("Dimenzije: ");
    scanf("%d", &n);

    for (int j = 0; j < n; ++j) {
        printf("a[%d] = ", j);
        scanf("%d", &vec_a[j]);
    }

    for (int j = 0; j < n; ++j) {
        printf("b[%d] = ", j);
        scanf("%d", &vec_b[j]);
    }

    printf("Vsota:");
    int skalarni = 0;

    // Vsote ne rabimo zapisovati v svojo tabelo, ampak jo lahko izpisujemo sproti

    for (int j = 0; j < n; ++j) {
        printf(" %d", vec_a[j] + vec_b[j]);
        // Hkrati pa se racunamo skalarni produkt
        skalarni = skalarni + vec_a[j] * vec_b[j];
    }

    printf("\n");
    printf("Skalarni produkt: %d\n", skalarni);

    return 0;
}