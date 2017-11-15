#include <stdio.h>

int main(void)
{
	printf("Vnesi a: ");
	int a;
	scanf("%d", &a);
	printf("Vnesi b: ");
	int b;
	scanf("%d", &b);
	int originalA = a;
	int originalB = b;
	if (b > a)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	do
	{
		printf("%d = %d * %d + %d\n", a, a/b, b, a%b);
		int tmp = b;
		b = a % b;
		a = tmp;
	} while (b > 0);
	printf("Najvecji skupni delitelj stevil %d in %d je ", originalA, originalB);
	printf("%d.", a);
	return 0;
}
