/* esercizio 3 elearning ciclo while */

#include <stdio.h>
#include <stdlib.h>

int main () {
		
	int num;
	int somma;
	int cont;
	somma=0;
	scanf("%d", &num);
	cont=1;

	while(num!=0) {
		
		int quad=num*num;
		somma=somma+quad;
		
		scanf("%d", &num);
		cont=cont+1;
	}
	
	float media;
	media=somma/cont;
	
	printf("Somma: %d - Media %f\n", somma, media);












}
