#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

/*
Poglejmo si kako si lahko podajamo funkcije kot parameter drugi funkciji,
edina omejitev ki se pojavi pri podajanju funkcij kot parametrov je ta;
'funkcija' lahko sprejme katerokoli 'pfunkcijo' le da morajo vse biti istega tipa (int) in sprejmejo natanko enako stevilo parametrov, ki so prav tako pripadajocega tipa!!
*/

//1. funkcija ki jo bomo podlai kot parameter
int parameterfunkcija1(int a) {
    int b = a + 13;
    return b;
}

//2. funkcija ki jo bomo podlai kot parameter
int parameterfunkcija2(int a) {
    int b = a - 15;
    return b;
}

//funkcija, ki bo sprejela funkcijo kot parameter
int funkcija(int pfunkcija(int b), int a) {
    int x = pfunkcija(a) * 3;
    return x;
}

//preverimo kaj se zgodi
int main(void) {
    int n = 4;

    //prvic bomo pognali 'funkcijo' z parameterfunkcijo1
    //ko navedemo funkcijo navedemo samo njeno ime
    //ker pa 'funkcija' pricakuje se drug parameter, ki ga bo kasneje dala 'pfunkciji' moramo navesti se tega
    int prva = funkcija(parameterfunkcija1, n);
    printf("%d\n", prva);

    //poglejmo kaj se zgodi ko pozenemo 'funkcijo' z parameterfunkcijo2
    int druga = funkcija(parameterfunkcija2, n);
    printf("%d\n", druga);


    return 0;
}