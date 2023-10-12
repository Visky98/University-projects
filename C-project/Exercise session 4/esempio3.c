#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	float somma=0;
	for (int i=1; i<argc; i++) {
		somma +=atof(argv[i]); /* += equivale a scrivere:somma=somma  + */
	}
	printf("la somma di tutti gli argomenti e %f\n", somma);
	exit(EXIT_SUCCESS);
}
