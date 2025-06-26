#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct ALUNOS{
	int matricula;
	float g1, g2, media;
	struct ALUNOS *proxAluno;
};

void cadastraAlunos(struct ALUNOS **aluno, struct ALUNOS **fim, int quantidade){
	char resp = 'S';
	struct ALUNOS *novo;
	while(resp!='N'){
		novo = malloc(sizeof(struct ALUNOS));
				printf("Digite a matrícula do estudante %i:\n", quantidade+1);
		scanf("%d", &novo->matricula);
		do{
			printf("Digite a nota G1 do estudante %i:\n", quantidade+1);
			scanf("%f", &novo->g1);
		}while((novo->g1<0)||(novo->g1>10));
		do{
			printf("Digite a nota G2 do estudante %i:\n", quantidade+1);
			scanf("%f", &novo->g2);
		}while((novo->g2<0)||(novo->g2>10));
		novo->media = (novo->g1+novo->g2)/2;
		novo->proxAluno = NULL;
		if(*aluno==NULL){
			*aluno=novo;
		}else{
			(*fim)->proxAluno = novo;
		}
		*fim = novo;
		quantidade++;
		printf("Deseja cadastrar outro estudante (S/N)?\n");
		getchar();
		do{
			scanf(" %c", &resp);
		}while((resp!='S')&&(resp!='N'));
	}
	printf("\n");
	printf("\n");
}

void imprimeAlunoMaiorMedia(struct ALUNOS **aluno){
	printf("_____IMPRIMINDO ESTUDANTE COM MAIOR MÉDIA_____\n");
		struct ALUNOS *aux = (*aluno);
		int maiorMatricula;
		float maiorMedia, maiorG1, maiorG2;
		if(*aluno == NULL){
    	printf("Lista vazia! Nenhum aluno cadastrado.\n");
    	return;
		}
		maiorMatricula = (*aluno)->matricula;
		maiorG1 = (*aluno)->g1;
		maiorG2 = (*aluno)->g2;
		maiorMedia = (*aluno)->media;
		for (aux = *aluno; aux != NULL; aux=aux->proxAluno){
			if(maiorMedia<aux->media){
				maiorMatricula = aux->matricula;
				maiorG1 = aux->g1;
				maiorG2 = aux->g2;
				maiorMedia = aux->media;
			}
		}
		printf("Matrícula: %d\n", maiorMatricula);
		printf("G1: %.1f\n", maiorG1);
		printf("G2: %.1f\n", maiorG2);
		printf("Média: %.1f\n", maiorMedia);
		printf("_______________________________\n");
		printf("\n");
		printf("\n");
}
		
void alunosSubstituicao(struct ALUNOS **aluno){
	printf("_____IMPRIMINDO ESTUDANTE QUE PRECISAM DE SUBSTITUIÇÃO_____\n");
	struct ALUNOS *aux;
	if(*aluno == NULL){
    	printf("Lista vazia! Nenhum aluno cadastrado.\n");
    	return;
	}
	aux = *aluno;
	while(aux != NULL){
			if(aux->media<6){
				printf("--------------------------------------------\n");
				printf("Matrícula: %d\n", aux->matricula);
				printf("G1: %.1f\n", aux->g1);
				printf("G2: %.1f\n", aux->g2);
				printf("Média: %.1f\n", aux->media);
			}
		aux = aux->proxAluno;
		}
	printf("\n");
	printf("\n");
}
	
void ordenaEstudantesPorMedia(struct ALUNOS **aluno){
	struct ALUNOS *atual;
	struct ALUNOS *proximo;
	int troca, tempMatricula;
	float tempG1, tempG2, tempMedia;
	if(*aluno == NULL){
    	printf("Lista vazia! Nenhum aluno cadastrado.\n");
    	return;
	}
	do{
		troca = 0;
		atual = *aluno;
		proximo = atual->proxAluno;
		while(proximo!=NULL){
			if(atual->media>proximo->media){
				tempMatricula = atual->matricula;
				tempG1 = atual->g1;
				tempG2 = atual->g2;
				tempMedia = atual->media;
				atual->matricula = proximo->matricula;
				atual->g1 = proximo->g1;
				atual->g2 = proximo->g2;
				atual->media = proximo->media;
				proximo->matricula = tempMatricula;
				proximo->g1 = tempG1;
				proximo->g2 = tempG2;
				proximo->media = tempMedia;
				troca = 1;
			}
		atual = atual->proxAluno;
		proximo = proximo->proxAluno;
		}
	}while(troca);
	printf("--------------------------------------------\n");
	printf("Lista ordenada com sucesso\n");
	printf("\n");
	printf("\n");
}

void imprimeLista(struct ALUNOS **aluno){
	struct ALUNOS *aux;
	printf("______IMPRIMINDO A LISTA DOS ESTUDANTES ORDENADA POR MÉDIA______\n");
	if(*aluno == NULL){
    	printf("Lista vazia! Nenhum aluno cadastrado.\n");
    	return;
	}
	for(aux=*aluno; aux!=NULL; aux = aux->proxAluno){
		printf("--------------------------------------------\n");
		printf("Matrícula: %d\n", aux->matricula);
		printf("G1: %.1f\n", aux->g1);
		printf("G2: %.1f\n", aux->g2);
		printf("Média: %.1f\n", aux->media);
	}
	printf("\n");
	printf("\n");
}

void limpaLista(struct ALUNOS **aluno){
	struct ALUNOS *aux;
	if(*aluno == NULL){
    	printf("Lista vazia! Nenhum aluno cadastrado.\n");
    	return;
	}
	while(*aluno != NULL){
		aux = *aluno;
		*aluno = (*aluno)->proxAluno;
		free(aux);
	}
	printf("Lista liberada com sucesso!\n");
}


int main(){
	setlocale(LC_ALL, "Portuguese");
	int quantidade=0;
	
	struct ALUNOS *aluno = NULL;
	struct ALUNOS *fim = NULL;

	
	cadastraAlunos(&aluno, &fim, quantidade);
	imprimeAlunoMaiorMedia(&aluno);
	alunosSubstituicao(&aluno);
	ordenaEstudantesPorMedia(&aluno);
	imprimeLista(&aluno);
	limpaLista(&aluno);
	
	
	return 0;
	}
