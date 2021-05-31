#include <stdio.h>
#define NUMERO_DE_TENTATIVAS 3

int main(void){
    int chute;
    unsigned int numerosecreto = 42;
    printf("=================================================\n");
    printf("\tBem-Vindo ao Jogo de Adivinhação!\n");
    printf("=================================================\n");
    for (unsigned int i = 1; i <= NUMERO_DE_TENTATIVAS; i++){
        printf("Qual é o seu %d° palpite?\t", i);
        scanf("%d", &chute);
        printf("Seu %do. palpite foi:\t%d", i, chute);
        short int acertou = chute == numerosecreto;
        short int maior = chute > numerosecreto;
        unsigned int invalido = chute < 0;
        if (invalido){
            printf("\033[31mDigite um número positivo!\033[m\n");
            i--;
        } else if (acertou) {
            printf("\033[32m\nParabéns, Você acertou!\033[m\n");
            break;
        } else if(maior) {
                printf("\033[33m\nSeu Chute foi maior do que o número secreto! Mas não desanime, jogue novamente!\033[m\n");
            } else {
                printf("\033[33m\nSeu chute foi menor do que o número secreto! Mas não desanime, jogue novamente!\033[m\n");
            };
        };
    printf("---------------------------\n");
    printf("\tFim de Jogo!\n");
    printf("---------------------------\n");
    return 0;
};