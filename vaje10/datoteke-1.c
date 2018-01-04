#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int datoteke_1(char vhod[], char liha[], char soda[]){
    FILE *vhodna = fopen(vhod, "rt");
    if (vhodna == NULL){
        return 1;
    }
    FILE *d_liha = fopen(liha, "wt");
    if(d_liha == NULL){
        fclose(vhodna);
        return 2;
    }
    FILE *d_soda = fopen(soda, "wt");
    if(d_soda == NULL){
        fclose(vhodna);
        fclose(d_soda);
        return 3;
    }
    int rezultat;
    int n;
    while((rezultat = fscanf(vhodna, "%d", &n)) != EOF){
        if(n % 2 == 0){
            fprintf(d_soda, "%d ", n);
        }else{
            fprintf(d_liha, "%d ", n);
        }
    }

    fclose(vhodna);
    fclose(d_soda);
    fclose(d_liha);
    return 0;
}


int main(){
    return datoteke_1("stevila/stevila.in", "stevila/liha.out", "stevila/soda.out");
}
