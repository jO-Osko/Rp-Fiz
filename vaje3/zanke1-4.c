#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("Vnesi x: ");
    double x;
    scanf("%lf", &x);
    
    printf("Vnesi n: ");
    int n;
    scanf("%d", &n);
    
    double rezultat = 0;
    
    for (int i = 0; i < n; i++)
    {
        double stevec = pow(x, i);
        double imenovalec = 1;
        for (int j = 1; j <= i; ++j)
        {
            imenovalec *= j;
        }
        rezultat += (stevec / imenovalec);
    }
    
    printf("Vsota: %lf\n", rezultat);
    return 0;
}
