/* Andrea Viscardi 825551 */

#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#define K 50 /* numero di punti di cui si calcola il centro di massa */



/* con la seguente funzione e' possibile calcolare la distanza tra il
   punto i-esimo e il centro di massa */

float distanza (float a, float b, float c, float d) {

    float ris = 0;

    float de_x = a - b; /* de_x indica la variazione sulle x */

    float de_y = c - d; /* de_y indica la variazione sulle y */

    float x = de_x * de_x;  /* applicando il teorema di Pitagora... */

    float y = de_y * de_y;

    float m = x + y;

    ris = sqrt(m); /* ...si trova la distanza punto-centro di massa */

    return ris;

}

int main (int argc, char*argv[]) {

/* per contenere tutti i dati si utilizzano 3 vettori distinti di 
   lunghezza K: uno per le ascisse, uno per le ordinate e uno per 
   le masse dei punti */
	
	float X[K]; 

	float Y[K];   
 
	float Massa[K];

/* il numero reale s viene inserito dalla linea di comando del 
   terminale. Nel programma si richiama il valore di s, posto in 
   posizione 1, e con una printf si controlla che ad s venga assegnato 
   esattamente il valore inserito dall'utente */

	double s=atof(argv[1]);
	
	printf("il valore inserito di s e': %f\n", s);

/* si inizializzano quattro variabili che permettono al programma di 
   calcolare numeratore e denominatore della formula per il calcolo 
   delle coordinate del centro di massa */

	float num_x = 0; 

	float den_x = 0;

	float num_y = 0;

	float den_y = 0;

	int i = 0;

/* le coordinate e la massa di ogni singolo punto vengono inserite 
   nei tre vettori  con un ciclo while */

	while (i < K) {

		printf("inserisci x, y e massa del punto %d:\n", i);

		scanf("%f %f %f", &X[i], &Y[i], &Massa[i]);

		i++;

	}	

/* i seguenti cicli for permettono di spostarsi all'interno dei vari 
   array e calcolare al numeratore la sommatoria tra le ascisse e le 
   masse; al denominatore la sommatoria delle masse stesse */

	for (int i = 0; i < K; i++) {

		num_x = num_x + (X[i] * Massa[i]);

		den_x = den_x + Massa[i];

	}

	for (int i = 0; i < K; i++) {

		num_y = num_y + (Y[i] * Massa[i]);

		den_y = den_y + Massa[i];

	}	

/* le variabili x_cm e y_cm rappresentano le coordinate del centro di 
   massa che successivamente vengo stampate a video con una printf */

	float x_cm = num_x / den_x;	

	float y_cm = num_y / den_y;

	printf("l'ascissa del centro di massa e': %f\n", x_cm);	

	printf("l'ordinata del centro di massa e': %f\n", y_cm);

/* la variabile s, passata al programma dalla linea di comando, è un 
   numero reale che funge da distanza fissata dal centro di massa. 
   Per ogni valore di s il programma e' in grado di capire quanti  
   punti distano meno di s dal centro di massa. Si introduce quindi una 
   variabile dist e una variabile temporanea: quest'ultima opera 
   come contatore */

	float dist = 0;

	int tmp = 0;

/*il ciclo for permette ancora una volta di scorrere gli 
  array-coordinate dei K punti inseriti e di calcolarne la distanza
  dal centro di massa */

	for (int i = 0; i < K; i++) {

		dist = distanza(X[i], x_cm, Y[i], y_cm);

/* le istruzioni if ed else permettono di contare quanti punti distano 
   meno di s. Se la distanza e' inferiore il contatore subisce un 
   incremento unitario, in caso contrario il contatore rimane 
   uguale a se stesso */

		if(dist<s) {

			tmp++;

		}

		else {

			tmp = tmp;

		}

	}

/* la funzione finale di stampa illustra quanti punti soddisfano 
   la richiesta analizzata in precedenza dal ciclo if */

	printf("i punti con distanza inferiore ad s sono: %d\n", tmp);

	exit(EXIT_SUCCESS);

}