#include <iostream>
#include <cstdlib>
#include <cmath>
#include "complessi.h"


//inizializzo i costruttori
complesso::complesso() {
	reale_p=0;
	immaginaria_p=0;
}


complesso::complesso (const double& reale, const double& immaginaria) {
	reale_p=reale;
	immaginaria_p=immaginaria;
}


complesso::complesso (const complesso& originale) {
	reale_p=originale.reale_p;
	immaginaria_p=originale.immaginaria_p;
}


//inizializzo il distruttore
complesso::~complesso () {

}


//operator overload
complesso& complesso::operator= (const complesso& originale) {
	reale_p=originale.reale_p;
	immaginaria_p=originale.immaginaria_p;
	return *this;
}


complesso complesso::operator+ (const complesso& originale) {
	double reale=reale_p+(originale.reale_p);
	double immaginaria= immaginaria_p+(originale.immaginaria_p);
	return complesso(reale, immaginaria);
}


complesso complesso::operator- (const complesso& originale) {
	double reale=reale_p-(originale.reale_p);
	double immaginaria=immaginaria_p-(originale.immaginaria_p);
	return complesso(reale, immaginaria);
}


complesso complesso::operator* (const complesso& originale) {
	double reale=(reale_p*originale.reale_p)-(immaginaria_p*originale.immaginaria_p);
	double immaginaria=(reale_p*originale.reale_p)+(immaginaria_p*originale.immaginaria_p);
	return complesso(reale, immaginaria);
}


complesso complesso::operator/ (const complesso& originale) {
	double denominatore=(originale.reale_p*originale.reale_p)+(originale.immaginaria_p*originale.immaginaria_p);
	double reale=((reale_p*originale.reale_p)+(immaginaria_p*originale.immaginaria_p))/denominatore;
	double immaginaria=((reale_p*originale.reale_p)-(immaginaria_p*originale.immaginaria_p))/denominatore;
	return complesso(reale, immaginaria);
}


/*complesso complesso::operator^ (const int& potenza) {
	double complesso::theta;
	double complesso::rho;
	for (int i=0; i<potenza; i++) {
		rho=rho*rho;
	}
	double reale=
} */


//funzioni
double complesso::reale() const {
	return reale_p;
}


double complesso::immaginaria() const {
	return immaginaria_p;
}


double complesso::rho() const {
	return sqrt(reale_p*reale_p+immaginaria_p*immaginaria_p);
}


double complesso::theta() const {
	return atan(immaginaria_p/reale_p);
}

void complesso::stampa() const {
	if(immaginaria()>=0) {
		std::cout << reale() << " +i " << immaginaria() << std::endl;
	}
	else if(immaginaria()<0) {
		std::cout << reale() << " -i " << immaginaria() << std::endl;
	}
}
