#include <stdio.h>
#include <stdlib.h>

struct LISTA {
	int valor;
	// ponteiro
	struct LISTA *prox;
};

int main()
{
	struct LISTA *l;
	struct LISTA *novo;
	struct LISTA *fim;
	struct LISTA *aux;
	
	int qtd=0;
	char r='S';
	
	l=NULL;
	fim=NULL;
	while (r!='N'){
		novo = malloc(sizeof(struct LISTA));
		if (novo == NULL){
			printf("ERRO no malloc\n");
			break;
		}
		novo->prox=NULL;
		printf("Digite valor:\n");
		scanf("%d", &novo->valor);
		
		// coloca novo na lista
		if (l==NULL) {// lista vazia
			l = novo;
		} else {
			fim->prox = novo;
		}
		fim = novo;
		qtd = qtd+1;
		printf("Quer digitar mais um? (S/N)\n");
		do {
			r = getchar();
		} while ((r!='S')&&(r!='N'));
	}
	printf("Imprimindo %d valores\n", qtd);
	for (aux = l; aux != NULL; aux=aux->prox){
		printf("%d\n", aux->valor);
	}
	// Limpando mem
	while (l!=NULL){
		aux = l;
		l = aux->prox;
		free(aux);
	}
}
