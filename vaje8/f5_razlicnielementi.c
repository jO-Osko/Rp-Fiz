#include <stdio.h>
#include <stdlib.h>


//funkcija zbere vse unikatne elemente na zacetku in vrne stevilo unikatnih elementov
int razlicnielementi(int n, int tab[n]) {
    //upravljali bomo z dvema stevnikoma
    int m = 0;
    for (int i = 0; i < n; i++) {
        //stikalo bo enako 1 ce je tab[i] razlicen od do sedaj zaznanih unikatnih elementov
        int stikalo = 1;

        //stevnik j sledi unikatnim elementom
        for (int j = 0; j < m; j++) {
            //ce je tab[i] enak enemu od ze zaznanih razlicnih elementov preklopimo stikalo
            if (tab[i] == tab[j]) {
                stikalo = 0;
            }
        }

        //ce je tab[i] na unikaten ga dodamo na zacetku k razlicnim elementom
        if (stikalo == 1) {
            tab[m] = tab[i];
            m++;
        }

    }

    return m;
}


//preverimo delovanje funkcije
int main(void) {
    int n;
    printf("Vnesi dolzino tabele: ");
    scanf("%d", &n);

    int tab[n];
    for (int i = 0; i < n; i++) {
        printf("Vnesi %d. element: ", i + 1);
        scanf("%d", &tab[i]);
    }

    int m = razlicnielementi(n, tab);
    printf("Stevilo razlicnih elementov: %d\n", m);

    /* naprintati rabimo samo prvih m elementov,
    saj smo vse razlicne elemente zbrali na zacetku */
    printf("Razlicni elementi: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", tab[i]);
    }

    return 0;
}