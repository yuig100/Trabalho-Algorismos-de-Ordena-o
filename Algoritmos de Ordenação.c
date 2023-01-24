#include <stdio.h>
#include<stdlib.h>
#include <time.h>

//Insertion Sort
void insertionSort(int arr[], int n){ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 

//Selection Sort
void selection_sort(int num[], int tam) { 
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++) 
  {
     min = i;
     for (j = (i+1); j < tam; j++) {
       if(num[j] < num[min]) 
         min = j;
     }
     if (num[i] != num[min]) {
       aux = num[i];
       num[i] = num[min];
       num[min] = aux;
     }
  }
}

//Bubble Sort

void bubble_sort(int vet[], int max) {      
    int flag, i, aux;   
    
    do {
      flag = 0;
      for (i = 0; i < (max - 1); i++) {
   
   /* Verfica se o vetor está em ordem, no caso ele coloca em ordem crescente, para decrescente trocar '>' por '<' */
   if (vet[i] > vet[i+1]) {
     /* Caso não esteja, ordena */
     aux = vet[i];
     vet[i] = vet[i+1];
     vet[i+1] = aux;
     flag =1;
   }
      }
    /* Repete enquanto algum valor estiver fora de ordem */  
    } while (flag == 1);
    
  }

//Comb Sort
void combo_sort(int matriz[], int tamanho) 
{
	int i, j, intervalo, trocado = 1;
	int aux;
	intervalo = tamanho;
	while (intervalo > 1 || trocado == 1)
	{
		intervalo = intervalo * 10 / 13;
		if (intervalo == 9 || intervalo == 10) intervalo = 11;
		if (intervalo < 1) intervalo = 1;
		trocado = 0;
		for (i = 0, j = intervalo; j < tamanho; i++, j++)
		{
			if (matriz[i] > matriz[j])
			{
				aux = matriz[i];
				matriz[i] = matriz[j];
				matriz[j] = aux;
				trocado = 1;
			}
		}
	}
}

//Merge Sort
void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

//Quick Sort
void Quicks(int vetor[], int inicio, int fim){
   
   int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) Quicks(vetor, inicio, j);
   if(i < fim) Quicks(vetor, i, fim);   

}


//

int main(void){
	
	clock_t Ticks[2];
	FILE *ler;
	
	FILE *insertion;
	FILE *selection;
	FILE *bubble;
	FILE *combo;
	FILE *merge;
	FILE *Quick;
	
	int i,j,n=100000,q=100;
	int V[n];
	char name[40]="100k-100 vetores-aleatorio-1000.dat";
	
	insertion=fopen("insertionSort-100k-100 vetores-aleatorio-1000.dat","w");
	selection=fopen("selectionSort-100k-100 vetores-aleatorio-1000.dat","w");
	bubble=fopen("bubbleSort-100k-100 vetores-aleatorio-1000.dat","w");
	combo=fopen("comboSort-100k-100 vetores-aleatorio-1000.dat","w");
	merge=fopen("mergeSort-100k-100 vetores-aleatorio-1000.dat","w");
	Quick=fopen("QuickSort-100k-100 vetores-aleatorio-1000.dat","w");
	
	ler=fopen(name,"r");
	for(j=0;j<q;j++){
		for(i=0;i<n;i++){
			
		fscanf(ler,"%i",&V[i]);
			
		}
		
		Ticks[0] = clock();
		
		insertionSort(V,n);

		Ticks[1] = clock();
		
		double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
		
		fprintf(insertion,"O vetor %i demorou %g ms.\n",j+1,Tempo);
	}
	
	//
	
	ler=fopen(name,"r");
	for(j=0;j<q;j++){
		for(i=0;i<n;i++){
			
		fscanf(ler,"%i",&V[i]);
			
		}
		
		Ticks[0] = clock();
		
		selection_sort(V,n);
		
		Ticks[1] = clock();
		
		double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
		
		fprintf(selection,"O vetor %i demorou %g ms.\n",j+1,Tempo);
	}
	
	//
	
	ler=fopen(name,"r");
	for(j=0;j<q;j++){
		for(i=0;i<n;i++){
			
		fscanf(ler,"%i",&V[i]);
			
		}
		
		Ticks[0] = clock();
		
		bubble_sort(V,n);
	
		Ticks[1] = clock();
		
		double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
		
		fprintf(bubble,"O vetor %i demorou %g ms.\n",j+1,Tempo);
	}
	
	//
	
	ler=fopen(name,"r");
	for(j=0;j<q;j++){
		for(i=0;i<n;i++){
			
		fscanf(ler,"%i",&V[i]);
			
		}
		
		Ticks[0] = clock();
		
		combo_sort(V,n);
		
		Ticks[1] = clock();
		
		double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
		
		fprintf(combo,"O vetor %i demorou %g ms.\n",j+1,Tempo);
	}

	//
	
	ler=fopen(name,"r");
	for(j=0;j<q;j++){
		for(i=0;i<n;i++){
			
		fscanf(ler,"%i",&V[i]);
			
		}
		
		Ticks[0] = clock();
		
		mergeSort(V,0,n);
		
		Ticks[1] = clock();
		
		double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
		
		fprintf(merge,"O vetor %i demorou %g ms.\n",j+1,Tempo);
	}
	
	//
	
	ler=fopen(name,"r");
	for(j=0;j<q;j++){
		for(i=0;i<n;i++){
			
		fscanf(ler,"%i",&V[i]);
			
		}
		
		Ticks[0] = clock();
		
		Quicks(V,0,n);
		
		Ticks[1] = clock();
		
		double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
		
		fprintf(Quick,"O vetor %i demorou %g ms.\n",j+1,Tempo);
	}

    return 0;
}
