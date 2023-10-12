/* Esempio di selezione con if else */

#include <stdio.h>
#include <stdlib.h>

int main () {
	
	int x;
	scanf("%d", &x);
	
	if( x<0) {
		x=-x;
		printf("il valore e %d\n", x);
	}
	else {
	printf("il valore e %d\n", x);
	}
}
