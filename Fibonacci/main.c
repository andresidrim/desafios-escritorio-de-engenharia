#include <stdio.h>
#include <stdlib.h>

int main() {
    int entrada; // numero de termos da sequencia de fibonacci
    int t1 = 0; // penultimo termo
    int t2 = 1; // ultimo termo
    int sum = t1 + t2; // proximo termo

    do {
        printf("Digite o numero de termos da sequencia de fibonacci (0 e 1 nao inclusos): ");
        scanf("%d", &entrada); // usuario escolhe o numero de termos
        fflush(stdin);
        system("cls || clear"); // limpa a tela apos o input do usuario
    } while (entrada < 0); // enquanto o numero for invalido

    // printa os dois primeiros termos por padrão
    printf("Termo 1: %d\n", t1);
    printf("Termo 2: %d\n", t2);

    for (int i = 0; i < entrada; i++) {
        sum = t1 + t2; // proximo termo
        // move os termos para a proxima posicao
        t1 = t2;
        t2 = sum;
        printf("Termo %d: %d\n", i + 3, sum); // printa o proximo termo
    }

    return 0;
}
