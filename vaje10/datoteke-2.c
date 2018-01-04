#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int datoteke_2(char vhod[]) {
    FILE *vhodna = fopen(vhod, "rt");
    if (vhodna == NULL) {
        return -1;
    }
    char *vrstica = malloc(MAX * sizeof(*vrstica));
    int n = 0;
    while (1) {
        char *temp = fgets(vrstica, MAX, vhodna);
        if (temp == NULL) {
            break;
        }
        ++n;
    }
    // Ce bi hoteli nalogo resiti za poljubno dolge vrstice, bi morali n povecati sele ko bi v prebranem nizu nasli
    // znak za novo vrstico in zraven paziti na nekaj podrobnosti.
    fclose(vhodna);
    return n;
}


int main() {
    int stevilo_vrstic = datoteke_2("stevila/stevila.in");
    if (stevilo_vrstic == -1) {
        return -1;
    }
    printf("Stevilo vrstic: %d\n", stevilo_vrstic);
    return 0;
}
