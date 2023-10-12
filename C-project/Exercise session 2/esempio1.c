/* esempio define */

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14157

int main ()  {

	float radius;
	scanf("%f", &radius);

	float circ=2*radius*PI;
	float area=radius*radius*PI;
	printf("La circonferenza e %.4f	e l'area e %.4f\n", circ, area);
}
