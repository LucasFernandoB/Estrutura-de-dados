#include <stdio.h>
#include <stdlib.h>
#define MAX 2
struct Fila
{
    int item[MAX];
    int inicio,fim;
};
int Insere(struct  Fila *F,int X);
int Remove( struct Fila *F,int *X);
int main()
{
    int i,retorno,valor;
   struct Fila F1;
   // struct Fila F;
    F1.inicio=F1.fim=0;
    for(i=0; i<MAX; i++)
    {
        printf("\nDigite um numero inteiro : ");
        scanf("%d",&valor);
        retorno=Insere(&F1,valor);
        if(retorno==1)
             printf("Dado inserido !!!\n");
        else
            printf("Fila esta cheia !!!\n");
        getch();
    }
    for(i=0; i<MAX; i++)
    {
        retorno=Remove(&F1,&valor);
        if(retorno==1)
            printf( "\nRemovido: %d", valor);
        else
            printf("\nFila esta vazia !!!");
    }
    getch();
}

int Insere(struct  Fila *F,int X)
{

    if( (*F).fim==MAX)//fila cheia
        return 0;
    else
    {
        (*F).item[(*F).fim]=X;//insere o numero
        (*F).fim++;
        return 1;
    }
}

int Remove( struct Fila *F,int *X)
{
    int i;
    if((*F).inicio==(*F).fim)//fila vazia
        return 0;
    else
    {

        (*X)=(*F).item[(*F).inicio];
        for( i=0;i<MAX; i++)
            (*F).item[i]=(*F).item[i+1];
        (*F).fim--;
        return 1;
    }
}
