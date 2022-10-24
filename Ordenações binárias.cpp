//Alunos: Caio Victor Silvério Sobral
//        Fabio Bentes Tavares de Melo Junior
#define Tam 100000
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h> 
using namespace std;
int inicio, fim;

int  n= Tam;
void BubbleSort(int *vet,int n)
{
printf("Calculando tempo da ordenacao em bubble sort...");
double time_spent = 0.0;
 
    clock_t begin = clock();
	int i, j, aux;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n-1-i; j++)
		{
			if(vet[j]>vet[j+1])
			{
				aux=vet[j];
				vet[j]=vet[j+1];
				vet[j+1]=aux;
			}
		}
	}
	clock_t end = clock();

time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

printf ("\n\n");
printf("TEMPO GASTO PARA ORDENACAO EM BUBBLESORT: %f segundos", time_spent);
printf ("\n\n"); 
printf ("\n\n");
}

void SelectionSort(int *vet,int n){ 
	printf("Calculando tempo da ordenacao em selection sort...");
double time_spent2 = 0.0;
 
    clock_t begin2 = clock(); 
    
    int i ,menorv ,aux;
    
    for(i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(vet[i]>vet[j])
            menorv=j;
        }
        if(i!=menorv){
            aux=vet[i];
            vet[i]=vet[menorv];
            vet[menorv]=aux;
        }
    }
    clock_t end2 = clock();

time_spent2 += (double)(end2 - begin2) / CLOCKS_PER_SEC;

 printf ("\n\n");
printf("TEMPO GASTO PARA ORDENACAO EM SELECTIONSORT: %f segundos", time_spent2);
printf ("\n\n"); 
printf ("\n\n");
}

void InsertionSort(int *vet, int n){
	printf("Calculando tempo da ordenacao em inserction sort...");
double time_spent3 = 0.0;
clock_t begin3 = clock();
 
int i, j , aux;
for(i = 1;i < n; i++){
	aux = vet[i];
	j=i-1;
	while((j>=0) && (aux< vet[j])){
		
		vet[j+1] = vet[j];
		j--;
	}
	vet[j+1]=aux;
}
clock_t end3 = clock();

time_spent3 += (double)(end3 - begin3) / CLOCKS_PER_SEC;

printf ("\n\n");
printf("TEMPO GASTO PARA ORDENACAO EM INSERTIONSORT: %f segundos", time_spent3);
printf ("\n\n"); 
printf ("\n\n");
}

void ShellSort(int *vet, int n){
	printf("Calculando tempo da ordenacao em Shell sort...");
double time_spent4 = 0.0;
clock_t begin4 = clock();
	int i,j,h,aux;
	h=1;
	while(h < n/3)
		h= 3 * h+1;
	while (h>0){
		for(i = h; i < n; i++){
			aux = vet[i];
			j = i;
			while(j >= h && aux < vet[j - h]){
				vet[j]= vet[j - h];
				j = j - h;
				
			}
			vet[j] = aux;
		}
		h = (h-1)/3;
	}
	clock_t end4 = clock();

time_spent4 += (double)(end4 - begin4) / CLOCKS_PER_SEC;

printf ("\n\n");
printf("TEMPO GASTO PARA ORDENACAO EM SHELLSORT: %f segundos", time_spent4);
printf ("\n\n"); 
printf ("\n\n");
}

void criaHeap(int *vet, int i, int f){

int aux = vet[i];
int j = i * 2 + 1;
while (j <= f){
	if(j < f){
		if(vet[j] < vet[j + 1]){
			j = j +1;
		}
	}
	if(aux < vet[j]){
		vet[i] = vet[j];
		i = j;
		j = 2 * i + 1;
	} else{
		j = f + 1;
	}
}
vet[i] = aux;	
}

