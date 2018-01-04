#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 250


/*
ta funkcija vzame ime datoteke in vrne kazalec na tabelo, ki vsebuje kazalce nizov na katerih so shranjene vrstice iz datoteke,
preko dodatne parametra vrne funkcija stevilo vrstic!
*/
char **fileTabNiz(char file[MAX], int *dolzina){
	
	FILE *f = fopen(file, "rt");
	
	char **tabniz = (char **)malloc(MAX * sizeof(char *));
	for(int i=0; i<MAX; i++){
		*(tabniz + i) = (char *)malloc(MAX * sizeof(char));
	}
	
	int n=0;
	while(1){
		char *str = fgets(*(tabniz + n), MAX, f);
		if(str == NULL) break;
		n++;
	}
	
	*dolzina = n;
	
	fclose(f);
	return tabniz;
}


int main(void){
	char niz[MAX];
	printf("Vnesi ime datoteke: ");
	fflush(stdin);
	gets(niz);
	
	int *n = (int *)malloc(sizeof(int));
	char **vrstice = fileTabNiz(niz, n);
	
	for(int i=0; i<*n; i++){
		printf("%s", *(vrstice + i));
	}
	
	free(n);
	free(vrstice);
	return 0;
}