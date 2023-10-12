/* esercizio 2 elearning */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int x;
	int somma;
	int cont;
	printf("inserisci il primo valore\n");
	scanf("%d", &x);
	cont=0;
	somma=0;
	while (cont<9) {
	somma=somma+x;
	printf("inserisci il valore\n");
	scanf("%d", &x);
	cont=cont+1;
	}
	float media;
	media=somma/10;
	printf("la somma e %d e la media e %f", somma, media);
}
