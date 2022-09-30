#include <stdio.h>
#include <stdlib.h>
typedef struct busca
{
    int distancia;
    char cor;
    int vertice;
}bus;
int n=4,m=4;
int main()
{
    int x,y,mat[m][n],i,j,con=0,vet[100];

    for(i=0; i<m; i++)
    {
        for(j=0; j<m; j++)
        {
            mat[i][j]=0;
        }
    }

    while(x>0 && y>0)
    {

        printf("\n\n  DIGITE VALOR PARA X: ");
        scanf("%d",&x);
        vet[con]=x;
        printf("  DIGITE VALOR PARA Y: ");
        scanf("%d",&y);
        vet[con]=y;
        con++;
        mat[m][n]=preenche(mat,x,y,0);

    }
    printf("\n     ");
    for(i=0; i<con; i++)
        printf("%d  ",vet[i]);


    printf("\n         ");

    printf("\n\n         ");
    for(i=1; i<=m; i++)
    {
        printf(" %d   ",i);

    }
    printf("\n        ___________________");

    printf("\n       |");
    for(i=0; i<m; i++)
    {
        printf("\n    %d  | ",i+1);
        for(j=0; j<m; j++)
        {
            printf(" %d   ",mat[i][j]);
        }
        if(i<m-1)
            printf("\n       |");
    }
    printf("\n\n");

    buscaGrafos(mat);


    return 0;
}
int preenche(int mat[n][n],int a, int b,int controle)
{
    int ajuda,i,j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<m; j++)
        {
            if(i==a-1 && j==b-1)
            {
                mat[i][j]=1;
                mat[j][i]=1;
                return;
            }
        }
    }
    return mat;
}

int buscaGrafos(int mat[m][n])
{
    int ajuda,i,j,distancia=-1;
    char cor='b';
    printf("cor: %c",cor);
    for(i=0; i<m; i++)
    {
        for(j=0; j<m; j++)
        {
            if(mat[i][j]!=0)
            {
                printf("Par ( %d , %d)  ",i+1,j+1);
            }
        }
    }
    printf("\n\n");


}
