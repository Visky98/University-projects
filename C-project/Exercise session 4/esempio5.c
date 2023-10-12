#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cerca(int valore, int *vettore, int len) {
	bool trovato=false;
	int indice=-1;
	int i=0;
	while ((i<len) && (trovato==false)) {
		if (vettore[i]==valore) {
		trovato=true;
		indice=i;
		}
		i++;
	}
	return indice;
}
 
int main (int argc, char *argv[]) {
	int v[]= {2, 4, 5, 1, 55, 3, -4, 9, 0, 10};
	int a= cerca(4, v, 10);
	printf("posizione di 4 nel vettore: %d\n", a);
	int b=cerca(7, v, 10);
	printf("posizione di 7 nel vettore: %d\n", b);
	exit(EXIT_SUCCESS);
}
