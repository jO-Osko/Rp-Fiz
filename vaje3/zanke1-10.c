#include <stdio.h>

int main(void)
{
	printf("Vnesi stevilo clenov zaporedja: ");
	int x;
	scanf("%d", &x);
	int a = 0;
	int b = 1;
	printf("Cleni zaporedja so:");
	for (int i = 1; i <= x; i++)
	{
		printf(" %d", a+b);
		if (i % 2)
		{
			b += a;
		}
		else
		{
			a += b;
		}
	}
	return 0;
}
		
