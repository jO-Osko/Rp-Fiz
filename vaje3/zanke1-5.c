#include <stdio.h>

int main(void)
{
	printf("Vnesi a: ");
	int a;
	scanf("%d", &a);
	printf("Vnesi b: ");
	int b;
	scanf("%d", &b);
	printf("Najvecji skupni delitelj stevil %d in %d je ", a, b);
	if (b > a)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	while (b != 0)
	{
		int tmp = b;
		b = a % b;
		a = tmp;
	}
	printf("%d.", a);
	return 0;
}
