//
// Created by Filip Koprivec on 13/10/2017.
//

#include "stdio.h"

int main(void) {
    printf("Vnesi 1. celo stevilo: ");
    int a;
    scanf("%d", &a);
    printf("Vnesi 2. celo stevilo: ");
    int b;
    scanf("%d", &b);
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d\n", a, b, a / b);
    printf("%d %% %d = %d\n", a, b, a % b);
    return 0;
}