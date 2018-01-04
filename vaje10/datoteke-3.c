#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int datoteke_3(char vhod[], int *min_d, int *min_m, int *min_y) {
    FILE *vhodna = fopen(vhod, "rt");
    if (vhodna == NULL) {
        return 1;
    }
    double min;
    int min_day;
    int min_month;
    int min_year;
    int n = fscanf(vhodna, "%d.%d.%d %lf", &min_day, &min_month, &min_year, &min);
    if (n == EOF) {
        return 2;
    }
    double current;
    int day_c, month_c, year_c;
    while ((n = fscanf(vhodna, "%d.%d.%d %lf", &day_c, &month_c, &year_c, &current)) != EOF) {
        if (current < min) {
            min_day = day_c;
            min_month = month_c;
            min_year = year_c;
            min = current;
        }
    }
    fclose(vhodna);
    *min_d = min_day;
    *min_m = min_month;
    *min_y = min_year;

    return 0;
}


int main() {
    int min_day, min_month, min_year;
    int rezultat = datoteke_3("stevila/meritve.in", &min_day, &min_month, &min_year);
    if (rezultat != 0) {
        return rezultat;
    }
    printf("Datum najmanjse meritve: %d.%d.%d\n", min_day, min_month, min_year);
    return 0;
}
