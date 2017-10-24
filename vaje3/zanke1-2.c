#include <stdio.h>

int main(void)
{
    printf("Vnesi naravno stevilo: ");
    int stevilo;
    scanf("%d", &stevilo);
    int produkt = 1;
    do
    {
        produkt *= (stevilo % 10 > 0) ? stevilo % 10 : 1;
        stevilo /= 10;
    } while (stevilo > 0);
    printf("Produkt nenicelnih stevk je %d.\n", produkt);
    return 0;
}
