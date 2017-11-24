#include <stdio.h>

int main(void) {
    printf("Vnesi naravno stevilo: ");
    int n;
    scanf("%d", &n);
    //n = 7654672;
    while(n >= 10) {
        printf("%d\n", n);
        int vsota = 0;
        while (n) {
            int zadnja = n % 10;
            vsota += zadnja*zadnja;
            n = n / 10;
        }
        n = vsota;
    }
    printf("%d\n", n);
    return 0;
}