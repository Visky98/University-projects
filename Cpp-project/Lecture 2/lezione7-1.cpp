#include <iostream>
#include "lezione7-1.h"

int main() {
	//definisco il vettore su cui voglio lavorare usando il costruttore
	simplearray<int> vettore;
	char istruzione;
	int elem;
	int indice_vettore;
	std::cout << "quale operazione vuoi eseguire?" << std::endl;
	std::cout << "-inserisci (i)       -togli (t)       -esci (e)" << std::endl;
	std::cin >> istruzione;
	if(istruzione==i) {
		std::cout << "nuovo elemento da inserire nel vettore: ";
		std::cin >> elem;
		vettore.push(elem); 
	}
	else if(istruzione==t) {
		std::cout << "inserisci l'indice dell'elemento da togliere dal vettore: ";
		std::cin >> indice_vettore;
		vettore.pop(indice_vettore);
	}
	while(istruzione!=e) {
		int k=vettore.size();
		std::cout << "il vettore ha: " << k << " elementi" << std::endl;
		for(int i=0; i<k; i++) {
			std::cout << "l' i-esimo elemento è: " << vettore[i] << std::endl;
		}
	}
}
