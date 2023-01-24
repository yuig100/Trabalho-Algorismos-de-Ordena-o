#include <stdio.h>
#include <time.h>
#include <windows.h>

main(){
	
	FILE *arq;
	
	arq=fopen("10k-100 vetores-aleatorio-1000.dat","r");
	
	int i,n,j,q;
	
	n=10;
	q=5;
	
	int V[n];
	
	LARGE_INTEGER inicio, fim, freq;
	
	double gasto;
	QueryPerformanceCounter( &inicio );
	
	for(i=0;i<q;i++){
		for(j=0;j<n;j++){
			
			fscanf(arq,"%i",&V[j]);
			printf("%i-",V[j]);
		}
		printf("\n");
	}
	
	QueryPerformanceCounter( &fim );
	
	float tempo_total = (float)( fim.QuadPart - inicio.QuadPart ) / freq.QuadPart;
	
	printf( "%f\n", tempo_total );

	fclose(arq);
	
}
