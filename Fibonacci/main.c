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

    // Se for o primeiro número da lista
    if(n == 1) {
        return 0;
    // Se for o segundo número da lista
    } else if(n == 2) {
        return 1;
    // Se for um número a partir da terceira posição
    } else {
        // Calcula os valores dois a dois até chegar na posição requerida
        for(i = 3; i <= n; i++) {
            aux = proximo;
            proximo = anterior + proximo;
            anterior = aux;
        }
        return proximo;
    }
}
