#ifndef ANALYZER_H
#define ANALYZER_H
#include <string>
#include <vector>
#include <fstream>
#include "TStyle.h"
#include "TH1D.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TF1.h"
#include "TMath.h"

using namespace std;

class analisi {
	public:
	//costruttore
	analisi();
	//distruttore
	~analisi();
	//funzione che legge i dati
	bool setData (const string data1, string conteggi);
	//calcolo momenti statistici
	void momenti (vector<double>* valori, vector<double>* errori, double* media, double* deviazione, double* errore_medio);
	//calcolo chi quadro
	void chi2(TF1* funzione, double& chi, int& NDF, double* pValue);
	//fit di dati
	void fit(TF1* funzione, double xmin, double xmax);
	//test di compatibilità
	bool testCompatibility (double& pvalue, double misura1, double errore1, double misura2, double errore2, double significance, string testType, double n1 = 1, double n2 = 1);
	//contorno del grafico
	TGraph* computeContour (TF1* myFun, double delta, unsigned int parA=0, unsigned int parB=1);
	
	TH1D* getHisto (void);
	TGraphErrors* getGraph (void);
	double getMeanX (void) { 
		return meanX_p;
	}
	double getMinX (void) { 
		return minX_p;
	}
	double getMaxX (void) { 
		return maxX_p;
	}
	double getStdDevX (void) { 
		return stdDevX_p;
	}
	double getMeanError (void) { 
		return meanError_p;
	}
	int getDataNumber (void) {
		return dataNumber_p;
	}
	vector<double>* getxMeas (void) { 
		return &xMeas_p;
	}
	vector<double>* getyMeas (void) { 
		return &yMeas_p;
	}
	vector<double>* getxErr (void) { 
		return &xErr_p;
	}
	vector<double>* getyErr (void) { 
		return &yErr_p;
	}

	// Data members
	private:	
	int dataNumber_p;
	double minX_p;
	double maxX_p;
	double meanX_p;
	double stdDevX_p;
	double meanError_p;
	vector<double> xMeas_p;
	vector<double> yMeas_p;
	vector<double> xErr_p;
	vector<double> yErr_p;
	TH1D* istogramma_p;
	TGraphErrors* grafico_p;
};

#endif
