#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
#define LEN 5

int main(void) {
    int stevila[LEN];
    int pojavitve[MAX];
    srand((unsigned) time(NULL));
    printf("Tabela:");

    for (int j = 0; j < MAX; ++j) {
        pojavitve[j] = 0;
    }
    for (int j = 0; j < LEN; ++j) {
        int trenutno = rand() % MAX;
        printf(" %d", trenutno);
        stevila[j] = trenutno;
        // Povecamo kolikokrat se pojavi
        pojavitve[trenutno]++;
    }
    printf("\n");
    for (int j = 0; j < MAX; ++j) {
        if (pojavitve[j]) {
            printf("Stevilo %d se pojavi %d-krat.\n", j, pojavitve[j]);
        }
    }
    return 0;
}