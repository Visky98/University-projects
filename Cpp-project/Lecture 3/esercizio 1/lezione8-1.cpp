#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int main(int argc, char** argv) {
	//creo 2 vettori
	int righe=0;
	double a, b;
	std::vector<double> vettore1;
	std::vector<double> vettore2;
	std::ifstream InFile;
	InFile.open("dati.txt", std::ios::in);
	if (InFile.good() == 0) {
 		std::cout << "Errore! Non è possibile aprire il file" << std::endl;
 		return 1;
	}
	while(true) {
		InFile >> a >> b;
		if(InFile.eof()==true) {
			break;
		}
		//else {
			vettore1.push_back(a);
			vettore2.push_back(b);
					std::cout << a << "\t" << b << std::endl;
			righe++;
		//}
	}
	
	InFile.close();
	double media=0;
	double varianza=0;
	double somma=0;
	double quadrati=0;
	for(int i=0; i<righe; i++) {
		somma=somma+vettore1[i];
		quadrati=quadrati+(vettore1[i]*vettore1[i]);
	}
	media=somma/righe;
	varianza=sqrt((quadrati/(double)righe)-(media*media));
	std::fstream OutFile;
	OutFile.open("calcoli.txt", std::ios::out);
	OutFile << "La media della prima colonna è: " << media << std::endl;
	OutFile << "La deviazione della prima colonna è: " << varianza << std::endl;
	//calcoli sulla seconda colonna
	somma=0;
	quadrati=0;
	for(int i=0; i<righe; i++) {
		somma=somma+vettore2[i];
		quadrati=quadrati+(vettore2[i]*vettore2[i]);
	}
	media=somma/righe;
	varianza=sqrt((quadrati/(double)righe)-(media*media));
	OutFile << "La media della seconda colonna è: " << media << std::endl;
	OutFile << "La deviazione della seconda colonna è: " << varianza << std::endl;
	OutFile.close();
}
