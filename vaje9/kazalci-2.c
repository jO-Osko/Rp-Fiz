#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char *podvoji(char old[]) {
    int dolzina = strlen(old);

    char *novi = malloc((dolzina * 2 + 1) * sizeof(*novi));
    for (int j = 0; j < dolzina; ++j) {
        novi[2 * j] = old[j];
        novi[2 * j + 1] = old[j];
    }
    novi[dolzina * 2] = '\0';

    return novi;

}


int main(void) {
    char niz[MAX_SIZE];
    printf("vnesi niz: ");
    scanf("%s", niz);
    char *podvojeni = podvoji(niz);

    printf("Nov niz: %s\n", podvojeni);
    free(podvojeni);
    podvojeni = NULL;

    return 0;
}