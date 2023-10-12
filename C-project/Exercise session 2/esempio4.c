/* esempio matrici */

#include <stdio.h>
#include <stdlib.h>

#define N 4

int main () {
	int a[N][N];
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			printf("Inserisci il valore alla riga %d e alla colonna %d:", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	printf("Hai inserito:\n");
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}



}
