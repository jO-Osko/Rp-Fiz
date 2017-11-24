#include <stdio.h>

// Premisli: Kaj bi bilo treba spremeniti, da bi se piramide na dnu dotikale ?

int main(void) {
    int n;
    printf("Vnesi visino prve piramide: ");
    scanf("%d", &n);
    for (int j = 0; j < n; ++j) {  // Izpisemo po vrsticah
        // Izpisujemo vsako piramido posebej
        for (int i = 0; i <= j; ++i) {
            // Stevilo preslaedkov je konstantno
            for (int k = 0; k < n - j - 1; ++k) {
                printf(" ");
            }
            // Spreminjamo zgolj zvezdice
            for (int k = 0; k < 2 * (j - i) + 1; ++k) {
                printf("*");
            }
            for (int k = 0; k < n - j; ++k) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
