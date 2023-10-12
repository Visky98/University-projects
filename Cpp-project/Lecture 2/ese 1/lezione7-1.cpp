#include <iostream>
#include <vector>
#include "lezione7-1.h"

int main() {
	//definisco il vettore su cui voglio lavorare usando il costruttore
	char istruzione;
	char in='i', t='t', e='e';
	int elem; 
	int indice_vettore;
	std::cout << "quanti elementi vuoi creare nel vettore? => ";
	std::cin >> indice_vettore;
	simplearray<int> vettore(indice_vettore);
	//riempio il vettore
	for (int i=0; i<indice_vettore; i++) {
		std::cout << "inserisci il valore in posizione " << i << ": ";
		std::cin >> elem;
		vettore.elemento(i)=elem;
	}
	for(int i=0; i<(indice_vettore); i++) {
		std::cout << "la componente " << i << " del vettore è: " << vettore[i] << std::endl;
	}
	std::cout << "quale operazione vuoi eseguire?" << std::endl;
	std::cout << "-inserisci (i)       -togli (t)       -esci (e)" << std::endl;
	std::cin >> istruzione;
	if(istruzione==in) {
		std::cout << "nuovo elemento da inserire nel vettore: ";
		std::cin >> elem;
		vettore.push(elem); 
	}
	else if(istruzione==t) {
		std::cout << "inserisci l'indice dell'elemento da togliere dal vettore: ";
		std::cin >> indice_vettore;
		vettore.pop(indice_vettore);
	}
	int k=vettore.lunghezza();
	std::cout << "il vettore ha: " << k << " elementi" << std::endl;
	for(int f=0; f<k; f++) {
		std::cout << "l' " << f <<"-esimo elemento è: " << vettore[f] << std::endl;
		}
}
