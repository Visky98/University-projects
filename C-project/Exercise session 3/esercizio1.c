#include <stdio.h>
#include <stdlib.h>

int main () {
	int a=10;
	int *ptr_a; /* variabile puntatore a un intero */
	int b;
	ptr_a=&a;
	b=a;
	b=b+10;
	printf("a=%d, b=%d\n", a, b);
	*ptr_a=*ptr_a+10; /* incremento della variabile a */
	printf("a=%d, *prt_a=%d\n", a, *ptr_a);
	exit(EXIT_SUCCESS);
}
