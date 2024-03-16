#include <stdio.h>
#include <stdlib.h>

// Calcula o valor do frete
// Retorna um valor do tipo float
// Recebe 2 argumentos do tipo float e 1 do tipo int
float calcFrete(float peso, float distancia, int tipo) {
    int taxa; // Taxa do tipo do frete

    // Verifica o tipo de frete
    if (tipo == 1) {
        taxa = 10; // Tipo economico
    }
    else if (tipo == 2) {
        taxa = 20; // Tipo padrao
    }
    else if (tipo == 3) {
        taxa = 30; // Tipo expresso
    }
    else {
        perror("Tipo de frete invalido"); // Mensagem de erro
        exit(1); // Encerra o programa
    }

    return peso * distancia + taxa; // Retorna o valor do frete
}

int main() {
    float peso, distancia; // Peso e distancia da encomenda
    int tipo; // Tipo de frete

    do {
        printf("Digite o peso da encomenda (kg): ");
        scanf("%f", &peso); // Le o peso da encomenda
        fflush(stdin); // Limpa o buffer do teclado
        system("cls || clear"); // Limpa a tela
    } while (peso <= 0); // Enquanto o peso for invalido

    do {
        printf("Digite a distancia da entrega (km): ");
        scanf("%f", &distancia); // Le a distancia da entrega
        fflush(stdin);
        system("cls");
    } while (distancia <= 0); // Enquanto a distancia for invalida

    do {
        printf("Digite o tipo de frete (1, 2 ou 3): ");
        scanf("%d", &tipo); // Le o tipo de frete
        fflush(stdin);
        system("cls");
    } while (tipo < 1 || tipo > 3); // Enquanto o tipo de frete for invalido

    float valor = calcFrete(peso, distancia, tipo); // Salva o valor do frete na variavel valor
    printf("O valor do frete e R$%.2f", valor); // Exibe o valor do frete

    return 0;
}



