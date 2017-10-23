#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sahovnica() {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);  // predpostavljamo veljaven vhod

    if ((x1 + y1) % 2 == (x2 + y2) % 2) {
        printf("Sta enake barve.\n");
    } else {}

    if (x1 == x2 || y1 == y2) {
        printf("Trdnjava napada drugo polje.\n");
    } else {}

    if (abs(y1 - y2) == abs(x1 - x2)) {
        printf("Lovec napada drugo polje.\n");
    } else {}

    if (x1 == x2 || y1 == y2 || abs(y1 - y2) == abs(x1 - x2)) {
        printf("Kraljica napada drugo polje.\n");
    } else {}

    if ((abs(x1 - x2) == 2 && abs(y1 - y2) == 1) || (abs(x1 - x2) == 1 && abs(y1 - y2) == 2)) {
        printf("Konj napada drugo polje.\n");
    } else {}

    if (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1) {
        printf("Kralj napada drugo polje.\n");
    } else {}

}

void krog() {
    double x1, y1, r1, x2, y2, r2;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
    // Razmisli, ali se lahko izognemo dragemu (in mogoce nepotrebnemu) korenjenju ?
    double raz = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double r = r1 + r2;
    if (x1 == x2 && y1 == y2) {
        if (r1 == r2) {
            printf("Kroznici imata vec kot eno skupno tocko (imata jih kontinuum)");
        } else {
            // Kroznici sta ena znotraj druge
            printf("Kroznici sta loceni");
        }
    } else if (r < raz) {
        printf("Kroznici sta loceni.\n");
    } else if (r == raz) {
        printf("Kroznici se dotikata.\n");
    } else {
        // D.N. en primer v razmisleku manjka, razmisli in popravi sam.
        printf("Kroznici imata vec kot eno skupno tocko.\n");
    }
}

void trikotnik() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if (b + c < a && a + c < b && a + b < c) {
        double s = (a + b + c) / 2;
        printf("Obseg: %lf\n", 2 * s);
        //
        printf("Ploscina: %lf\n", sqrt(s * (s - a) * (s - b) * (s - c)));
    } else {
        printf("Takega trikotnika ni, ali pa je degeneriran\n");
    }
}

void funkcija() {
    // fabs nam vrne absolutno vrednost stevil s plavajoco vejico
    // fmin nam vrne deluje enako kot min, le da sprejema stevila s plavajoco vejico
    double x;
    scanf("%lf", &x);
    // Najprej argument premaknemo na ustrezen interval, pri tem pazimo na obnasanje negativnih stevil
    // https://stackoverflow.com/questions/11720656/modulo-operation-with-negative-numbers
    // Pozor, to se lahko razlikuje glede na ostale programske jezike
    x = fmod(fmod(x, 10.0) + 10.0, 10.0);

    printf("f(%f) = ", x);
    if (x < 2) {
        printf("%lf", x + sin(x));
    } else if (x <= 4) {
        printf("%lf", fabs(x - 3));
    } else if (x < 7) {
        printf("%lf", (x - 5) * (x - 5));
    } else {
        printf("%lf", 12 - 5 * x);
    }
}

void pravokotniki() {
    double x11, x12, x21, x22, y11, y12, y21, y22;
    printf("Vnesi koordinate 1. pravokotnika: ");
    scanf("%lf %lf %lf %lf", &x11, &y11, &x12, &y12);
    printf("Vnesi koordinate 2. pravokotnika: ");
    scanf("%lf %lf %lf %lf", &x21, &y21, &x22, &y22);

    // uredimo koordinate, ce so bile morda vnesene v npacnem vrstnem redu
    double x1l = fmin(x11, x12), x1r = fmax(x11, x12); // Zelimo tako:
    double y1u = fmax(y11, y12), y1d = fmin(y11, y12); // *           (xl, yu)
    double x2l = fmin(x21, x22), x2r = fmax(x21, x22); //
    double y2u = fmax(y21, y22), y2d = fmin(y21, y22); //           * (xr, yd)

    // izracunamo stranice, obsega in ploscini originalnih pravkotnikov
    double a1 = x1r - x1l, a2 = x2r - x2l;
    double b1 = y1u - y1d, b2 = y2u - y2d;
    double p1 = a1 * b1, p2 = a2 * b2;
    double o1 = 2 * a1 + 2 * b1, o2 = 2 * a2 + 2 * b2;

    // dx in dy sta stranici pravokotnika v preseku, ce preseka ni, sta 0
    double dx = fmax(0, fmin(x1r, x2r) - fmax(x1l, x2l));
    double dy = fmax(0, fmin(y1u, y2u) - fmax(y1d, y2d));

    // izracunamo ploscino in obseg unije (odstejemo obseg in ploscino preseka)
    double obseg = o1 + o2 - 2 * dx - 2 * dy;
    double ploscina = p1 + p2 - dx * dy;

    printf("Obseg unije: %f\n", obseg);
    printf("Ploscina unije: %f\n", ploscina);
}

void ahil_in_zelva() {
    int dolzina = 100;
    int prednost = 90;
    int presotanek = dolzina - prednost;
    double v1, v2;
    printf("Vnesi hitrost Ahila in zelve: ");
    scanf("%lf %lf", &v1, &v2);
    double t1 = dolzina / v1;
    double t2 = presotanek / v2;
    if (t1 > t2) {
        printf("Zmagovalec je zelva.\n");
    } else if (t1 < t2) {
        printf("Zmagovalec je Ahil.\n");
    } else {
        printf("Tekmovalca sta na cilj prisla hkrati, sodniki so se odlocili tekmo ponoviti.\n");
    }
}

void startup() {
    int v1 = 80;
    int v2 = 20;
    int v3 = 25;

    int kos, roz, or;
    printf("Vnesi zalogo ovsenih kosmicev v gramih: ");
    scanf("%d", &kos);
    printf("Vnesi zalogo rozin v gramih: ");
    scanf("%d", &roz);
    printf("Vnesi zalogo oresckov v gramih: ");
    scanf("%d", &or);

    int stk = kos / v1;
    int str = roz / v2;
    int sto = or / v3;

    // Ker se ne znamo uporabljati funkcije min...
    int mi = stk;
    if (str < mi) {
        mi = str;
    }
    if (sto < mi) {
        mi = sto;
    }
    // Razmisli, zakaj zgoraj nismo uporabili else if?

    printf("S sestavinami lahko (brez upostevanja slovnice) napolnimo %d vreck.\n", mi);

    // Potem skoraj gotovo ne poznamo funkcije max :(
    int ma = stk;
    int polna = (kos % v1) == 0; // Ali napolnimo celo vrecko
    if (str > ma) {
        ma = str;
        polna = (roz % v2) == 0;
    }
    if (sto > ma) {
        ma = sto;
        polna = (or % v3) == 0;
    }
    if (!polna) {
        ma += 1;
    }

    printf("Ce dodamo:\n");
    printf("\t%d g ovsenih kosmicev,\n", ma * v1 - kos);
    printf("\t%d g rozin in\n", ma * v2 - roz);
    printf("\t%d g oresckov\n", ma * v3 - or);
    printf("Lahko napolnimo %d vreck.\n", ma);

}

int main(void) {
    sahovnica();
    krog();
    trikotnik();
    funkcija();
    pravokotniki();
    ahil_in_zelva();
    startup();
    return 0;
}