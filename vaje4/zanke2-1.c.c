#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    srand((unsigned) time(NULL));
    int najvecje = 100;

    printf("Izmislil sem si stevilo med 1 in %d. Ugani ga!\n", najvecje);
    int stevilo = rand() % najvecje + 1;

    int poskus = 1;
    while (1) {
        int uganjeno;
        printf("%d. poskus: ", poskus);
        scanf("%d", &uganjeno);
        if (uganjeno < stevilo) {
            printf("Narobe. Stevilo %d je premajhno.\n", uganjeno);
        } else if (uganjeno > stevilo) {
            printf("Narobe, Stevilo %d je preveliko.\n", uganjeno);
        } else {
            break;
        }
        ++poskus;
    }
    printf("Cestitam. Stevilo %d si uganil v %d. poskusu.\n", stevilo, poskus);

    return 0;
}