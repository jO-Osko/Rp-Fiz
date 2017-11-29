#include <stdio.h>


#define MAX 100

int main(void) {
    int tab[MAX];

    int n;
    printf("Vnesi stopnjo polinoma: ");
    scanf("%d", &n);
    ++n; // Polinom stopnje n ima n+1 koeficientov

    for (int j = 0; j < n; ++j) {
        printf("a[%d] = ", j);
        scanf("%d", &tab[j]);
    }

    int x;
    printf("Vnesi tocko: ");
    scanf("%d", &x);

    // Uporabimo hornerjev algoritem


    int cur = 1;
    int rezultat = 0;
    for (int j = 0; j < n; ++j) {
        rezultat += cur * tab[j];
        cur *= x;
    }

    printf("Vrednost polinoma v tocki %d je %d.\n", x, rezultat);
    return 0;
}