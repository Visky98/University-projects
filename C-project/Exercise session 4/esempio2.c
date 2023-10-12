#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	if(argc!=3) {
		printf("il programma richiede esattamente due argomenti\n");
		exit(EXIT_FAILURE);
	}
	int a=atoi(argv[1]);  
	int b=atoi(argv[2]);
	int somma=a+b;
	printf("la somma di %d e %d e %d\n", a, b, somma);
	exit(EXIT_SUCCESS);
}
