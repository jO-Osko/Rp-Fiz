#include <stdio.h>


// Metoda, ki jo bomo uporabili deluje zgolj na določenih sistemih kovancev
// (Sistem, ki ga uporablja večina valut po svetu je primeren za tako vračanje)

// Natančneje, kovance vračamo po POŽREŠNI metodi, saj v vsakem koraku vrnemo kovanec (bankovec) z največjo denominacijo
// in (upamo), da bomo na ta način vrnili najmanjše število kovancev.
//
// Formalno, sistem kovancev je matroid, in iščemo najcenejšo bazo v tem matroidu, super predmet, kjer lahko izveste
// več o tem je izbirni predmet podatkovne strukture in algoritmi 2 (PSA2).

#define SIZEOF(tab) (sizeof(tab) / sizeof(tab[0]))

int main(void){

    int moznosti[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};

    int znesek;
    printf("Vnesi znesek: ");
    scanf("%d", &znesek);

    int moznost = 0;

    while(znesek){
        int st = znesek / moznosti[moznost];
        if(st){
            printf("%d x %d\n", st, moznosti[moznost]);
            znesek = znesek % moznosti[moznost];
        }
        ++moznost; // Poskusimo z naslednjim kovancem
    }

    return 0;
}