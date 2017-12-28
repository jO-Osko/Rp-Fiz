
#include <stdio.h>
#include <stdlib.h>


int* fibbonaci(int n){
    int *p = malloc(n * sizeof(*p));
    if (n == 0){
        return p;
    }
    p[0] = 1;
    if(n == 1){
        return p;
    }
    p[1] = 1;
    if(n == 2){
        return p;
    }
    for(int j = 2; j < n; ++j){
        p[j] = p[j-1] + p[j-2];
    }

    return p;
}

int main(void){
    int n;
    printf("Vnesi stevilo clenov: ");
    scanf("%d", &n);

    int* stevila = fibbonaci(n);

    for(int j = 0; j < n; ++j){
        printf("%d ", stevila[j]);
    }
    printf("\n");
    free(stevila);
    stevila = NULL;

    return 0;
}