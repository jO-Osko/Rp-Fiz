#include <stdio.h>

// Tudi ta naloga ne zahteva tabele, saj lahko vhodne podatke pregledujemo po vrsti.
// Ideja: Prvic, ko pride do padca, ponovno nastavimo dolzino in posodobimo zaporedje


int main(void) {

    int n;
    printf("Vnesi dolzino tabele: ");
    scanf("%d", &n);

    int max_dolzina = 0;
    int trenutna_dolzina = 1;
    int stevilo_cet = 1;
    int zadnji;
    int i = 0;
    printf("Vnesi %d. element: ", i+1);
    scanf("%d", &zadnji);
    ++i;
    for (; i < n; ++i) {
        int trenutni;
        printf("Vnesi %d. element: ", i+1);
        scanf("%d", &trenutni);
        if (trenutni < zadnji) {
            ++stevilo_cet;
            if (trenutna_dolzina > max_dolzina) {
                max_dolzina = trenutna_dolzina;
            }
            trenutna_dolzina = 1; // Ponastavimo dolzino,
        }else{ // Trenutna dolzina se poveca (lahko pa zgoraj nastavimo na 0 in damo to na konec zanke)
            ++trenutna_dolzina;
        }
        zadnji = trenutni;
    }

    if(trenutna_dolzina > max_dolzina){ // Kaj ce je trenutna najdaljsa
        max_dolzina = trenutna_dolzina;
    }

    printf("V tabeli so %d cete.\n", stevilo_cet);
    printf("Najdaljsa ima dolzino %d.\n", max_dolzina);



    return 0;
}