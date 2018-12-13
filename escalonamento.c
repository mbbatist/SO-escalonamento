#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define max  1000

double imprimir(int n[max])
{
	clock_t tic = clock();
	for (int i=0;i<max;i++)
	{
		printf("%d ",n[i]);	
	}
	clock_t toc = clock();
  	return (double)(toc - tic) / CLOCKS_PER_SEC;
}

double imprimir_srtn(int n[max])
{
	int atual=0;
	int prox=1;
	clock_t tic = clock();
	for (int i=0;i<max;i++)
	{
		if(n[atual]<=n[prox])
		{
			printf("%d ",n[atual]);
			atual=prox;
			prox++;
		}
		else
		{
			printf(" %d ",n[prox]);
			prox++;			
		}
	}
	clock_t toc = clock();
  	return (double)(toc - tic) / CLOCKS_PER_SEC;
}

int main()
{
	int i,aux;
	int M[max];
	double result_time[3];

	printf("****Simulação Impressao de Numeros****");
	
	for (int i=0;i<max;i++)
	{
		M[i]=rand()% max + 1;
	}
	printf("\n First­Come First­Served \n");
	result_time[0]=imprimir(M);
	
	printf(" \n Shortest Remaining Time Next \n ");
	result_time[1]=imprimir_srtn(M);

	printf(" \n Shortest Job First \n ");
	for (i=0;i<max;i++)
	{
		for (int j=i; j<=max;j++)
		{
			if(M[j]<M[i])
			{
				aux=M[i];
				M[i]=M[j];
				M[j]=aux;	
			}		
		}	
	}
	result_time[2]=imprimir(M);
	printf("\n _____TEMPOS DE EXECUCAO_____ \n");
	printf("FIFO:  %f \n",result_time[0]);
	printf("SRTN:: %f \n",result_time[1]);
	printf("SJF:   %f \n",result_time[2]);
	return 0;
}