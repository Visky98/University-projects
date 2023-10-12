/* esempio ciclo for e funzioni */

#include <stdio.h>
#include <stdlib.h>

int fattoriale (int n) {

	int m=1;
	for (int i=1; i<=n; i++) {
		m=m*i;
	}
	return m;
}

int main () {
	
	int valore;
	scanf("%d", &valore);
	int risultato=fattoriale(valore);
	printf("Il fattoriale di %d e %d\n", valore, risultato);
	int risultato2=fattoriale(5);
	printf("Il fattoriale di %d e %d\n", 5, risultato2);
	int risultato3=fattoriale(1+2+2);
	printf("Il fattoriale di %d e %d\n", 1+2+2, risultato3);
}
