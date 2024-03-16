#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Biblioteca para a função rand()

// Jogo de batalha de turnos usando funções e laços de repetição

// Menu principal
int Menu() {
    int escolha;

    do {
        printf("1. Iniciar\n2. Tutorial\n3. Sair\n\n");
        printf("> ");
        scanf("%d", &escolha);
        fflush(stdin);
        system("cls || clear");
    } while (escolha < 1 || escolha > 3);

    return escolha; // Retorna a escolha do jogador
}

// Gera valores aleatórios entre dois limites
//                 valor mínimo,       valor máximo
float GerarValores(int limiteInferior, int limiteSuperior) {
    int variacao = (limiteSuperior - limiteInferior) * 10; // Variação entre os limites
    return ((rand() % variacao) * 0.1) + limiteInferior; // Gera um número entre os limites
}

// OBS: A função rand() retorna um número inteiro. Para transformá-lo em um número decimal, é necessário multiplicar por 0.1

// Verifica se um ataque falha com base em uma chance de erro
int Erro(int chance) {
    return rand() % 101 <= chance;
    // rand() % 101 gera um número aleatório entre 0 e 100
}

// Retorna o valor do ataque leve ou 0, caso o ataque falhe
float AtaqueLeve() {
    if (Erro(12)) return 0; // O ataque leve tem 12% de chance de falhar
    return GerarValores(8, 15); // O dano do ataque leve pode variar entre 8 e 15
}

// Retorna o valor do ataque pesado ou 0, caso o ataque falhe
float AtaquePesado() {
    if (Erro(40)) return 0; // O ataque pesado tem 40% de chance de falhar
    return GerarValores(20, 30); // O dano do ataque pesado pode variar entre 20 e 30
}

// Retorna o valor da poção pequena
float PocaoPequena() {
    return GerarValores(4, 7); // A poção pequena pode curar entre 4 e 7 HP
}

// Retorna o valor da poção grande
float PocaoGrande() {
    return GerarValores(8, 14); // A poção grande pode curar entre 8 e 14 HP
}

// Retorna o valor da defesa, que vai diminuir o dano recebido pelo inimigo
float Defesa() {
    return GerarValores(0, 5); // A defesa pode variar entre 0 e 5
}

// Menu da função Ataque
int MenuAtaque() {
    int escolha;

    do {
        printf("1. Ataque leve\n2. Ataque pesado\n3. Voltar\n\n> ");
        scanf("%d", &escolha);
        fflush(stdin);
        system("cls || clear");
    } while (escolha < 1 || escolha > 3);

    return escolha; // Retorna a escolha do jogador
}

// Menu da função Cura
int MenuCura() {
    int escolha;

    do {
        printf("1. Pocao pequena\n2. Pocao grande\n3. Voltar\n\n>");
        scanf("%d", &escolha);
        fflush(stdin);
        system("cls || clear");
    } while (escolha < 1 || escolha > 3);

    return escolha; // Retorna a escolha do jogador
}

// Função que controla o turno do jogador
int TurnoJogador(float vidaJogador, float vidaOponente, int qtdPocaoPequena, int qtdPocaoGrande) {
    int escolha;

    do {
        printf("Turno do jogador\n\n");
        printf("Seu HP: %.2f\nHP do oponente: %.2f\nPocao pequena: %d\nPocao grande: %d\n\n", vidaJogador, vidaOponente, qtdPocaoPequena, qtdPocaoGrande);
        printf("1. Ataque\n2. Cura\n\n> ");
        scanf("%d", &escolha);
        fflush(stdin);
        system("cls || clear");
    } while (escolha < 1 || escolha > 2);

    if (escolha == 1) {
        escolha = MenuAtaque(); // Qualquer escolha feita no menu de ataque será um número entre 1 e 3 (1, 2 ,3)
    }
    else {
        escolha = MenuCura() + 3; // Qualquer escolha feita no menu de cura será um número entre 4 e 6 (4, 5, 6)
    }

    // Assim é possivel diferenciar as escolhas de ataque e cura

    return escolha; // Retorna a escolha do jogador
}

