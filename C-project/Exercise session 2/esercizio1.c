/* esercizio1 */

#include <stdio.h>
#include <stdlib.h>

float eleva(float base, int exp) {
	int i=0;
	float r=1;
	while (i<exp) {
		r=r*base;
		i++;
	}
	return r;
}
int main () {
	float a;
	int b;
	scanf("%f", &a);
	scanf("%d", &b);
	printf("Il valore di a e %f \n", a);
	printf("Il valore di b e %d \n", b);
	float p;
	p=eleva(a,b);
	printf("Il risultato e %f \n", p);


}
