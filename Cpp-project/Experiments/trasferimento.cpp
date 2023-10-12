#include <iostream>
#include <cmath>
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TAxis.h"
#include <TF1.h>
#include <TStyle.h>

using namespace std;

double esponenziale (double* x, double* par) {
	return 1/(x[0]*par[0]);
}

void computeChi2(TGraphErrors* myData, TF1* myFun, double& Chi2, double& NDF, double& pvalue) {
	double result = 0;
	for (int i = 0; i < myData->GetN(); i++) {
		result += pow(myData->GetY()[i] - myFun -> Eval(myData->GetX()[i]),2.) / (pow(myData->GetErrorY(i),2.) + pow(myFun->Derivative(myData->GetX()[i])*myData->GetErrorX(i),2.));
	}
	Chi2 = result;
	NDF = myData->GetN() - myFun->GetNpar();
	pvalue = TMath::Prob(Chi2,NDF);
}	 

int main(int argc, char** argv) {
	if (argc < 2) {
		cout << "Not enough parameters: ./FitTGraphErrors filename.txt" << endl;
		return 1;
	}
	gStyle->SetOptFit(1112);
	TApplication* myApp = new TApplication("myApp", NULL, NULL);
	TCanvas* myC = new TCanvas("myC", "myC", 0, 0, 600, 330);
	TF1* myFun = new TF1("myFun", esponenziale, 1257, 4084, 1);
	myFun->SetParameter(0, 0.0000023);
	myFun->SetParName(0,"capacita'");

// TGRaphErrors constructor from file
	TGraphErrors* myGraph = new TGraphErrors(argv[1]);
	myGraph->GetYaxis()->SetTitle("Z(w)");
	myGraph->GetXaxis()->SetTitle("W [Hz]");
	myGraph->SetMarkerStyle(20); //come visualizzare la coppia di dati (20=punto)
	myGraph->SetMarkerSize(0.5); //grandezza del punto
	myC->cd();
	myGraph->Draw("AP");
	myGraph->Fit("myFun", "1257", "4084");
	myC->Modified();
	myC->Update();
	
	cout << "\nREduced Chi-2: " << myFun->GetChisquare()/myFun->GetNDF() << endl;
	cout << "p-value: " << myFun->GetProb() << endl;

	double Chi2, NDF, pvalue;
	computeChi2(myGraph, myFun, Chi2, NDF, pvalue);
	cout << "\nMy Chi-2: " << Chi2 <<endl;
	cout << "My NDF: " << NDF << endl;
	cout << "My reduced Chi-2: " << Chi2/NDF << endl;
 	cout << "My p-value: " << pvalue << endl;

	myApp->Run();
	return 0;
}
