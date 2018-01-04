#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10

int kaznuj(char vhod[], char izhod[]) {
    FILE *in_file = fopen(vhod, "rt");
    if (in_file == NULL) {
        return -1;
    }
    FILE *out_file = fopen(izhod, "wt");
    if (out_file == NULL) {
        fclose(in_file);
        return -2;
    }

    double omejitev = 80 * 1000 / (60 * 60);
    int dolzina = 622;
    int minimalni_cas = dolzina / omejitev;

    int n = 0;
    int in, out;
    char tablica[MAXSIZE];
    int prebrano;
    int krsitelji = 0;
    while ((n = fscanf(in_file, "%d %d %s", &in, &out, tablica)) != EOF) {
        if ((out - in) < minimalni_cas) {
            ++krsitelji;
            fprintf(out_file, "%.2lf %s", 3.6 * dolzina / (out - in), tablica);
        }
    }

    fclose(in_file);
    fclose(out_file);
    return krsitelji;
}

int main() {
    int rezultat = kaznuj("stevila/golovec.in", "stevila/golovec.txt");
    printf("%d\n", rezultat);
    return rezultat < 0;

}