#include <stdio.h>

int main(void) {
    int spodnja, zgornja;
    printf("Vnesi spodnjo mejo: ");
    scanf("%d", &spodnja);
    printf("Vnesi zgornjo mejo: ");
    scanf("%d", &zgornja);
    printf("Perfektna stevila:");
    for(int stevilo = spodnja; stevilo < zgornja; ++stevilo){
        int vsota = 0;
        for(int j = 1; j < stevilo; ++j){
            if(stevilo % j == 0){
                vsota += j;
            }
        }
        if(vsota == stevilo){
            printf(" %d", stevilo);
        }

    }
    printf("\n");
    return 0;
}

// Nekoliko bolj pametna verzija
int main2(void) {
    int spodnja, zgornja;
    printf("Vnesi spodnjo mejo: ");
    scanf("%d", &spodnja);
    printf("Vnesi zgornjo mejo: ");
    scanf("%d", &zgornja);
    printf("Perfektna stevila:");
    for(int stevilo = spodnja; stevilo < zgornja; ++stevilo){
        int vsota = 1; // Spustimo 1
        int j = 2; // Zato da nam ostane
        for(; j*j < stevilo; ++j){
            if(stevilo % j == 0){
                vsota += j;
                // Pogledamo se drugega delitelja
                vsota += stevilo/j;
            }
        }
        // Preverimo, ce je stevilo popolni kvadrat
        if(j*j == stevilo){
            vsota += j;
        }
        if(vsota == stevilo){
            printf(" %d", stevilo);
        }

    }
    printf("\n");
    return 0;
}