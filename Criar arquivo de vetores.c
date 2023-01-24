#include <stdio.h>

main(){
	
	srand(time(NULL)); 
	FILE *arq;
	arq=fopen("100k-100 vetores-aleatorio-1000.dat","w");
	
	int i,j,n,a,q;
	
	q=100;
	n=100000;
	a=1000;
	
	for(i=0;i<q;i++){
		for(j=0;j<n;j++){
			
			fprintf(arq,"%i ",rand() % a);
	
		}
		fprintf(arq,"\n");
	}
	fclose(arq);
}
