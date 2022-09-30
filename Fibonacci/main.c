#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    printf("Digite a posicao: ");
    scanf("%d", &n);
    printf("O termo: %d\n", fibonacci(n));
    system("pause");
    return 0;
}
int fibonacci(int n) {
    int anterior = 0,
        proximo = 1,
        aux,
        i;

    // Se for o primeiro n�mero da lista
    if(n == 1) {
        return 0;
    // Se for o segundo n�mero da lista
    } else if(n == 2) {
        return 1;
    // Se for um n�mero a partir da terceira posi��o
    } else {
        // Calcula os valores dois a dois at� chegar na posi��o requerida
        for(i = 3; i <= n; i++) {
            aux = proximo;
            proximo = anterior + proximo;
            anterior = aux;
        }
        return proximo;
    }
}
