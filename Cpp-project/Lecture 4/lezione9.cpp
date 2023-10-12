#include <iostream>
#include <cmath>
#include <cstdlib>
#include <TApplication.h>
#include <TF1.h>
using namespace std;

int main () {
	TApplication* myApp= new TApplication("myApp", NULL, NULL);
	TCanvas* myCanv= new TCanvas("myCanv", "esponenziale", 0, 0, 650, 450);
	TF1* funzione= new TF1("funzione", "(1/mu)*exp(-x/mu)",-20, 20); 
	//pdf dell'estimatore
	TH1F *hmedia= new TH1F("hmedia", "pdf dell'estimatore", 100, 0, 40);
	double somma;
	double mu=7;
	//numero di campionamenti della pdf
	int camp;
	cout<< "numero di campionamenti: ";
	cin>> camp;
	//quante volte ripeto l'esperimento
	int nexp=10000; 
	for (int i=0; i<nexp; i++) {
		somma=0;
		for (int i=0; 
	}
}
