#include <stdio.h>
#include <stdlib.h>
#define N 8

int cont=0;
int main()
{
    int coluna[N + 1];
    int rup[2 * N + 1];
    int lup[2 * N + 1];
    int rainha[N + 1] = {0};
    int i;

    for(i = 1; i <= N; i++)
        coluna[i] = 1;

    for(i = 1; i <= 2 * N; i++)
        rup[i] = lup[i] = 1;

    voltar(coluna, rup, lup, rainha, 1);
    return 0;
}
void printRainha(int * rainha)
{
    int x, y;

    for(y = 1; y <= N; y++)
    {
        printf(" ");
        for(x = 1; x <= N; x++)
        {
            printf(" %c", rainha[y] == x ? 'R' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

void voltar(int* coluna, int* rup, int* lup, int* rainha, int i)
{
    int j;
    if(i > N)
    {
        cont++;
        printf("\n  Rainha %d \n",cont);
        printRainha(rainha);
    }
    else
    {
        for(j = 1; j <= N; j++)
        {
            if(coluna[j] == 1 && rup[i + j] == 1 && lup[i - j + N] == 1)
            {
                rainha[i] = j;
                coluna[j] = rup[i + j] = lup[i - j + N] = 0;
                voltar(coluna, rup, lup, rainha, i + 1);
                coluna[j] = rup[i + j] = lup[i - j + N] = 1;
            }
        }
    }
}
