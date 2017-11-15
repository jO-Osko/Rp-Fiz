#include <stdio.h>

int main(void)
{
	printf("Vnesi n: ");
	int n;
	scanf("%d", &n);
	printf("Vnesi k: ");
	int k;
	scanf("%d", &k);
	double binom = 1;
	for (int i = 1; i <= k; i++)
	{
		binom *= (n - (i - 1)) * 1.0 / i; // * 1.0 je zaradi celostevilskih operacij
	}
	printf("%d nad %d je %.0lf\n", n, k, binom);
	return 0;
}
