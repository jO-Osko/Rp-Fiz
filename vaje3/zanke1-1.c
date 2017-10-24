#include <stdio.h>

int main(void)
{
    printf("Vnesi zgornjo mejo: ");
    int zgMeja;
    scanf("%d", &zgMeja);
    printf("Kubi do %d so:", zgMeja);
    int kub = 1;
    while (kub * kub * kub <= zgMeja)
    {
        printf(" %d", kub * kub * kub);
        kub ++;
    }
    return 0;
}
