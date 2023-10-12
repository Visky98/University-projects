/*generazione numeri pseudorandom */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
	srand(3456897); /* funzione che genera num. random */
	int valori[6];
	for(int i=0; i<6; i++) {
		valori[i]=0;
	}
	for(int i=0; i<10; i++) {
		int tmp=rand()%6+1;  /* tmp= variabile temporanea */
		valori[tmp-1]++;
	}
	for(int i=0; i<6; i++) {
		printf("numero di volte in cui %d e stato generato: %d\n", i+1, valori[i]); 
	}
	exit(EXIT_SUCCESS);
}
