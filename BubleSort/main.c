#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet1[10]= {2,1,6,3,8,5,4,9,7,0};
    ordena(vet1,10);
    return 0;
}

int ordena( int *vet[], int n)
{
    int i, continua, aux,fim=n;
    do
    {
        continua=0;
        for(i=0; i<fim-1; i++)
        {
            if(vet[i]<vet[i+1])
            {
                aux=vet[i];
                vet[i]=vet[i+1];
                vet[i+1]=aux;
                continua=1;
            }
        }
        fim--;
    }while(continua!=0);
    for(i=0;i<10;i++)
    {
        printf(" %d, ",vet[i]);
    }
    return vet;

}
