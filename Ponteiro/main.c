#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[10],i=0;
    int *p;
   //vet[0]=0;
    p=&vet;
   // for(i=0;i<10;i++)
   while(i<10) {
       printf("DIGITE VALORES: ");
        scanf("%d",p);
        *p++;
        i++;
    }
    for(i=0;i<10;i++)
    {
        printf("vet[%d]= %d\n",i,vet[i]);

    }
    return 0;
}
