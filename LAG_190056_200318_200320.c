/*
	Nome: Gabriel Bueno Machado Ribeiro RA:200320
	Nome: Gianluca Bueno Machado Ribeiro RA:200318
	Nome: Leonardo Poveda Mayoral RA: 190056
	Turma:CP004TIN1v
	
struct pontos
{
    
    float X;
    float Y;
}pontos;
  
pontos ponto;

*pp = &ponto
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Funções
void alocaFloat(float **pf,int tampf);
void alocaInt(int **pi,int tampi);
void receber_Parametros(int *qtd, float *pX,float *pY);
void receber_Ponto(int *pqtd,float *pXinter,float *pX);
void lagrange(int *pqtd,float *pX, float *pY, float *pXinter, float *pYinter, float *pLin);


int main(){
	int *qtd = NULL;
	float *X=NULL,*Y=NULL,*Xinter = NULL, *Yinter = NULL,*Lin= NULL;
	int escolha,escolha1;
	
	alocaInt(&qtd,3);
	alocaFloat(&X,3);
	alocaFloat(&Y,3);
	alocaFloat(&Xinter,3);
	alocaFloat(&Yinter,3);
	alocaFloat(&Lin,3);
	sleep(5);
	system("cls");
	printf("Metodo de Lagrange \n");
	do{
	
		printf("------------------------------------------------------------------------------------------------------------------------");
		receber_Parametros(qtd,X,Y);
		do{
			printf("------------------------------------------------------------------------------------------------------------------------");
			receber_Ponto(qtd,Xinter,X);	
			lagrange(qtd,X,Y,Xinter,Yinter,Lin);
			printf("------------------------------------------------------------------------------------------------------------------------");
			printf("\nDeseja Continuar:");
			printf("\nDigite 1 para Sim\n");
			printf("Digite 0 para Nao\n");
			printf("Escolha: ");
			scanf("%d",&escolha);
		
		}while(escolha == 1);
		
		printf("\n");
		printf("\nDeseja Encerrar:");
		printf("\nDigite 1 para Sim");
		printf("\nDigite 0 para Nao");
		printf("\nEscolha: ");
		scanf("%d",&escolha1);
		
	}while(escolha1 == 0);
	printf("\nObrigado por Utilizar");
}

void alocaFloat(float **pf, int tampf){
	if( (*pf=(float *)realloc(*pf,tampf*sizeof(float)) )==NULL)
	{
		printf("Erro na alocação!");
		exit(1);
	}
	printf("Espaco alocado com sucesso! End= %u\n",*pf);
}

void alocaInt(int **pi, int tampi){
	if( (*pi=(int *)realloc(*pi,tampi*sizeof(int)) )==NULL)
	{
		printf("Erro na alocação!");
		exit(1);
	}
	printf("Espaco alocado com sucesso! End= %u\n",*pi);
}

void receber_Parametros(int *pqtd, float *pX, float *pY){
	int i;
	printf("Quantidade de Pontos: ");
	scanf("%d",pqtd);
	printf("\nValores de X e Y\n");
	for(i=1;i<=*pqtd;i++){
		printf("\nValor do ponto x[%d]: ",i);
		scanf("%f",pX+i);
		printf("Valor do ponto f(x[%d]): ",i);
		scanf("%f",pY+i);	
	}	
}

void receber_Ponto(int *pqtd,float *pXinter, float *pX){
	int v;
	v = *pqtd;
	do{
		printf("\n\n\nPonto de Interpolacao: ");
		scanf("%f",pXinter);
	}while(*pXinter < *(pX+1) || *pXinter > *(pX+v));
}

void lagrange(int *pqtd,float *pX, float *pY, float *pXinter, float *pYinter, float *pLin){
	printf("------------------------------------------------------------------------------------------------------------------------");
	printf("++++++++++++++++++++++++++++++++++++++++++++ Resultados ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	int i,j;	
	*pYinter = 0;
	for(i = 1; i <=*pqtd; i++){
		*pLin= 1;
		for(j=1;j<=*pqtd;j++){
			if(i != j){
					*pLin = *pLin * ( ( (*pXinter) - (*(pX+j))) / ((*(pX+i)) - (*(pX+j))) );
			}		
		}
		printf("\nlinha[%d]: %.3f",i,*pLin);
		*pYinter = (*pYinter) + (*pLin) *  (*(pY+i));
	}
	
	printf("\n\nO ponto de %.3f eh em f(X): %.3f\n",*pXinter,*pYinter);
	
}

