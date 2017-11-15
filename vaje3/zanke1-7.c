#include <stdio.h>

int main(void)
{
	int buff;
	printf("Vnesi celo stevilo: ");
	scanf("%d", &buff);
	int max = buff;
	int min = buff;
	double avg = buff;
	int counter = 1;
	while(buff != 0)
	{
		printf("min = %d, max = %d, povp = %lf\n", min, max, avg);
		printf("Vnesi celo stevilo: ");
		scanf("%d", &buff); 
		min = (buff < min) ? buff : min;
		max = (buff > max) ? buff : max;
		avg *= counter;
		avg += buff;
		counter ++;
		avg /= counter;
	}
	return 0;
}
