//
// Created by Filip Koprivec on 13/10/2017.
//

#include <stdio.h>

int main(void){
    printf("Vnesi kot v radianih: ");
    double rad;
    scanf("%lf", &rad);
    double stop = rad / 3.14159 * 180;
    printf("%.3lf radianov je %d stopinj, %d minut.\n", rad, (int) stop, (int) ((stop - (int) stop) * 60));
    return 0;
}