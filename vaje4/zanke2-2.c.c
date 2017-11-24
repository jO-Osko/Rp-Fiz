#include <stdio.h>

int main(void) {
    printf("Vnesi visino piramide: ");
    int visina;
    scanf("%d", &visina);
    for (int j = 0; j < visina; ++j) { // Izpisemo po vrsticah
        // Najprej izpisemo presledke
        for (int i = 0; i < visina - j - 1; ++i) {
            printf(" ");
        }
        // Nato zvezdice
        for (int i = 0; i < j * 2 + 1; ++i) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

