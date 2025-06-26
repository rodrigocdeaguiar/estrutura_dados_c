/*Entre em um grupo. Use a conversa aqui no lex para combinar os grupos.
No in�cio do c�digo, NECESSARIAMENTE, como coment�rio, devem constar:
Matricula, nome e email de todos os integrantes do grupo
Uma pequena linha ou par�grafo para cada um dos integrantes contando qual a contribui��o deste no trabalho (aceito logs do commit)
O c�digo fonte que n�o tiver estes coment�rios n�o ser� avaliado.

Considere os seguintes dados de alunos:

numero de matricula
nota da g1
nota da g2
media
Programe, em C, uma pilha usando vetor. Veja que uma pilha � uma lista linear para a qual se aplica o crit�rio LIFO.
No caso de ser vetor, esta pilha ter� um limite superior (tamanho do vetor). Pergunte ao usu�rio este limite e aloque dinamicamente a pilha.
Implemente as fun��es empty(), pop() e push() para esta pilha.
Fa�a o cadastro dos alunos sempre usando empilhar.
Implemente uma busca pela matricula respeitando o jeito LIFO de ser.

Nome: Rodrigo Costa de Aguiar
Matr�cula: 202021039
E-mail: rodrigo.202021039@unilasalle.edu.br
*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct ALUNOS{
	int matricula;
	float g1, g2, media;
};

void empty(int topo){
	if(topo==-1){
		printf("A pilha de dados est� vazia! Nenhum aluno cadastrado!\n");
		system("pause");
		system("cls");
	}else{
		printf("Existe pelo menos um aluno cadastrado na lista!\n");
		system("pause");
		system("cls");
	}
}

void push(int *topo, int tamVetor, struct ALUNOS *lista){
	if(*topo+1==tamVetor){
		printf("Lista cheia!\n");
		printf("\n");
		system("pause");
		system("cls");
		return;
	}else{
		(*topo)++;
		printf("Digite o n�mero de matr�cula do aluno %i:\n", *topo);
		scanf("%i", &lista[*topo].matricula);
		do{
			printf("Digite a nota da G1 do aluno %i:\n", *topo);
			scanf("%f", &lista[*topo].g1);
		}while(lista[*topo].g1<0||lista[*topo].g1>10);
		do{
			printf("Digite a nota da G2 do aluno %i:\n", *topo);
			scanf("%f", &lista[*topo].g2);
		}while(lista[*topo].g2<0||lista[*topo].g2>10);		
		lista[*topo].media= ((lista[*topo].g1+lista[*topo].g2)/2);
		printf("\n");
		printf("Aluno inserido no topo com sucesso!\n");
		printf("\n");
		system("pause");
		system("cls");
	}	
}

void pop(int *topo, int tamVetor, struct ALUNOS *lista){
	if(*topo==-1){
		printf("Lista Vazia! N�o � poss�vel excluir nenhum aluno da pilha!\n");
		printf("\n");
		system("pause");
		system("cls");
		return;
	}else{
		printf("ESTUDANTE QUE EST� SENDO REMOVIDO DA PILHA: \n");
		printf("Posi��o: %i\n", *topo);
		printf("Matr�cula: %i\n", lista[*topo].matricula);
		printf("G1: %.1f\n", lista[*topo].g1);
		printf("G2: %.1f\n", lista[*topo].g2);
		printf("M�dia: %.1f\n", lista[*topo].media);
		lista[*topo].matricula = 0;
		lista[*topo].g1 = 0;
		lista[*topo].g2 = 0;
		lista[*topo].media = 0;
		(*topo)--;
		printf("Aluno do topo removido com sucesso!\n");
		printf("\n");
		system("pause");
		system("cls");
	}
}

void consultaMatricula(int *topo, int tamVetor, struct ALUNOS *lista){
	int i, matriculaCons, encontrado = 0;
	if(*topo==-1){
		printf("A pilha de alunos est� vazia! Nenhum aluno pode ser encontrado!\n");
		printf("\n");
		system("pause");
		system("cls");
		return;
	}else{
		do{
		printf("Digite o n�mero de matr�cula que ser� consultado:\n");
		scanf("%i", &matriculaCons);
		printf("\n");
		}while(matriculaCons<0);
		for(i=*topo; i>=0; i--){
			if(matriculaCons==lista[i].matricula){
				printf("ALUNO ENCONTRADO!\n");
				printf("Posi��o: %i\n", i);
				printf("Matr�cula: %i\n", lista[i].matricula);
				printf("G1: %.1f\n", lista[i].g1);
				printf("G2: %.1f\n", lista[i].g2);
				printf("M�dia: %.1f\n", lista[i].media);
				encontrado = 1;
				printf("\n");
				system("pause");
				system("cls");
				break;
			}
		}
		if(encontrado==0){
			printf("Nenhum aluno encontrado na pilha com essa matr�cula!\n");
			printf("\n");
			system("pause");
			system("cls");
		}
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int topo = -1, tamVetor, resp, i;
	struct ALUNOS *listaAlunos;
	printf("_______SISTEMA DE CADASTRO DE ALUNOS USANDO PILHAS DE DADOS_______\n");
	printf("Digite a quantidade de alunos que ser�o cadastrados:\n");
	scanf("%d", &tamVetor);
	if(tamVetor<1){
		printf("Quantidade inv�lida! Programa encerrado!");
		return 1;
	}
	system("cls");
	listaAlunos = malloc(tamVetor*sizeof(struct ALUNOS));
	if(listaAlunos==NULL){
		printf("N�o foi poss�vel alocar mem�ria para a lista!\n");
		return 1;
	}
	do{
		printf("DIGITE A OP��O DESEJADA:\n");
		printf("1 - Verificar se a lista est� vazia\n");
		printf("2 - Inserir aluno na pilha\n");
		printf("3 - Remover o aluno do topo da pilha\n");
		printf("4 - Consultar estudante pelo n�mero de matr�cula\n");
		printf("0 - Sair:\n");
		scanf("%d", &resp);
		system("cls");
		switch(resp){
			case 0:
				break;
			case 1:
				empty(topo);
				break;
			case 2:
				push(&topo, tamVetor, listaAlunos);
				break;
			case 3:
				pop(&topo, tamVetor, listaAlunos);
				break;
			case 4:
				consultaMatricula(&topo, tamVetor, listaAlunos);
				break;
			default:
				printf("Op��o inv�lida.\n");
            	break;
		}
	}while(resp!=0);
	free(listaAlunos);
	return 0;
}
	
