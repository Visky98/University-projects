#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "TApplication.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TH1.h"
#include "TF1.h"
#include "TFitResult.h"
#include "TMatrixDSym.h"
using namespace std;


int main(int argc, char **argv) {
	double num, xmin, xmax;
	vector<double> dataList;	
	gStyle-> SetOptFit(1112);
	if (leggidati(argv[1], dataList, xmin, xmax)==false) {
		cout << "Errore" << endl;
		return 1;
	}
	cout << "Il file " << argv[1] << " contiene " << dataList.size() << " dati. " << endl;
	cout << "Il minimo è: " << xmin << "; e il massimo: " << xmax << endl;
	TApplication* myApp= new TApplication ("myApp", NULL, NULL);
	int nbins=100;
	TH1D* istogramma1= new TH1D("istogramma1", "distribuzione dati", nbins, xmin, xmax);
	istogamma1->SetFillColor(kAzure+7);
  	istogramma1->GetXaxis()->SetTitle("Variabile x");
  	istogramma1->GetYaxis()->SetTitle("Conteggi");
	for(unsigned int i=0; i<dataList.size(); i++) {
		istogramma1->Fill(dataList[i]);
	}
	//creo la tavolozzza
	TCanvas* mycanv1=new TCanvas ("mycanv1", "mycanv1", 0, 0, 700, 500);
	//creo la funzione con cui fittare l'istogramma
	TF1* funzione= new TF1 ("funzione", somma, xmin xmax, 6);
	//massimo della gaussiana
	funzione->SetParameter(0, 10000);
	//media della guassiana
	funzione->SetParameter(1, 5);
	//deviazione stadard della gaussiana
	funzione->SetParameter(2, istogramma1->GetRMS());
	//intercetta della parabola
	funzione->SetParameter(3, 1000);
	funzione->SetParName (0, "ampiezza");
	funzione->SetParName (1, "media");
	funzione->SetParName (2, "sigma");
	funzione->SetParName (3, "zero");
	funzione->SetParName (4, "primo");
	funzione->SetParName (5, "secondo");
	//fit con la funzione creata
	mycanv1->cd();
	istogramma->Draw();
	istogamma1->Fit("funzione");
	//calcoli statistici
	cout << "\n chi2 ridotto: " << funzione->GetChisquare()/funzione->Getndf() << endl;
	cout << "pvalue: " << funzione->GetProb() << endl;
	for (unsigned int i=0; i<funzione->GetNPar(); i++) {
		cout << "parametro-" << i << " = " << funzione->GetParameter(i) << " +/- " << funzione->GetParError(i) << endl;
	}
	//calcolo numero di entrate per la gaussiana
	TF1* mysignal= new TF1("mysignal", mygauss, xmin, xmax, 3);
	mysignal->SetLineColor(kblack);
	mysignal->SetParameter(0, funzione->GetParameter(0));
	mysignal->SetParameter(1, funzione->GetParameter(1));
	mysignal->SetParameter(2, funzione->GetParameter(2));
	cout << "numero entrate per il segnale: " << nbins/(xmax-xmin)*mysignal->Integral(xmin, xmax) << endl;
	//calcolo numero d ientate per la prabola 
	TF1* mybackground =new TF1 ("mybackground", myparabola, xmin, xmax, 3);
	mybackground->SetLineColor(kblue);
	mybackground->SetParameter(0, funzione->Getparameter(3));
	mybackground->SetParameter(1, funzione->Getparameter(4));
	mybackground->SetParameter(2, funzione->Getparameter(5));
	cout << "numero di entrate per il fondo: " << nbins/(xmax-xmin)*mybackground->Integral(xmi, xmax) << endl;
	double chi2, ndf, pvalue;
	calcola_chi2 (istogramma1, funzione, chi2, ndf, pvalue);
	cout << "\nil chi2 è: " << chi2 << endl;
	cout << "i ndf sono: " << ndf << endl;
	cout << "il chi2 ridotto vale: " << chi2/ndf << endl;
	cout << "pvalue vale: " << pvalue << endl;
	mybackground->Draw("same");
	mycanv1->Modified();
	mycanv1->Update();
	//stampa della matrice di covarianza
	TFitResultPtr r=istogramma1->Fit("funzione", "S");
	r->Print("V");
	TMatrixDSym cov=r->GetCovarianceMatrix();
	cout << "\nMatrice di covarianza: " << endl;
 	for (int i = 0; i < myFun->GetNpar(); i++) {
      		for (int j = 0; j < myFun->GetNpar(); j++) {
			double sigma_ij = cov(i,j);
	  		cout << setw(15) << sigma_ij;
		}
      		cout << endl;
    	}
	myApp->Run();
	return 0;
}
