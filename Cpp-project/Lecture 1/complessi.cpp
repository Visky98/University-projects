#include <iostream>
#include <cmath>
#include "complessi.h"

int main() {
	complesso z(1, -1);
	complesso w(2, -2);
	z.stampa();
	w.stampa();
	//somma tra complessi	
	complesso somma=z.operator+(w);
	somma.stampa();
	//sottrazione tra complessi
	complesso differenza=z.operator-(w);
	differenza.stampa();
	//prodotto tra complessi
	complesso prodotto=z.operator*(w);
	prodotto.stampa();
	//divisione tra complessi
	complesso quoziente=z.operator/(w);
	quoziente.stampa();
	//calcolo del modulo di z
	z.rho();
	std::cout << "Il modulo di z è: " << z.rho() << std::endl;
	//calcolo dell'angolo di z 
	z.theta();
	std::cout << "L'angolo di z è: " << z.theta() << std::endl;
	//calcolo del modulo di w 
	w.rho();
	std::cout << "Il modulo di w è: " << w.rho() << std::endl;
	//calcolo dell'angolo di w 
	w.theta();
	std::cout << "L'angolo di w è: " << w.theta() << std::endl;
}
