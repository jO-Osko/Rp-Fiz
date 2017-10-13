//
// Created by Filip Koprivec on 13/10/2017.
//

#include <stdio.h>

int main(void){
    printf("Vnesi prvi kot:\n");
    int s1, s2, m1, m2, sec1, sec2;
    printf("\tstopinje: ");
    scanf("%d", &s1);
    printf("\tminute: ");
    scanf("%d", &m1);
    printf("\tsekunde: ");
    scanf("%d", &sec1);
    printf("Vnesi drugi kot:\n");
    printf("\tstopinje: ");
    scanf("%d", &s2);
    printf("\tminute: ");
    scanf("%d", &m2);
    printf("\tsekunde: ");
    scanf("%d", &sec2);

    int vs, vm, vsec;
    vsec = sec1 + sec2;
    vm = m1 + m2 + vsec / 60;
    vs = s1 + s2 + vm / 60;
    printf("Vsota obeh kotov je %d stopinj, %d minut in %d sekund.\n", vs, vm % 60, vsec % 60);

    return 0;
}