#include <stdio.h>
#include <string.h>


#define MAX_LEN 1000
#define SIZE 'z' - 'a' + 1

int main(void) {
    char niz[MAX_LEN];
    printf("Vnesi besedilo: ");
    fgets(niz, sizeof(niz), stdin);
    printf("%s", niz);

    int crke[SIZE] = {0};

    for(int j = 0; niz[j]; ++j){
        char trenutni = niz[j];
        if('A' <= trenutni && trenutni <= 'Z'){
            ++crke[trenutni - 'A'];
        }else if('a' <= trenutni && trenutni <= 'z'){
            ++crke[trenutni - 'a'];
        }
    }
    printf("Stevilo crk:\n");
    for(int j = 0 ; j < SIZE; ++j){
        if(crke[j]){
            printf("#%c = %d\n", 'a' + j, crke[j]);
        }
    }

    return 0;
}