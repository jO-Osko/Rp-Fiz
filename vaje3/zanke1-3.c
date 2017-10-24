#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    printf("Vnesi naravno stevilo: ");
    int stevilo;
    scanf("%d", &stevilo);
    
    bool prastevilo = true;
    
    for (int i = 2; i * i < stevilo; i++)
    {
        if (stevilo % i == 0)
        {
            prastevilo = false;
            break;
        }
    }
    
    if (prastevilo)
    {
        printf("%d je prastevilo.\n", stevilo);
    }
    else
    {
        printf("%d ni prastevilo.\n", stevilo);
    }
    
    return 0;
}
    
    
