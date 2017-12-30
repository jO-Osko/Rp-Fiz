# Uporaba knjižnic v programskem jeziku C

V programiranju nekatere funkcije uporabljamo večkrat (ne samo v eni sami datoteki, lahko tudi v nekem projektu, ali 
pa v več različnih programih, ki so med seboj povsem neodvisni). Nekaj takih funkcij smo že večkrat srečali v preteklih 
nekaj mesecih: `pow` iz knjižnice `math.h`, praktično v vsakem programu pa smo zagotovo uporabili `scanf` in `printf`.

Funkcijo, ki jo definiramo (implementiramo) v določeni datoteki, lahko brez težav uporabljamo v isti datoteki 
(če seveda uporaba sledi deklaraciji), želimo pa si, da bi lahko skupino funkcij, ki se nam zdijo uporabne uporabili 
tudi izven datoteke, kjer smo jih definirali.

Programski C vključevanje kode iz drugih datotek omogoča s pomočjo preprocesorske direktive 
`#include <ime-knjiznice>` ali `#include "ime-datoteke.h"`. S tem prevajalniku povemo, da bom uporabljali funkcije 
deklarirane v podani datoteki (`#include <math.h>` tako pove, da bomo uporabili funkcije iz knjiznice(iz datoteke) po 
imenu math.h).

## Zaglavne ali ``.h`` datoteke (deklaracija)


Zaradi večje modularnosti (želimo si, da so knjižnice in koda čim manj sklopljene), funkcije, ki jih bomo v knjižnici 
definirali najprej _deklariramo_ v `.h` datoteki (končnica `h`pove da gre za "header" datoteko), kjer samo povemo, kako 
bodo funkcije izgledale (v header datoteko napišemo zgolj signature (tipe) funkcij, da prevajalnik ve, kako lahko 
funkcije pravilno uporabi). Primer `.h` datoteke iz vaj, ki pove, da bo knjižnica vsebovala dve funkciji (in njune tipe) vidimo 
spodaj.


```c
#ifndef C_PREBERI_SEZNAM_H
#define C_PREBERI_SEZNAM_H

int *vnosTabele(char vnosDolzine[], char vnosElementa[], int *n);

void izpisTabele(char opis[], int *tabela, int dolzina);

#endif //C_PREBERI_SEZNAM_H

```

Zaglavna datoteka se tipično prične s preprocesorsko direktivo `#ifndef C_IME_KNJIZNICE_H`, ki predstavlja pogojni 
stavek, katerega vsebina se izvede, če konstanta `C_IME_KNJIZNICE_H` **ni** definirana. Pogojni stavek končamo na dnu 
datoteke, kjer `#endif` navadno v komentarju pripišemo, kateri pogojni stavek zaključuje. Kot prvo stvar v pogojnem 
stavku pa sedaj definiramo konstanto `C_IME_KNJIZNICE_H`. S tem zagotovimo, da se bo naša knjižnica vključila največ 
enkrat in ne bo prišlo do težav. Pogoj da tak mehanizem sploh lahko deluje je seveda da ime ``C_IME_KNJIZNICE_H`` ni 
uporabljeno kje drugje. Tipično zato da zagotovino edinost take konstante uporabimo ime knjižnice, ki ji dodamo 
dogovorjene predpone ali pripone.

Nato sledijo deklaracije funkcij, ki bodo v naši knjižnici javne (implementiramo lahko tudi različne druge funkcije, 
ki pa ne bodo nujno vidne prevajalniku). Pomembno je, da v `.h` datoteki samo povemo kakšne funkcije bodo v naši 
knjižnici, njihovo implementacijo pa zapišemo drugje.

## Implementacijske ali `.c` datoteke (implementacija)

V `.c` datoteki funkcije (ki je tipično poimenovana enako kot zaglavna datoteka, drugačna je le končnica), ki smo jih v `.h` datoteki deklarirali implementiramo (napišemo dejansko kodo). Tu nam ni več treba paziti na 
večkratno vklučevanje, saj se v program vključijo zgolj deklaracijske datoteke. Tipično v ``c`` datoteko vključimo tudi 
``.h``datoteko, in s tem preverimo, da se deklaracija in implementacija ujemata. Spodaj vidimo primer iz vaj.

```c
#include <stdio.h>
#include <stdlib.h>

// Za dodatno preverjanje vključimo header file, da se tipi zagotovo ujemajo
#include "tabele.h"

// Uporaba:
// int* tabela = vnosTabele("Vnesi stevilo elementov: ", "Vnesi %d. element tabele: ", &n);

int *vnosTabele(char vnosDolzine[], char vnosElementa[], int *n) {
    printf(vnosDolzine);
    scanf("%d", n);

    int *seznam = malloc(*n * sizeof(*seznam));

    for (int j = 0; j < *n; ++j) {
        printf(vnosElementa, j + 1);
        scanf("%d", &seznam[j]);
    }

    return seznam;
}

// Uporaba:
// izpisTabele("Kumulativne vsote:", tabela, n);

void izpisTabele(char opis[], int *tabela, int n) {
    printf(opis);
    for (int j = 0; j < n; ++j) {
        printf(" %d", tabela[j]);
    }
    printf("\n");
}

```


## Uporaba knjižnic

V glavnem programu knjižnice vključimo tako, da zgolj vključimo ``.h`` datoteke, torej zgolj povemo, kako naše funkcije 
izgledajo, ne pa tudi njihovo implementacijo.

```c
#include <stdio.h>
#include <stdlib.h>

// Vkljucimo delaracijo funkcij
#include "tabele.h"

int main(void) {
    int n;
    // Uporabimo funkcije
    int *tabela = vnosTabele("Vnesi dolzino table: ", "Vnasi %d. element tabele: ", &n);
    izpisTabele("Sodi elementi:", tabela, n);

    return 0;
}
```

Program prevedemo tako, da prevajalniku hkrati podamo glavno datoteko in implementacijske datoteke vključenih knjižnic.
V primeru iz vaj bi tako program prevedli kot: 

```gcc -std=c99 -Wall kazalci-4.c tabele.c -o kazalci-4.exe```

### Opomba
Prevajalnik nam (povsem upravičeno) javi, da v funkcijijah ```printf``` in ``scanf`` ne uporabljamo konstantnega niza, 
kar je potencialno lahko varnostna težava.

Povezovanje (linkanje) je sicer zahtevno in pogosto težko, zato si pogosto pomagamo z različnimi orodji, kot so 
```make``` in ``cmake``, več o povezovanju in prevajanju si lahko preberete na [https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html).

Po vsem zgornjih težavah z povezovanjem se pojavi vprašanje, zakaj je deljenje datotek na deklaracijske in 
implementacijske sploh smiselno. Glavni namen ločene deklaracije in implementacije je predvsem zmožnost, da z 
deklaracijo podamo samo dogovor, kako bodo funkcije izgledale (med prevajanjem prevajalnik potrbuje zgolj signature), 
ob povezovanju (linkanju) pa podamo prave implementacije (ki so lahko ob povezovanju drugačne recimo: bolj optimizirane, 
novejše, posebej prevedene za ciljno arhitekturo ...). Več o razliki lahko brez težav najdete na internetu, v pomoč pa 
vam je lahko spodnja povezava:

[https://stackoverflow.com/questions/1410563/what-is-the-difference-between-a-definition-and-a-declaration](https://stackoverflow.com/questions/1410563/what-is-the-difference-between-a-definition-and-a-declaration)



