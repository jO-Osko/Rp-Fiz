//
// Created by Filip Koprivec on 13/10/2017.
//

#include <stdio.h>
#include <math.h>


int main(void){
    printf("Polog: ");
    double polog;
    scanf("%lf", &polog);
    printf("Stevilo mesecev: ");
    int meseci;
    scanf("%d", &meseci);
    printf("Mesecna obrestna mera: ");
    double interest_rate;
    scanf("%lf", &interest_rate);
    printf("\n");
    printf("Enostavno obrestovnanje: %.2lf\n", polog * (1 + meseci * interest_rate));
    printf("Obrestno obrestovnanje: %.2lf\n", polog * pow(1 + interest_rate, meseci));
    return 0;
}