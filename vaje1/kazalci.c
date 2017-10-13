//
// Created by Filip Koprivec on 13/10/2017.
//

#include <stdio.h>

int main(void) {
    printf("Vnesi uro: ");
    int ura;
    scanf("%d", &ura);
    ura = ura % 12;
    printf("Vnesi minute: ");
    int minute;
    scanf("%d", &minute);
    double minutni = 360.0 * minute / 60.0;
    double urni = 360.0 * ura / 12.0 + minute * 0.5;
    // Find the difference between two angles
    double razlika = urni - minutni;
    if (razlika < 0) {
        razlika = -razlika;
    }
    if (razlika > 180) {
        razlika = 360 - razlika;
    }
    printf("Manjsi kot med kazalcema je %d stopinj in %d minut.\n", (int) razlika,
           (int) ((razlika - (int) razlika) * 60));
    return 0;
}
