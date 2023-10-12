#include "analisi.h"

analisi::analisi() {
	dataNumber_p = 0;
	minX_p = 0;
	maxX_p = 0;
	meanX_p = 0;
	stdDevX_p = 0;
	xmeas_p.clear();
	ymeas_p.clear();
	xErr_p.clear();
	yErr_p.clear();
	histo_p = NULL;
	graph_p = NULL;	
}

analisi::~analisi() {
	delete histo_p;
	delete graph_p;	
}

bool analisi::setData (const string data1, string conteggi) {
	ifstream inFile(data1.c_str());
	if (inFile.good==false) {
		cout << "Errore nell'apertura del fili di dati" << endl;
		return false;
	}
	double x=0, y=0, xErr=0, yErr=0, larghezzax=0, larghezzay=0, varx=0, vary=0;
	int n=0;
	while(true) {
		if(type=="counts") {
			inFile >> x;
		}
		else if (type=="measurements") {
			inFile >> x >> y >> xErr >> yErr;
		}
		else {
			return false;
		}
	}
}
