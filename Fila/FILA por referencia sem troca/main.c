#include <stdio.h>
#include <stdlib.h>
#define MAX 2
struct Fila
{
    int item[MAX];
    int inicio,fim;
} ;

void main(void)
{
    struct Fila F1;
    int i,retorno,valor;
    F1.inicio=F1.fim=0;
    for(i=0; i<MAX; i++)
    {
        printf( "\nDigite um numero inteiro : ");
        scanf( "%d",&valor);
        retorno=Insere(&F1,valor);
        if(retorno==1)
            printf( "Dado inserido !!!\n");
        else
            printf( "Fila esta cheia !!!\n");
        getch();
    }
    for(i=0; i<MAX; i++)
    {
        retorno=Remove(&F1,&valor);
        if(retorno==1)
           printf("\nRemovido: %d", valor);
        else
            printf( "\nFila esta vazia !!!");
    }
    getch();
}

//----------Função para inserir dados na Fila
int Insere( struct Fila *F,int X)
{
    if((*F).fim==MAX)
        return 0;
    else
    {
        (*F).item[(*F).fim]=X;
        (*F).fim++;
        return 1;
    }
}
int Remove( struct Fila *F,int *X)
{
    if((*F).inicio==(*F).fim)
        return 0;
    else
    {
       (* X)=(*F).item[(*F).inicio];
        (*F).inicio++;
        return 1;
    }
}
