#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include "TApplication.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TH1.h"
#include "TF1.h"
#include "TFitResult.h"
#include "TMatrixDSym.h"
using namespace std;

void computeChi2(TH1D* myHisto, TF1* myFun, double& Chi2, double& NDF, double& pvalue) {
	double result = 0;
	NDF = 0.;
	for (unsigned int i = 1; i <= myHisto->GetNbinsX(); i++) {
     		if (myHisto->GetBinContent(i) != 0.) {
	  		result += pow((myHisto->GetBinContent(i) - myFun->Eval(myHisto->GetBinCenter(i))),2.) / myHisto->GetBinContent(i);
	  		NDF++;
		}
	}
	Chi2   = result;
	NDF   -= myFun->GetNpar();
	pvalue = TMath::Prob(Chi2,NDF);
}




int main (int argc, char** argv) {
	gStyle->SetOptFit(1112);
	if (argc < 2) {
      		cout << "Insufficient number of parameters: ./ReadData1AndFit fileName.txt" << endl;
      		return 1;
    	}
	double a;
	int righe=0;
  	vector<double> dataList;
	std::ifstream InFile;
	InFile.open("diodo.txt", std::ios::in);
	if (InFile.good() == 0) {
 		std::cout << "Errore! Non è possibile aprire il file" << std::endl;
 		return 1;
	}
	while(true) {
		InFile >> a;
		if(InFile.eof()==true) {
			break;
		}
		else {
			dataList.push_back(a);
			std::cout << a << "\t" << std::endl;
			righe++;
		}
	}
	InFile.close();
	TApplication* myApp = new TApplication("myApp", NULL, NULL);
	int nBins = 20;
  	TH1D* h1 = new TH1D("h1","Data distribution", nBins, 0.10, 0.50);
	//cout << dataList.size() << endl;
  	h1->SetFillColor(kRed+6);
 	h1->GetXaxis()->SetTitle("Variable x");
	h1->GetYaxis()->SetTitle("Counts");
  	for (unsigned int i = 0; i < dataList.size(); i++) {
		h1->Fill(dataList[i]);
	}
	TCanvas* myCanv1 = new TCanvas("myCanv1","myCanv1",0,0,700,500);
	myCanv1->cd();
  	h1->Draw();
  	h1->Fit("gaus");
	myApp->Run();
	return 0;
}
