#include <stdio.h>
#include <stdlib.h>

int Fatorial(int n) {
    if (n == 0) return 1; // Se o numero for 0, o fatorial e 1

    // Calcula o fatorial do numero -> n! = n * (n - 1) * (n - 2) * ... * 1
    for (int i = n - 1; i > 0; i--) {
        n *= i; // Multiplica o numero pelo proximo menor
    }

    return n; // Retorna o fatorial
}

int main() {
    int entrada; // Numero a ser calculado o fatorial

    do {
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &entrada); // Le o numero
        fflush(stdin); // Limpa o buffer do teclado
        system("cls || clear"); // Limpa a tela
    } while (entrada < 0); // Enquanto o numero for invalido

    printf("%d! = %d", entrada, Fatorial(entrada)); // Exibe o fatorial do numero

    return 0;
}