// Função que controla o turno do oponente
int TurnoOponente(float vidaJogador, float vidaOponente, int qtdPocaoPequenaOponente, int qtdPocaoGrandeOponente) {
    int escolha;

    // Se o oponente não tiver mais poções pequenas e grandes
    if (qtdPocaoPequenaOponente == 0 && qtdPocaoGrandeOponente == 0) {
        escolha = rand() % 2; // Ele só pode escolher atacar (escolha = 0 ou 1)
    }
    // Se o oponente não tiver mais poções grandes
    else if (qtdPocaoGrandeOponente == 0) {
        escolha = rand() % 3; // Ele só pode escolher atacar ou curar com a poção pequena (escolha = 0, 1 ou 2)
    }
    // Se o oponente não tiver mais poções pequenas
    else if (qtdPocaoPequenaOponente == 0) {
        escolha = rand() % 3;
        if (escolha == 2) escolha = 3; // Ele só pode escolher atacar ou curar a poção grande (escolha = 0, 1 ou 3)
    }
    else {
        escolha = rand() % 4; // Se o oponente tiver as duas poções, ele pode escolher atacar ou curar com qualquer uma delas (escolha = 0, 1, 2 ou 3)
    }

    printf("Seu HP: %.2f\nHP do oponente: %.2f\nPocao pequena: %d\nPocao grande: %d\n\n", vidaJogador, vidaOponente, qtdPocaoPequenaOponente, qtdPocaoGrandeOponente);
    printf("O oponente esta pensando...\n");

    return escolha; // Retorna a escolha do oponente
}

// Função que explica as mecânicas do jogo
void Tutorial() {
    printf("Bem-vindo ao jogo de batalha de turnos! Neste jogo, voce enfrentara um oponente em uma batalha onde cada turno e crucial para determinar o vencedor.\n\n");
    system("pause");
    system("cls || clear");
    printf("O objetivo do jogo e derrotar seu oponente, reduzindo sua vida a zero, enquanto mantem sua propria vida.\n\nDurante a batalha, voce e seu oponente terao oportunidades alternadas para agir em cada turno.\nVoce pode escolher entre duas acoes principais: Ataque ou Cura.\nSelecione sua acao com base em sua estrategia e no estado atual da batalha.\n\n");
    system("pause");
    system("cls || clear");
    printf("Ataque Leve: Um ataque rapido com menor chance de errar e dano moderado.\nAtaque Pesado: Um ataque poderoso com maior chance de errar, mas causa mais dano.\nPocao Pequena: Recupere uma pequena quantidade de vida para se curar.\nPocao Grande: Recupere uma quantidade maior de vida para uma cura mais eficaz.\n\n");
    system("pause");
    system("cls || clear");
    printf("Agora que voce entende as mecanicas basicas, entre na batalha e teste suas habilidades!\n\n");
    system("pause");
    system("cls || clear");
}

