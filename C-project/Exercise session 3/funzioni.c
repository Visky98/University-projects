#include <stdio.h>
#include <stdlib.h>

int incrementa_uno(int a) {
	a=a+1;
	return a;
}

int incrementa_uno_bis(int *a) {
	*a=*a+1;
	return *a;
}

int main () {
	int v1=10;
	int v2=incrementa_uno(v1);
	printf("v1=%d, v2=%d\n", v1, v2);
	int v3=incrementa_uno_bis(&v1);
	printf("v1=%d, v3=%d\n", v1, v3);
}
