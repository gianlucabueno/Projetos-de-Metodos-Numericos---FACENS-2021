/*
	Nome: Gabriel Bueno Machado Ribeiro RA:200320
	Nome: Gianluca Bueno Machado Ribeiro RA:200318
	Nome: Leonardo Poveda Mayoral RA: 190056
	Turma:CP004TIN1

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

//Funções


void alocaFloat(float **pf,int tampf);
void alocaInt(int **pi,int tampi);


void receber_Parametros(int *pq, int *pc, int *pe, float *pa,float *pb,float *pp);


void resolver_media(float *pa, float *pb,float *pm);
void resolver_polinomio(float *px, float *pfx,int *pc,int *pe,int *pq);
void resolver_modulo(float *pv,float *pfm);


void mostrar_resultado(int *count,int *pi,float *pa,float *pm,float *pb,float *pfa,float *pfm,float *pfb,float *pp);


//Função Main
int main(void){
	
	int *coeficiente=NULL,*expoente = NULL,*quantidade = NULL, *i = NULL,*count = NULL;
	float *a=NULL,*b = NULL,*m = NULL,*precisao = NULL,*fa = NULL, *fb = NULL ,*fm = NULL,*verificacao = NULL;
	
	alocaInt(&quantidade,3);
	alocaInt(&coeficiente,3);
	alocaInt(&expoente,3);
	alocaFloat(&a,3);
	alocaFloat(&b,3);
    alocaFloat(&m,3);
    alocaFloat(&fa,3);
	alocaFloat(&fb,3);
    alocaFloat(&fm,3);
    alocaFloat(&precisao,3);
    alocaFloat(&verificacao,3);
    alocaInt(&i,3);
    alocaInt(&count,3);
    sleep(5);
    system("cls");
	printf("------------------------------------------------------------------------------------------------------------------------");
	printf("+++++++++++++++++++++++++++++++++++++++++ Metodo Dicotomia +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("------------------------------------------------------------------------------------------------------------------------\n\n\n\n");
	
	
	
	*i=0;
	*count=0;
	int j = 0;
	
	receber_Parametros(quantidade,coeficiente,expoente,a,b,precisao);
	
    
	do{
		if(j != 0){
			float ma,mb,va,vb,vm;
			va = *(fa+j);
			printf("va:%f\n",va);
			vm = *(fm+j);
			printf("vm:%f\n",vm);
			vb = *(fb+j);
			printf("vb:%f\n",vb);
			ma = va * vm;
			printf("ma:%f\n",ma);
			mb = vb * vm;
			printf("mb:%f\n",mb);
			if(	ma < 0 && mb > 0){
			
				*(a+j) = *a;
				//printf("a:%f\n",*(a+j));
				*(b+j) = *(m+(j-1));
				//printf("b:%f\n",*(b+j));
			}
			if(	ma > 0 && mb < 0){
			
				*(b+j) = *b;
				//printf("a:%f\n",*(a+j));
				*(a+j) = *(m+(j-1));
				//printf("b:%f\n",*(b+j));
			}
			
		}
		if(j == 0){
			*(a+j) = *a;
			//printf("a:%f\n",*(a+j));
			*(b+j) = *b;
			//printf("b:%f\n",*(b+j));
		}
		
		resolver_media(a+j,b+j,m+j);

		resolver_polinomio(a+j,fa+j,coeficiente,expoente,quantidade);

		resolver_polinomio(m+j,fm+j,coeficiente,expoente,quantidade);

		resolver_polinomio(b+j,fb+j,coeficiente,expoente,quantidade);

    	resolver_modulo(verificacao+j,fm+j);
    	*(i+j) = j;
		j++;
		
    	
	}while(*(verificacao+(j-1)) > *precisao);
	
    *count = *(i+j);
  
	mostrar_resultado(count,i,a,m,b,fa,fm,fb,precisao);
}



//Funções de Alocação
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



//Funções de Recebimento
void receber_Parametros(int *pq, int *pc, int *pe, float *pa,float *pb,float *pp){
	int i;
	printf("Digiete o tamanho do polinomio: ");
	fflush(stdin);
	scanf("%d",pq);
	for(i=0;i<*pq;i++){
		printf("Digite do Coeficiente de x: ");
		fflush(stdin);
		scanf("%i",pc+i);
		printf("Digite a elevacao de x: ");
		fflush(stdin);
		scanf("%i",pe+i);	
	}	
	printf("Digite o valor de a: ");
	fflush(stdin);
	scanf("%f",pa);
	printf("Digite o valor de b: ");
	fflush(stdin);
	scanf("%f",pb);
	printf("Digite o valor de Precisao: ");
	fflush(stdin);
	scanf("%f",pp);
	printf("\n\n\n");
}


//Funções Matematicas
void resolver_polinomio(float *px, float *pfx,int *pc,int *pe,int *pq){	
	int i;
	*pfx = 0;
	for(i=0;i<*pq;i++)
	{
		*pfx+= *(pc+i) * (pow(*px,*(pe+i)));
	}
}

void resolver_media(float *pa, float *pb,float *pm){
	
	*pm = (*pa + *pb)/2;
	
}

void resolver_modulo(float *pv,float *pfm){
	
	*pv = fabs(*pfm);
	
}


//Funções de Exibição
void mostrar_resultado(int *count, int *pi,float *pa,float *pm,float *pb,float *pfa,float *pfm,float *pfb,float *pp){
	int i,k;
	i=0;
	k = *count - 1;
	printf("------------------------------------------------------------------------------------------------------------------------");
	printf("++++++++++++++++++++++++++++++++++++++++++++ Resultados ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("------------------------------------------------------------------------------------------------------------------------");
	printf("     i          a          m          b         f(a)       f(m)        f(b)    \n");
	for(i=0;i <= k;i++){
		printf("    %.3i       %3.3f      %.3f      %.3f      %.3f     %.3f      %.3f   \n",*(pi+i),*(pa+i),*(pm+i),*(pb+i),*(pfa+i),*(pfm+i),*(pfb+i));
	}
	
	printf("\nA raiz da funcao e %.3f com erro de %.3f (%.3f)",*(pm+k),*(pfm+k),*pp);
}
