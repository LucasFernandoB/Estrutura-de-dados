//#include <iostream.h>
#include <stdio.h>
#include <conio.h>
struct stack{
int topo;
int dados[10];
};

void empilha (int x, struct stack *pil);
int desempilha(struct stack *pil);

void main(void)
{
    int x;
    struct stack pilha;

    pilha.topo=-1;
    empilha(4,&pilha);
    empilha(2,&pilha);
    empilha(7,&pilha);
    x=desempilha(&pilha);
    printf("\n %d",x);
    x=desempilha(&pilha);
    printf("\n %d",x);
    x=desempilha(&pilha);
    printf("\n %d \n",x);
    x=desempilha(&pilha);
    printf("\n %d \n",x);
    getch();

}

void empilha (int x, struct stack *pil)
{
    //struct stack pilha;
    if ((*pil).topo == 9) /* pilha cheia */
        printf("%s", "stack overflow");
    else
    {
        (*pil).topo=(*pil).topo+1;
        (*pil).dados[((*pil).topo)]=x;
    }
}
int desempilha(struct stack *pil)
{
 //struct stack pilha;


    if ((*pil).topo == -1)  /* pilha vazia */
    {
        printf("%s", "stack underflow,pilha vazia");
        return(-1);
    }
    else
    {
        (*pil).topo=(*pil).topo-1;
        return((*pil).dados[(*pil).topo]);
    }
}
