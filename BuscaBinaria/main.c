#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[10],i,a=8;
    printf("\n   ");
    for(i=0; i<10; i++)
    {
        vet[i]=i;
        printf(" vet[%d]= %d  ",vet[i],i);
    }
    printf("\n");
    printf("Numero a ser buscado: %d",a);
    busca(vet,0,10,a);

    return 0;
}
int busca(int vet[], int i, int j, int n)
{
    int meio,a,b;
    a=b=0;
    if(meio==j || meio==i || meio==0)
        printf("\n   NAO  EXISTE\n");

    else
    {
        meio=(i+j)/2;
        if(vet[meio]==n)//ta antes
        {
            printf("Achou [%d]= %d\n",meio,n);
            return;
        }
        else
        {
            if(vet[meio]>n)//ta antes
            {
                busca(vet,i,meio,n);
            }
            else//ta depois
            {
                busca(vet,meio,j,n);
            }
        }
    }

}
