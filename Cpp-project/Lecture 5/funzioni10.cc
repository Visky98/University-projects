#include <cstdlib>
#include <cmath>
#include "funzioni10.h"
using namespace std;

double mygauss (double* x, double* par) {
	return par[0]*exp(-0.5*((x[0]-par[1])*(x[0]-par[1])/     	 	(par[2]*par[2])));
}

double myparabola (double* x, double* par) {
	return par[0]+par[1]*x[0]+par[2]*x[0]*x[0];
}

double somma (double* x, double* par) {
	double valore= mygass(x, par)+myparabola(x, &par[3]);
	return valore;
}

bool leggidati (char* data1, vector<double>& dataList, double& xmin, double& xmax) {
	double num;
	bool first=true;
	std::fstream in;
	in.open (data1, std::ios::in);
	if (in.good()== true) {
		return false;
	}
	while (true) {
		in>>num;
		if (in.eof()==true) {
			break;
		}
		dataList.push_back(num);
		if (first==true) {
			xmin=num;
			xmax=num;
			first=false;
		}
		else {
			if (num<xmin) {
				xmin=num;
			}
			if (num>xmax) {
				xmax=num;
			}
		}
	}
	return false;
}

void calcola_chi2 (TH1D* istogramma1, TF1* funzione, double& chi2, double& ndf, double& pvalue) {
	double result=0;
	ndf=0;
	for (unsigned int i=0, i<= istogramma1->GetnbinsX(); i++) {
		if (istogramma1->GetnbinsX(i) !=0) {
			result+=pow((istogramma1->GetBinContent(i)-funzione->Eval(istogramma1->GetBinCenter((i))), 2)/isogramma->GetBinContent(i);
			ndf++;
		}
	}
	chi2 = result;
	ndf -= funzione->GetNpar();
	pvalue = TMath::Prob(chi2, ndf);
}
