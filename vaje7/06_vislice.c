/*
Sestavi program, ki bo z nami igral igro vislice. Uporabnik naj vnese besedo, potem pa se dela, kot da te besede ne pozna. 
* Program naj najprej sestavi vzorec, sestavljen iz samih zvezdic, nato pa pocaka na vnos crke s tipkovnice. 
* ce ta crka nastopa v besedi, potem ustrezne zvezdice v vzorcu nadomesti s to crko, ce je ni, pa izpise primerno obvestilo. 
* To ponavlja toliko casa, dokler uporabnik ne odkrije vseh crk.

         Vnesi besedo: banana
         Ugani jo!

         ******
         Vnesi crko: a

         *a*a*a
         Vnesi crko: s
         Crke s ni v besedi.

         *a*a*a
         Vnesi crko: n

         *anana
         Vnesi crko: b

         banana
         Bravo!
      

*/
#include <stdio.h>
#include <string.h>

#define MAX 100

int main(void) {


    char beseda[MAX];
    char crka;
    char izpis[MAX];


    //beseda
    printf("Vnesi besedo: ");

    gets(beseda);

    printf("Ugani jo!\n");

    //stevilo crk
    int n;
    n = strlen(beseda);


    //stevec
    int i;


    //celemu izpisu zvezdico

    for (i = 0; i < n; i = i + 1) izpis[i] = '*';

    izpis[n] = '\0';
    printf("%s\n", izpis);


    while (1) {


        printf("\nVnesi crko: ");
        fflush(stdin);
        scanf(" %c", &crka);
        printf("crka je %c", crka);


        if (strchr(beseda, crka) == NULL) {
            printf("\nCrke %c ni v besedi.", crka);
            fflush(stdin);
        } else {
            for (i = 0; i < n; i = i + 1) {
                if (beseda[i] == crka) izpis[i] = crka;
            }

            printf("\n%s", izpis);
            if (strchr(izpis, '*') == NULL) break;

        }
    }
    printf("\nBravo!");


    return 0;
}



