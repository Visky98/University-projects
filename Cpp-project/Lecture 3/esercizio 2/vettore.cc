#include <iostream>
#include <cstdlib>
#include <cmath>
#include "vettore.h"

//inizializzo i costruttori
vettore::vettore() {
	x_p=0;
	y_p=0;
}

vettore::vettore(const double* x_p, const double* y_p) {
	x_p=x;
	y_p=y;
}

vettore::vettore (const vettore& originale) {
	x_p=originale.x_p;
	y_p=originale.y_p;
}

//inizializzo il distruttore
vettore::~vettore() {

}

//operator overload
vettore& vettore::operator= (const vettore& originale) {
	x_p=originale.x_p;
	y_p=originale.y_p;
	return *this;
}

vettore vettore::operator+ (const vettore& vettore2) {
	double x=x_p+(vettore2.x_p);
	double y=y_p+(vettore2.y_p);
}

vettore vettore::operator- (const vettore& vettore2) {
	double x=x_p-(vettore2.x_p);
	double y=y_p-(vettore2.y_p);
}

//funzioni
double prodotto (double k) {
	double x=x_p*k;
	double y=y_p*k;
	return x, y;
}

double modulo () {
	double xquad=(x_p)*(x_p);
	double yquad=(y_p)*(y_p);
	return sqrt(xquad+yquad);
}

void print() {
	std::cout << "x_p: " << 
}
