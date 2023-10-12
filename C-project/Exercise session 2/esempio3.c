/* esempio vettore */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main () {

	int a[SIZE];
	
	for (int i=0; i<SIZE; i++) {
		printf("Inserisci il valore di a[%d]:", i);
		scanf("%d", &a[i]);	
	}
	printf("Hai inserito:\n");
	for (int i=0; i<SIZE; i++) {
		printf("%d\n", a[i]);
	}
	printf("\n");


}
