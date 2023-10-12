#include <stdio.h>
#include <stdlib.h>

int main () {
	int *vettore;
	vettore=(int *) malloc (sizeof(int)*100);
	if(vettore==NULL) {
	printf("NO!\n");
	exit(EXIT_FAILURE);
	}
	vettore[0]=10;
	vettore[1]=20;
	printf("vettore[0]=%d\n", vettore [0]);
	printf("vettore[1]=%d\n", vettore [1]);

	/* usando i puntatori */
	*(vettore+0)=12;
	*(vettore+1)=24;
	printf("vettore[0]=%d\n", *(vettore+0));
	printf("vettore[1]=%d\n", *(vettore+1));
	exit(EXIT_SUCCESS);
}
