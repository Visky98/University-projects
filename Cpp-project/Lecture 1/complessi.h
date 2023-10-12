#ifndef complesso_h
#define complesso_h

class complesso {

public:
	// costruttori
	complesso ();
	complesso (const double& reale, const double& immaginaria);
	complesso (const complesso& originale);
	// distruttori
	~complesso ();
	// Operator overloads
	complesso& operator= (const complesso& originale);
	complesso& operator= (const double& originale);
	complesso operator+ (const complesso& originale);
	complesso operator- (const complesso& originale);
	complesso operator* (const complesso& originale);
	complesso operator/ (const complesso& originale);
	complesso operator^ (const int& potenza); 
	// funzioni
	double reale() const;
 	double immaginaria() const;
 	double rho() const;
 	double theta() const;
 	void stampa() const;
	// dati
	private:
 	double reale_p;
 	double immaginaria_p;
};

#endif