int main() {
    srand(time(NULL)); // Gera uma semente para a função rand()

    // Loop principal
    while (1) {
        int escolha = Menu(); // Menu principal -> Salva a escolha do jogador
        int turno = rand() % 2; // Sorteia quem começa o jogo (0 = jogador, 1 = oponente)

        // Jogador
        float vidaJogador = 100; // Vida inicial do jogador
        int qtdPocaoPequena = 5; // Quantidade inicial de poções pequenas
        int qtdPocaoGrande = 2; // Quantidade inicial de poções grandes

        // Oponente
        float vidaOponente = 100; // Vida inicial do oponente
        int qtdPocaoPequenaOponente = 5; // Quantidade inicial de poções pequenas
        int qtdPocaoGrandeOponente = 2; // Quantidade inicial de poções grandes

        // Se o jogador escolher 1 -> Inicia o jogo
        if (escolha == 1) {
            // Loop da batalha
            // O loop continua enquanto a vida do jogador e do oponente for maior que zero
            while (vidaJogador > 0 && vidaOponente > 0) {
                // Se o turno for 0 -> Jogador
                if (turno == 0) {
                    // Menu de escolha do jogador
                    escolha = TurnoJogador(vidaJogador, vidaOponente, qtdPocaoPequena, qtdPocaoGrande); // Salva a escolha do jogador
                    if (escolha == 3 || escolha == 6) continue; // Se a escolha for 3 ou 6, volta para o menu principal (3 -> voltar no menu de ataque, 6 -> voltar no menu de cura)
                    // Se a escolha for 1 -> Ataque Leve
                    else if (escolha == 1) {
                        float dano = AtaqueLeve() - Defesa(); // Calcula o dano do ataque leve
                        // Se o dano for menor ou igual a zero, o ataque falhou
                        if (dano <= 0) printf("Jogador usou Ataque Leve!\nVoce errou!\nHP do oponente: %.2f", vidaOponente);
                        // Se o dano for maior que zero, o ataque foi bem sucedido
                        else {
                            vidaOponente -= dano; // Diminui a vida do oponente
                            printf("Jogador usou Ataque Leve!\nVoce causou %.2f de dano!\nHP do oponente: %.2f", dano, vidaOponente);
                        }
                    }
                    // Se a escolha for 2 -> Ataque Pesado
                    else if (escolha == 2) {
                        float dano = AtaquePesado() - Defesa(); // Calcula o dano do ataque pesado
                        // Se o dano for menor ou igual a zero, o ataque falhou
                        if (dano <= 0) printf("Jogador usou Ataque Pesado!\nVoce errou!\nHP do oponente: %.2f", vidaOponente);
                        // Se o dano for maior que zero, o ataque foi bem sucedido
                        else {
                            vidaOponente -= dano; // Diminui a vida do oponente
                            printf("Jogador usou Ataque Pesado!\nVoce causou %.2f de dano!\nHP do oponente: %.2f", dano, vidaOponente);
                        }
                    }
                    // Se a escolha for 4 -> Pocao Pequena
                    else if (escolha == 4) {
                        // Se o jogador não tiver mais poções pequenas, ele não pode usar
                        if (qtdPocaoPequena == 0) {
                            printf("Voce nao tem mais pocoes pequenas!\n\n");
                            system("pause");
                            system("cls || clear");
                            continue; // Volta para o menu principal
                        }
                        // Se o jogador tiver poções pequenas, ele pode usar
                        float cura = PocaoPequena(); // Calcula a cura da poção pequena
                        vidaJogador += cura; // Recupera a vida do jogador
                        printf("Jogador usou Pocao Pequena!\nVoce recuperou %.2f de vida!\nSeu HP: %.2f", cura, vidaJogador);
                        qtdPocaoPequena--; // Diminui a quantidade de poções pequenas
                    }
                    // Se a escolha for 5 -> Pocao Grande
                    else {
                        // Se o jogador não tiver mais poções grandes, ele não pode usar
                        if (qtdPocaoGrande == 0) {
                            printf("Voce nao tem mais pocoes grandes!\n\n");
                            system("pause");
                            system("cls || clear");
                            continue; // Volta para o menu principal
                        }
                        float cura = PocaoGrande(); // Calcula a cura da poção grande
                        vidaJogador += cura; // Recupera a vida do jogador
                        printf("Jogador usou Pocao Grande!\nVoce recuperou %.2f de vida!\nSeu HP: %.2f", cura, vidaJogador);
                        qtdPocaoGrande--; // Diminui a quantidade de poções grandes
                    }
                }
                // Se o turno for 1 -> Oponente
                else {
                    printf("Turno do oponente\n\n");
                    escolha = TurnoOponente(vidaJogador, vidaOponente, qtdPocaoPequenaOponente, qtdPocaoGrandeOponente); // Salva a escolha do oponente
                    printf("\n");
                    system("pause");
                    system("cls || clear");

                    // Se a escolha for 0 -> Ataque Leve
                    if (escolha == 0) {
                        float dano = AtaqueLeve() - Defesa(); // Calcula o dano do ataque leve
                        // Se o dano for menor ou igual a zero, o ataque falhou
                        if (dano <= 0) printf("O oponente usou Ataque Leve!\nEle errou!\nSeu HP: %.2f", vidaJogador);
                        // Se o dano for maior que zero, o ataque foi bem sucedido
                        else {
                            vidaJogador -= dano; // Diminui a vida do jogador
                            printf("O oponente usou Ataque Leve!\nEle causou %.2f de dano!\nSeu HP: %.2f", dano, vidaJogador);
                        }
                    }
                    // Se a escolha for 1 -> Ataque Pesado
                    else if (escolha == 1) {
                        float dano = AtaquePesado() - Defesa(); // Calcula o dano do ataque pesado
                        // Se o dano for menor ou igual a zero, o ataque falhou
                        if (dano <= 0) printf("O oponente usou Ataque Pesado!\nEle errou!\nSeu HP: %.2f", vidaJogador);
                        // Se o dano for maior que zero, o ataque foi bem sucedido
                        else {
                            vidaJogador -= dano; // Diminui a vida do jogador
                            printf("O oponente usou Ataque Pesado!\nEle causou %.2f de dano!\nSeu HP: %.2f", dano, vidaJogador);
                        }
                    }
                    // Se a escolha for 2 -> Pocao Pequena
                    else if (escolha == 2) {
                        float cura = PocaoPequena(); // Calcula a cura da poção pequena
                        vidaOponente += cura; // Recupera a vida do oponente
                        printf("O oponente usou Pocao Pequena!\nEle recuperou %.2f de vida!\nHP do oponente: %.2f", cura, vidaOponente);
                        qtdPocaoPequenaOponente--;
                    }
                    // Se a escolha for 3 -> Pocao Grande
                    else {
                        float cura = PocaoGrande(); // Calcula a cura da poção grande
                        vidaOponente += cura; // Recupera a vida do oponente
                        printf("O oponente usou Pocao Grande!\nEle recuperou %.2f de vida!\nHP do oponente: %.2f", cura, vidaOponente);
                        qtdPocaoGrandeOponente--; // Diminui a quantidade de poções grandes
                    }
                }
                printf("\n\n");
                system("pause");
                system("cls || clear");
                turno = !turno; // Troca o turno (0 -> 1 | 1 -> 0)
            }
        }
        // Se o jogador escolher 2 -> Mostra o tutorial
        else if (escolha == 2) {
            Tutorial(); // Mostra o tutorial
            continue; // Volta para o menu principal
        }
        // Se o jogador escolher 3 -> Encerra o programa
        else {
            printf("Obrigado por jogar!\n\n");
            exit(0); // Encerra o programa
        }

        // Verifica o resultado da batalha
        if (vidaJogador <= 0) printf("Voce perdeu!\n\n"); // Se a vida do jogador for menor ou igual a zero, ele perde
        else printf("Voce venceu!\n\n"); // Se a vida do oponente for menor ou igual a zero, o jogador vence

        // Menu de escolha (jogar novamente ou sair)
        do {
            printf("1. Jogar Novamente / 2. Sair)\n> ");
            scanf("%d", &escolha);
            fflush(stdin);
            system("cls || clear");
        } while (escolha < 1 || escolha > 2);

        // Se o jogador escolher 1 -> Reinicia o jogo -> Volta para o menu principal

        // Se o jogador escolher 2 -> Encerra o programa
        if (escolha == 2) {
            printf("Obrigado por jogar!\n\n");
            exit(0); // Encerra o programa
        }
    }

    return 0;
}
