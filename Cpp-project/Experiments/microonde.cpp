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

double retta (double* x, double* par) {
	return par[0]*x[0]+par[1];
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
	TCanvas* myC = new TCanvas("myC", "myC", 0, 0, 80, 80);
	TF1* myFun = new TF1("myFun", retta, 0, 80, 2);
	myFun->SetParameter(0,1);
	myFun->SetParameter(1,0);
	myFun->SetParName(0,"a");
	myFun->SetParName(1,"b");

// TGRaphErrors constructor from file
	TGraphErrors* myGraph = new TGraphErrors(argv[1]);
	myGraph->GetXaxis()->SetTitle("Angolo incidenza [gradi]");
	myGraph->GetYaxis()->SetTitle("Angolo rifrazione [gradi]");
	myGraph->SetMarkerStyle(20);
	myGraph->SetMarkerSize(0.5);
	myC->cd();
	myGraph->Draw("AP");
	myGraph->Fit("myFun");
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





