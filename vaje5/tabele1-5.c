#include <stdio.h>

// Za to nalogo v resnici ne potrebujemo tabele, saj se lahko po stevilih sprehajamo kar zaporedoma

// Ideja, ves cas hranimo trenutno najmanjsa in ju ob vsakem novem vnosu posodobimo (izpodrinemo napacnega)

#define MAX 100

int main(void) {

    int n;
    printf("Vnesi stevilo elementov (med 2 in %d): ", MAX);
    scanf("%d", &n);

    int najmanjsi;
    int drugi_najmanjsi;
    int i = 0;

    printf("%d. element: ", i + 1);
    scanf("%d", &najmanjsi);
    ++i;
    printf("%d. element: ", i + 1);
    scanf("%d", &drugi_najmanjsi);
    ++i;
    if (drugi_najmanjsi < najmanjsi) { // Ju zamenjamo
        int temp = drugi_najmanjsi;
        drugi_najmanjsi = najmanjsi;
        najmanjsi = temp;
    }

    for (; i < n; ++i) {
        int trenutni;
        printf("%d. element: ", i + 1);
        scanf("%d", &trenutni);
        if (trenutni < najmanjsi) { // Vseeno je ali uporabimo enakost ali neenakost (razmisli zakaj)
            drugi_najmanjsi = najmanjsi;
            najmanjsi = trenutni;
        } else if (trenutni < drugi_najmanjsi) { // Vseeno je ali uporabimo enakost ali neenakost
            drugi_najmanjsi = trenutni;
        }

    }
    printf("Drugi najmanjsi element je %d.\n", drugi_najmanjsi);

    return 0;
}