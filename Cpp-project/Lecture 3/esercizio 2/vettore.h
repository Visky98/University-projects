#ifndef vettore_H
#define vettore_H

class vettore {
	public:
  		// costruttore di default
  		vettore ();
  		vettore (double x, double y);
  		// costruttore di copia
  		vettore (const vettore &originale);
		// Operatore
  		vettore& operator= (const vettore& originale);
  		vettore operator+ (const vettore& vettore2);
  		vettore operator- (const vettore& vettore2);
		// funzioni
		double prodotto (double k); // moltiplicazione di un vettore per uno scalare
  		double modulo(); // Modulo del vettore
  		void   print();
		// Metodo che rinormalizza il vettore a 1
  		void   norma();         
  		double getx();
 		double gety();	
		// Data members
	private:
  		double x_p;
  		double y_p;
};

#endif

