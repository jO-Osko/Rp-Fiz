#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/*ta funkcija bo izracanala multifakulteto,
ter izpisala vmesne clene pri racunanju. */
int multifakulteta(int a, int b) {
    //ker je multifakulteta zmnozek jo inicializiramo z nevtralnim elementom za mnozenje
    int f = 1;
    //tabela za belezenje vmesnih clenov
    int tab[MAX];

    int n = 0;
    while (a > 0) {
        f *= a;
        tab[n] = a;
        n++;
        //vrednost spremenimo na koncu, tako se bo takoj preveril pogoj
        a -= b;
    }

    //osnovni izpis
    printf("F(%d, %d) = %d ", tab[0], b, f);

    //if ne potrebuje zajemati spodnje zanke,
    if (f != tab[0]) {
        printf("= %d", tab[0]);
    }
    for (int i = 1; i < n; i++) {
        printf(" * %d", tab[i]);
    }

    return f;
}


//v glavni funkciji preverimo delovanje funkcije
int main(void) {
    int n, k;
    printf("Vnesi n: ");
    scanf("%d", &n);
    printf("Vnesi k: ");
    scanf("%d", &k);

    //f ne bomo naprintala na kar nas bo prevajalnik opozoril
    int f = multifakulteta(n, k);

    return 0;
}