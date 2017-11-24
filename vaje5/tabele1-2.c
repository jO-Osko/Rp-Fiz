#include <stdio.h>

#define MAX_SIZE 100

int main(void) {
    int stevila[MAX_SIZE];
    int n;
    printf("Vnesi stevilo elementov (med 0 in %d): ", MAX_SIZE);
    scanf("%d", &n);
    // Preberemo element
    for (int j = 0; j < n; ++j) {
        printf("%d. element: ", j + 1);
        // Seveda bi lahko uporabili zacasno spremenljivko
        // int stevilo
        // scanf("%d", &stevilo);
        // stevila[j] = stevilo;
        scanf("%d", &stevila[j]);
    }
    while (1) {
        printf("Vnesi iskani element: ");
        int iskano;
        int mesto_iskanega = -1;
        scanf("%d", &iskano);
        if(iskano == 0){
            break;
        }
        for (int j = 0; j < n; ++j) {
            if (stevila[j] == iskano) {
                mesto_iskanega = j;
                break;
            }
        }
        // Nikoli nismo nastavili mesta => elementa ni v seznamu
        if (mesto_iskanega == -1) {
            printf("Elementa %d ni v tabeli.\n", iskano);
        } else {
            printf("Element %d se prvic pojavi na %d. mestu (mesto z indeksom %d).\n",
                   iskano, mesto_iskanega + 1, mesto_iskanega);
        }
    }
    return 0;
}