#include <stdio.h>

#define MAX_SIZE 100

int main(void) {
    int stevila[MAX_SIZE];
    int n;
    printf("Vnesi stevilo elementov (med 0 in %d): ", MAX_SIZE);
    scanf("%d", &n);
    // Preberemo element
    for (int j = 0; j < n; ++j) {
        printf("%d. element: ", j+1);
        // Seveda bi lahko uporabili zacasno spremenljivko
        // int stevilo
        // scanf("%d", &stevilo);
        // stevila[j] = stevilo;
        scanf("%d", &stevila[j]);
    }
    printf("Od leve proti desni:");
    // Gremo po vrsti
    for (int j = 0; j < n; ++j) {
        printf(" %d", stevila[j]);
    }
    printf("\n");
    printf("Od desne proti levi:");
    for (int j = n - 1; j > -1; --j) {
        printf(" %d", stevila[j]);
    }
    printf("\n");
    return 0;
}