void HeapSort(int *vet, int n){
	printf("Calculando tempo da ordenacao em heap sort...");
double time_spent = 0.0;
 
    clock_t begin = clock();
int i, aux;
for(i = (n - 1)/2; i > 0; i--){
	criaHeap(vet, i, n-1);
}	
for(i = n-1; i > 1; i--){
	aux = vet[0];
	vet[0] = vet [i];
	vet[i] = aux;
	criaHeap(vet, 0, i - 1);
}
clock_t end = clock();

time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

printf ("\n\n");
printf("TEMPO GASTO PARA ORDENACAO EM HEAPSORT: %f segundos", time_spent);
printf ("\n\n"); 
printf ("\n\n");
}
int i,tamanho;
void merge(int *v,int inicio,int meio,int fim){
	int *temp,p1,p2,i,j,k;
	int fim1 = 0,fim2=0;
	tamanho = fim - inicio + 1;
	p1=inicio;
	p2=meio+1;
	temp = (int *)malloc(tamanho*sizeof(int));
	if(temp != NULL){
		for(i=0;i<tamanho;i++){
			if(!fim1 && !fim2){
				if(v[p1]<v[p2])
					temp[i] = v[p1++];
				else
					temp[i] = v[p2++];
				if(p1>meio) fim1=1;
                if(p2>fim)  fim2=1;
			}
		    else{
				if(!fim1)
					temp[i]=v[p1++];
				else
					temp[i]=v[p2++];
			}	
		}
		for(j=0,k=inicio;j<tamanho;j++,k++)
				v[k]=temp[j];
	}
	free(temp);
}
void mergesort(int *v,int inicio,int fim){
	int meio;
    if(inicio<fim){
	    meio = floor((inicio+fim)/2);
        mergesort(v,inicio,meio);
	    mergesort(v,meio+1,fim);
	    merge(v,inicio,meio,fim);
	}
}

void trocar(int vetor[Tam],int i,int j){
	int aux;
	aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}
int particionar(int vetor[Tam],int inicio,int fim){
	int pivo,indice_pivo,i;
	pivo = vetor[fim];
	indice_pivo = inicio;
	for(i=inicio;i<fim;i++)
		if(vetor[i]<=pivo){
			trocar(vetor,i,indice_pivo);
			indice_pivo++;}
     trocar(vetor,indice_pivo,fim);
     return indice_pivo;
}
int particiona_random(int vetor[Tam], int inicio, int fim){
	int indice_pivo;
    indice_pivo = (rand() % (fim - inicio + 1)) + inicio;
	trocar(vetor,indice_pivo, fim);
	return particionar(vetor, inicio, fim);
}
int particiona(int *vetor,int inicio, int final){
	int esquerda,direita,pivo,aux;
	esquerda = inicio;
	direita = final;
	pivo = vetor[inicio];
	while(esquerda<direita){
	   while(vetor[esquerda]<=pivo)
	     	esquerda++;
	    while(vetor[direita]>pivo)
	    	direita--;
	    if(esquerda<direita){
			aux = vetor[esquerda];
			vetor[esquerda] = vetor[direita];
			vetor[direita] = aux;
		}
	}
	vetor[inicio] = vetor[direita];
	vetor[direita] = pivo;
	
	return direita;
}
void quickSort(int *vetor,int inicio, int fim){
	int pivo;
	if(fim>inicio){
		pivo = particiona(vetor,inicio,fim);
		quickSort(vetor,inicio,pivo-1);
		quickSort(vetor,pivo+1,fim);
	}
}

void copia(int *vetor, int *vetor2){
	for(int i = 0; i < n; i++)
	  	 vetor[i]= vetor2[i];
}

int main (void){
printf("gerando vetores de forma aleatoria...");
	printf ("\n\n");
	int i;
	int *vet,*vet2,j, k=0, igual;
 	vet = (int*)malloc(n * sizeof(int));
	vet2= (int*)malloc(n * sizeof(int));
	srand(time(NULL));
	do{
		vet[k] = rand() % (n * 3);
        igual=0;
	    for(j=0;j<k;j++)
	    	if(vet[j]==vet[k])
				igual = 1;
		if(igual==0)
			k++;
	}while(k<n);
copia(vet2,vet);
BubbleSort(vet, n);

copia(vet,vet2);

copia(vet,vet2);
SelectionSort(vet, n);


copia(vet,vet2);
	
InsertionSort(vet, n);

copia(vet,vet2);

ShellSort( vet, n);

copia(vet,vet2);
HeapSort(vet,n);

copia(vet,vet2);
printf("Calculando tempo da ordenacao em merge sort...");
double time_spent = 0.0;
clock_t begin = clock();
mergesort(vet, 0, Tam);
clock_t end = clock();

time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

printf ("\n\n");
printf("TEMPO GASTO PARA ORDENACAO EM MERGE: %f segundos", time_spent);
printf ("\n\n"); 
printf ("\n\n");
copia(vet,vet2);
printf("Calculando tempo da ordenacao em quick sort...");
double time_spent2 = 0.0;
clock_t begin2 = clock();
quickSort(vet,0,Tam);
clock_t end2 = clock();

time_spent2 += (double)(end2 - begin2) / CLOCKS_PER_SEC;

printf ("\n\n");
printf("TEMPO GASTO PARA ORDENACAO EM QUICKSORT: %f segundos", time_spent2);
printf ("\n\n"); 
printf ("\n\n");
return 0;
}
