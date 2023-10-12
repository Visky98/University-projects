#include <stdio.h>
#include <stdlib.h>

struct nodo_lista {
	int valore;
	struct nodo_lista *prox;
};

typedef struct nodo_lista nodo;
nodo*riempi_nodo(int a) {
	nodo*nuovo_nodo;
	nuovo_nodo=(nodo*) malloc(sizeof(nodo));
	if(nuovo_nodo==NULL) {
	exit(EXIT_FAILURE);
	}
	nuovo_nodo->valore=a;
	return nuovo_nodo;
}

int main () {
	nodo*testa=NULL;
	int valore_letto=1;
	while(valore_letto!=0) {
		printf("inserisci un valore:\n");
		scanf("%d", &valore_letto);
		nodo*nuovo_nodo=riempi_nodo(valore_letto);
		nuovo_nodo->prox=testa; /*oppure (*nuovo_nodo).prox=testa;*/
		testa=nuovo_nodo;
	}
	nodo*nodo_corrente=testa;
	while(nodo_corrente!=NULL) {
		printf("%d ", nodo_corrente->valore);
		nodo_corrente=nodo_corrente->prox;
	}
	printf("\n");
	exit(EXIT_SUCCESS);
}
