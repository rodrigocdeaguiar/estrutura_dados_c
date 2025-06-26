#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct{
	int matricula;
	float g1, g2, media;
}ALUNOS;

void cadastraAluno(ALUNOS *listaEstudantes, int numAlunos){
	int i;
	printf("_________SISTEMA DE CADASTRO DE ESTUDANTES_________\n");
	for(i=0;i<numAlunos; i++){
		printf("Digite a matricula do aluno %i de %i:\n", i + 1, numAlunos);
		scanf("%d", &listaEstudantes[i].matricula);
		fflush(stdin);
		do{
			printf("Digite a nota do grau 1 do aluno %i de %i:\n", i + 1, numAlunos);
			scanf("%f", &listaEstudantes[i].g1);
			fflush(stdin);
		}while(listaEstudantes[i].g1<0||listaEstudantes[i].g1>10);
		do{
			printf("Digite a nota do grau 2 do aluno %i de %i:\n", i + 1, numAlunos);
			scanf("%f", &listaEstudantes[i].g2);
			fflush(stdin);
		}while(listaEstudantes[i].g2<0||listaEstudantes[i].g2>10);
		listaEstudantes[i].media = (listaEstudantes[i].g1 + listaEstudantes[i].g2) / 2;
		system("cls");
	}
}

void imprimeMaiorMedia(ALUNOS *listaEstudantes, int numAlunos){
	int i, indiceMaiorMedia=0;
	float maiorMedia = listaEstudantes[0].media;
	for(i=0; i<numAlunos;i++){
		if(listaEstudantes[i].media>maiorMedia){
			maiorMedia = listaEstudantes[i].media;
			indiceMaiorMedia = i;
		}
	}
	printf("_____ESTUDANTE COM A MAIOR MÉDIA_____\n");
	printf("Número de matrícula: %i\n", listaEstudantes[indiceMaiorMedia].matricula);
	printf("Média: %.1f\n", listaEstudantes[indiceMaiorMedia].media);
}

void substituicao(ALUNOS *listaEstudantes, int numAlunos){
	int i;
	printf("____LISTA DE ESTUDANTES QUE PRECISARÃO REALIZAR A SUBSTITUIÇÃO______\n");
	for(i=0; i<numAlunos; i++){
		if(listaEstudantes[i].media<6){
			printf("Matricula: %i\n", listaEstudantes[i].matricula);
			printf("Média: %.1f\n", listaEstudantes[i].media);
		}
	}
}

void ordenaEstudantes(ALUNOS *listaEstudantes, int numAlunos){
	int i, j, tempMat;
	float tempG1, tempG2, tempMedia;
	for(i=0;i<numAlunos;i++){
		for(j=i+1;j<numAlunos;j++){
			if(listaEstudantes[i].media>listaEstudantes[j].media){
				tempMat = listaEstudantes[i].matricula;
				tempG1 = listaEstudantes[i].g1;
				tempG2 = listaEstudantes[i].g2;
				tempMedia = listaEstudantes[i].media;
				listaEstudantes[i].matricula = listaEstudantes[j].matricula;
				listaEstudantes[i].g1 = listaEstudantes[j].g1;
				listaEstudantes[i].g2 = listaEstudantes[j].g2;
				listaEstudantes[i].media = listaEstudantes[j].media;
				listaEstudantes[j].matricula = tempMat;
				listaEstudantes[j].g1 = tempG1;
				listaEstudantes[j].g2 = tempG2;
				listaEstudantes[j].media = tempMedia;
			}
		}
	}	
}

void imprimeEstudantes(ALUNOS *listaEstudantes, int numAlunos){
	int i;
	printf("________IMPRIMINDO ESTUDANTES ORDENADOS POR MÉDIA_________\n");
	for(i=0;i<numAlunos;i++){
		printf("Matrícula: %i\n", listaEstudantes[i].matricula);
		printf("Média final: %.1f\n", listaEstudantes[i].media);
	}
	
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int qtde;
	printf("\nDigite o número de estudantes que você quer cadastrar: ");
	scanf("%i", &qtde);
	ALUNOS *estudantes = malloc(qtde*sizeof(ALUNOS));
	if(estudantes==NULL){
		printf("\nErro ao alocar memória!!!!");
		return 1;
	}
	system("cls");
	cadastraAluno(estudantes, qtde);
	imprimeMaiorMedia(estudantes, qtde);
	substituicao(estudantes, qtde);
	ordenaEstudantes(estudantes, qtde);
	imprimeEstudantes(estudantes, qtde);
	free(estudantes);
}
