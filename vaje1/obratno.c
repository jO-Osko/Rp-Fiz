//
// Created by Filip Koprivec on 13/10/2017.
//

#include <stdio.h>

int main(void){
    int stevilo;
    printf("vnesi trimestno naravno stevilo: ");
    scanf("%d", &stevilo);
    printf("Obrat stevila %d", stevilo);
    int prva = stevilo % 10;
    stevilo = stevilo / 10;
    int druga = stevilo % 10;
    stevilo /= stevilo;
    int tretja = stevilo % 10; // == stevilo
    printf(" je stevilo %d%d%d.\n", prva, druga, tretja);
    return 0;
}