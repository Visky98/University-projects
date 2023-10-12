#ifndef simplearray_h
#define simplearray_h

template <class T>
class simplearray {
	public:
		//costruttore di default
		simplearray() {
			numero_el_p=0;
			elementi_p=NULL;
		}
		//costruttore
		simplearray(const int& numero_el) {
			numero_el_p=numero_el;
			if (numero_el_p!=0) {
				elementi_p=new T[numero_el];
			}
			else elementi_p=NULL;
		}
		//costruttore di copia
		simplearray(const simplearray& original) {
			numero_el_p=original.numero_el_p;
			if (numero_el_p!=0) {
				elementi_p=new T[numero_el_p];
				for (int i=0; i<numero_el_p; i++) {
					elementi_p[i]=original.elementi_p[i];
				}
			}
			else elementi_p=NULL;
		}
		//distruttore
		~simplearray() {
			delete[] elementi_p;
		}
		//visualizza gli elementi dell'array
		T& elemento(const int& i) {
			if(i<numero_el_p) {
				return elementi_p[i];
			}
			else {
				return elementi_p[i-1];
			}
		}
		//overloading operator[]
		T& operator[](const int& i) {
			if (i < numero_el_p) {
				return elementi_p[i];
			}
			else {
				return elementi_p[numero_el_p-1];
			}
		}
		//lunghezza del vettore
		int lunghezza() {
			return numero_el_p;
		}
		//funzione push
		void push(const T& elem) {
			numero_el_p++;
			T* nuovo=new T[numero_el_p];
			for (int i=0; i<(numero_el_p-1); i++) {
				nuovo[i]=elementi_p[i]; //creo nuovo vettore ma con un posto in più
			}
                        nuovo[numero_el_p-1]=elem;
			elementi_p=nuovo;
			//delete [] nuovo; //cancello il vecchio vettore			
		}
		//funzione pop
		T pop (int i) {
			if (i<numero_el_p) {
				T elem=elementi_p[i];
				numero_el_p--;
				T* nuovo=new T[numero_el_p];
				int j=0;
				while (j<i) {
					nuovo[j]=elementi_p[j];
				}
				for (j>i; j<(numero_el_p+1); j++) {
					nuovo[j-1]=elementi_p[j];
				}
				nuovo=elementi_p;
				delete [] elementi_p;
			}
			else {
				std::cout << "ERRORE! Procedimento impossibile " << std::endl;
			}
		}		
	private:
		int numero_el_p;
		T* elementi_p;
};

#endif
