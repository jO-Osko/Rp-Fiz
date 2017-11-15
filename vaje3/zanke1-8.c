#include <stdio.h>

int main(void)
{
	const double eps = 0.0001;
	printf("Vnesi x: ");
	double x;
	scanf("%lf", &x);
	double sum = 1;
	double previousSum = 0;
	int counter = 1;
	int fakulteta = 1;
	double potenca = 1;
	while (sum - previousSum > eps)
	{
		previousSum = sum;
		fakulteta *= counter;
		counter ++;
		potenca *= x;
		sum += 1.0 * potenca / fakulteta;
	}
	printf("e^%lf = %lf\n", x, previousSum);
	return 0;
}
