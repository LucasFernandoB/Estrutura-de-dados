#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Fila{
	int item[MAX];
	int inicio,fim;
};



void Inicia(struct Fila *F){
	(*F).inicio=0;
	(*F).fim=0;
}

int enqueue(struct Fila *F,int X){
	if((*F).fim==MAX)
		return 0;
	else{
		(*F).item[(*F).fim]=X;
		(*F).fim= (*F).fim+1;
	return 1;
	}
}

int dequeue(struct Fila *F,int *X){
	if((*F).inicio==(*F).fim)
		return 0;
	else{
		*X=(*F).item[(*F).inicio];
		(*F).inicio=(*F).inicio+1;
		return 1;
	}
}

int main(){
	struct Fila F1;
	int i,retorno,valor;
	Inicia(&F1);

	for(i=0;i<MAX;i++){
		printf("\nDigite um numero inteiro : ");
		scanf ("%d",&valor);
		retorno=enqueue(&F1,valor);
		if(retorno==1)
			printf("Dado inserido !!!\n");
		else
			printf("Fila esta cheia !!!\n");
	}

	for(i=0;i<MAX;i++){
		retorno=dequeue(&F1,&valor);
		if(retorno==1)
			printf("\nRemovido: ", valor);
		else
		printf("\nFila esta vazia !!!");
	}
	return 0;
}
