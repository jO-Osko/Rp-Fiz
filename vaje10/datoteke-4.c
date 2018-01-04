#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int preuredi(char vhod[], char izhod[]) {
    FILE *vhodna = fopen(vhod, "rt");
    if (vhodna == NULL) {
        return 1;
    }
    FILE *izhodna = fopen(izhod, "wt");
    if (izhodna == NULL) {
        fclose(vhodna);
        return 2;
    }

    int odprto_i = 0;
    int odprto_b = 0;

    char znak;
    while ((znak = fgetc(vhodna)) != EOF) {
        if (znak == '*') {
            if (odprto_b) {
                fputs("</b>", izhodna);
                odprto_b = 0;
            } else {
                fputs("<b>", izhodna);
                odprto_b = 1;
            }
        } else if (znak == '/') {
            if (odprto_i) {
                fputs("</i>", izhodna);
                odprto_i = 0;
            } else {
                fputs("<i>", izhodna);
                odprto_i = 1;
            }
        } else{
            fputc(znak, izhodna);
        }
    }
    fclose(vhodna);
    fclose(izhodna);
    return 0;
}

int main() {
    return preuredi("stevila/besedilo.md", "stevila/besedilo.html");
}