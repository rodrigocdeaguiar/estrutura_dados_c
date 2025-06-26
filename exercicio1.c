/*Exerc�cio 1 - Cria��o e Impress�o de Lista Simplesmente Encadeada
Descri��o:
Implemente uma estrutura de lista simplesmente encadeada que armazene n�meros inteiros.
O programa dever� permitir que o usu�rio insira N n�meros e, ao final, imprima todos os elementos da lista.

Tarefas:
- Criar a estrutura da lista.
- Implementar a inser��o no final da lista.
- Implementar a fun��o de impress�o da lista.
*/


#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct NUMERO{
	int num;
	struct NUMERO *prox;
};

void criaLista(struct NUMERO **inicio, struct NUMERO **fim){
	struct NUMERO *aux;
	char resp = 's';
	
	if (*inicio!=NULL){
		printf("Lista j� criada!\n");
		return;
	}
	
	while(resp=='s'||resp=='S'){
		
		aux = (struct NUMERO*)malloc(sizeof(struct NUMERO));
	
		if(aux==NULL){
			printf("Erro ao alocar mem�ria!\n");
			return;
		}
		
		printf("Digite um n�mero inteiro:\n");
		scanf("%i", &aux->num);
		aux->prox = NULL;
		if(*inicio==NULL){
			*inicio = aux;
			*fim = aux;
		}else{
			(*fim)->prox = aux;
			*fim = aux;
			
		}
		do{
			getchar();
			printf("Deseja digitar outro n�mero? (S/N)\n");
			scanf("%c", &resp);
		}while(resp!='s'&&resp!='S'&&resp!='n'&&resp!='N');
	}
}


void insereNumero(struct NUMERO **inicio, struct NUMERO **fim){
	struct NUMERO *aux;
	char resp = 's';
	
	if(*inicio==NULL){
		printf("Lista ainda n�o criada!\n");
		return;
	}
	
	while(resp=='s'||resp=='S'){
			aux = (struct NUMERO*)malloc(sizeof(struct NUMERO));
        	if (aux == NULL) {
	            printf("Erro ao alocar mem�ria!\n");
	            return;
        	}
			printf("Digite um n�mero inteiro:\n");
			scanf("%i", &aux->num);
			aux->prox = NULL;
			(*fim)->prox = aux;
			*fim = aux;
			do{
				printf("Deseja digitar outro n�mero? (S/N)\n");
				getchar();
				scanf("%c", &resp);
			}while(resp!='s'&&resp!='S'&&resp!='n'&&resp!='N');		
		}
	}

void imprimeLista(struct NUMERO *inicio){
	struct NUMERO *aux = inicio;
	
	
	if (inicio==NULL){
		printf("A lista est� vazia!\n");
		return;
	}
	
		
	printf("N�meros inteiros da lista encadeada: ");
	
	while(aux!=NULL){
		printf("%i ", aux->num);
		aux = aux->prox;
	}
	printf("\n");
}

void limpaLista(struct NUMERO **inicio, struct NUMERO **fim){
	struct NUMERO *aux;
	struct NUMERO *prox; 
	
	aux = *inicio;
	while (aux != NULL) {
	    struct NUMERO *prox = aux->prox;
	    free(aux);
	    aux = prox;
    }

    *inicio = NULL;
    *fim = NULL;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	struct NUMERO *num = NULL;
	struct NUMERO *fim = NULL;
	int menu;
	
	printf("______PROGRAMA PARA CADASTRO DE N�MEROS EM UMA LISTA ENCADEADA______\n");
	
	do{
		printf("SELECIONE O MENU DESEJADO:\n");
		printf("1 - Criar lista e inserir novos n�meros\n");
		printf("2 - Inserir novos n�meros em uma lista que j� foi criada\n");
		printf("3 - Imprimir a lista encadeada\n");
		printf("4 - Sair do menu e limpar a lista\n");
		printf("\n");
		scanf("%i", &menu);
		getchar();
		switch(menu){
			case 1:
				criaLista(&num, &fim);
				break;
			case 2:
				insereNumero(&num, &fim);
				break;
			case 3:
				imprimeLista(num);
				break;
			case 4:
				limpaLista(&num, &fim);
				break;
			default:
				printf("Op��o inv�lida.\n");
            	continue;
		}
	}while(menu!=4);
	return 0;
}

