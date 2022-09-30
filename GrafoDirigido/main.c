#include <stdio.h>
#include <stdlib.h>
int n=4,m=4;
int main()
{
    int x,y,mat[m][n],i,j;

    for(i=0; i<m; i++)
    {
        for(j=0; j<m; j++)
        {
            mat[i][j]=0;
        }
    }

    while(x>0 && y>0){
        printf("\n\n  DIGITE VALOR PARA X: ");
        scanf("%d",&x);
        printf("  DIGITE VALOR PARA Y: ");
        scanf("%d",&y);
        mat[m][n]=preenche(mat,x,y,0);
    }

    for(i=0; i<m; i++)
    {
        printf("\n    ");
        for(j=0; j<m; j++)
        {
            printf(" %d ",mat[i][j]);
        }
        printf("\n");
    }


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
                return;
            }
        }
    }
    return mat;
}
