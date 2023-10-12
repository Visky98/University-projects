/* Esempio somma di due numeri interi */

#include <stdio.h>
#include <stdlib.h>

int main()  {

	int a, b;
	int somma;
	
	a = 1968;
	b = -404;
	
	somma = a + b;	

	printf("La somma e %d\n", somma);

	a=765;

	printf("La somma e %d\n", somma);

	somma=a+b;

	printf("La somma e %d\n", somma);

	/* lettura di a e b da tastiera */

	scanf("%d", &a);
	scanf("%d", &b);

	printf("La somma e %d\n", a+b);

}
