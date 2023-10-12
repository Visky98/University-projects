#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "TApplication.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TGraphErrors.h"
#include "TAxis.h"
using namespace std;



int main (int argc, char** argv) {
	gStyle -> SetOptFit(1112);
	TApplication* myapp = new TApplication ("myapp", NULL, NULL);
	TCanvas* mycanvas = new TCanvas ("mycanvas", "mycanvas", 0, 0, 800, 600);
	//costruttore del grafico con errori che legge direttamente dal file
	TGraphErrors* grafico = new TGraphErrors(argv[1]);
	//tipo di simbolo del marker
	grafico->SetMarkerStyle (20);
	grafico->SetTitle ("carica condensatore");
	grafico->GetXaxis()->SetTitle ("t [secondi]");
	grafico->GetYaxis()->SetTitle ("V [volt]");
	TF1* funzione = new TF1 ("funzione", "[0]*(1-exp(-x/[1]))");
	//assegno il nome al parametro zero e il valore corrispondente
	funzione->SetParName (0, "ampiezza");
	funzione->SetParameter(0, 5);
	//assegno il nome al parametro uno e il valore corrispondente
	funzione->SetParName (1, "tau");
	funzione->SetParameter(1, 0.4);
	mycanvas->cd();
	grafico->Draw("AP");
	grafico->Fit("funzione");
	mycanvas->Modified();
	mycanvas->Update();
	cout << "\nV0 vale: " << funzione->GetParameter(0) << " e il suo errore è +/- " << funzione->GetParError(0) << endl;
	cout << "\nTau vale: " << funzione->GetParameter(1) << " e il suo errore è +/- " << funzione->GetParError(1) << endl;
	myapp->Run();
	return 0;
}
