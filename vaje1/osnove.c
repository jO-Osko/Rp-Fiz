//
// Created by Filip Koprivec on 10/10/2017.
//

#include <stdio.h>
// Da lahko uporabimo funkcijo pow, kasneje jo bomo znali napisati sami,
// se malo kasneje pa jo boste znali tudi optimizirati
#include <math.h>

void racke() {
    printf("       __         __\n");
    printf("      ( ')>     >(' )\n");
    printf("       \\(         )/\n");
    printf("        )\\       /(\n");
    printf("  \\----'  \\     /  `----/\n");
    printf("    \\ --~  )   (  ~-- /\n");
    printf("~^~^~^~^~^~^~^~^~^~^~^~^~^~^\n");
}

void sestevanje() {
    printf("Vnesi 1. celo stevilo: ");
    int a;
    scanf("%d", &a);
    printf("Vnesi 2. celo stevilo: ");
    int b;
    scanf("%d", &b);
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d\n", a, b, a / b);
    printf("%d %% %d = %d\n", a, b, a % b);
}

void obratno() {
    int stevilo;
    printf("vnesi trimestno naravno stevilo: ");
    scanf("%d", &stevilo);
    printf("Obrat stevila %d", stevilo);
    int prva = stevilo % 10;
    stevilo = stevilo / 10;
    int druga = stevilo % 10;
    stevilo /= stevilo;
    int tretja = stevilo % 10; // == stevilo
    printf(" je stevilo %d%d%d.\n", prva, druga, tretja);

}

void koti() {
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
}

void radiani() {
    printf("Vnesi kot v radianih: ");
    double rad;
    scanf("%lf", &rad);
    double stop = rad / 3.14159 * 180;
    printf("%.3lf radianov je %d stopinj, %d minut.\n", rad, (int) stop, (int) ((stop - (int) stop) * 60));
}

void obrestovanje() {
    printf("Polog: ");
    double polog;
    scanf("%lf", &polog);
    printf("Stevilo mesecev: ");
    int meseci;
    scanf("%d", &meseci);
    printf("Mesecna obrestna mera: ");
    double interest_rate;
    scanf("%lf", &interest_rate);
    printf("\n");
    printf("Enostavno obrestovnanje: %.2lf\n", polog * (1 + meseci * interest_rate));
    printf("Obrestno obrestovnanje: %.2lf\n", polog * pow(1 + interest_rate, meseci));
}

void kazalci() {
    printf("Vnesi uro: ");
    int ura;
    scanf("%d", &ura);
    ura = ura % 12;
    printf("Vnesi minute: ");
    int minute;
    scanf("%d", &minute);
    double minutni = 360.0 * minute / 60.0;
    double urni = 360.0 * ura / 12.0 + minute*0.5;
    // Find the difference between two angles
    double razlika = urni - minutni;
    if (razlika < 0) {
        razlika = -razlika;
    }
    if (razlika > 180) {
        razlika = 360 - razlika;
    }
    printf("Manjsi kot med kazalcema je %d stopinj in %d minut.\n", (int) razlika, (int) ((razlika - (int) razlika) * 60));
}

int main(void) {
    racke();
    sestevanje();
    obratno();
    koti();
    radiani();
    obrestovanje();
    kazalci();
    // Davcno stevilko naredite sami za vajo :)
    return 0;
}