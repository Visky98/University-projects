/* esempio passaggio parametri a funzioni */

#include <stdio.h>
#include <stdlib.h>

#define D 5

double f(double x, double y) {

	double e;
	x=2.0*y;
	e=-x;

	return y+e*e;
}
void g(int v[], int dim, int i) {
	
	if (0<=i && i<dim) {
		v[i]=-v[i];
	}
	return;
}

int main () {
	double a=3.14;
	double b=-2.71;
	double x=1.968;
	double z;

	z=f(a,b);
	printf("z: %f, a: %f, b: %f,x: %f\n", z, a, b, x);
	
	int q[D]={1, 2, 3, 4, 5};
	int i=0;
	g(q, D, i);

	for(int j=0; j<D; j++) {
		printf("q[%d]; %d\n", j, q[j]);

	}


}





