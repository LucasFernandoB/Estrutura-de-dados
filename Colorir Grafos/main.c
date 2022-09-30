#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct v
{
    char sigla[4];
    int cor ;
    int grau ;
} vertice;

typedef struct a
{
    char a1[4];
    char a2[4];
} aresta;

void carregarEstados(vertice vet[])
{
    FILE *arq;
    arq = fopen("ESTADOS.txt", "rt");
    int i = 0;
    if (arq == NULL)
    {
        printf("\nErro na abertura do arquivo!\n");
        return;

    }
    while(!feof(arq))
    {
        fscanf(arq,"%s\n", &vet[i].sigla);
        vet[i].cor = -1;
        i++;
    }
    fclose(arq);
}

void carregarFronteiras( aresta frondeiras[])
{
    FILE *arq;
    arq = fopen("FRONTEIRASBR.txt", "rt");
    int i = 0;
    if (arq == NULL)
    {
        printf("\nErro na abertura do arquivo!\n");
        return;
    }
    while(!feof(arq))
    {
        fscanf(arq,"%s %s\n", &frondeiras[i].a1, &frondeiras[i].a2);
        i++;
    }
    fclose(arq);
}


void comparar(vertice vet[], aresta fronteiras[])
{
    int i,j, cont;
    for(i=0; i<27; i++)
    {
        cont = 0;
        for(j=0; j<48; j++)
        {
            if( strcmp(vet[i].sigla, fronteiras[j].a1) == 0 || strcmp(vet[i].sigla,fronteiras[j].a2) == 0 )
                cont++;
        }
        vet[i].grau = cont;
    }
}

void ordenar(vertice vet[])
{
    int i = 0, j = 0,index;
    vertice menor;
    for (i=0; i<27; i++)
    {
        for (j =i+1; j<27; j++)
        {
            if(vet[i].grau < vet[j].grau)
            {
                menor = vet[i];
                vet[i]= vet[j];
                vet[j] = menor;
            }

        }
    }
}
int verifica(int cor,int i, vertice vet[], aresta fronteiras[])
{
    int j, k;
    for(j = 0; j<48; j++)
    {
        if(strcmp(fronteiras[j].a1, vet[i].sigla)==0)
        {
            for(k=0; k< 27; k++)
            {
                if(strcmp(fronteiras[j].a2,vet[k].sigla) == 0)
                {
                    if(vet[k].cor == cor)
                        return 0;/*a cor já existe*/

                }

            }

        }else  if(strcmp(fronteiras[j].a2, vet[i].sigla)==0)
        {
            for(k=0; k< 27; k++)
            {
                if(strcmp(fronteiras[j].a1,vet[k].sigla) == 0)
                {
                    if(vet[k].cor == cor)
                        return 0;/*a cor já existe*/

                }

            }

        }



    }

}

int main()
{
    vertice vet[27];
    aresta fronteiras[48];
    int i, cor = 0, coloridos = 0;

    carregarEstados(vet);
    carregarFronteiras(fronteiras);
    comparar(vet, fronteiras);
    ordenar(vet);


    while(coloridos<27)
    {
        cor ++;
        for(i=0; i < 27; i++)
        {
            if (vet[i].cor == -1)
            {
                if (verifica(cor, i, vet, fronteiras))
                {
                    vet[i].cor = cor;
                    coloridos++;


                }

            }


        }

    }
    for(i=0; i<27; i++)
        printf("[%d] %s - %d - %d\n", i, vet[i].sigla, vet[i].cor, vet[i].grau);



    return 0;
}
