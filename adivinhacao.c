#include <stdio.h>

int main(void){
    int chute; double pontos = 1000, pontos_perdidos; unsigned int numerosecreto = 42, TENTATIVAS = 1;
    printf("=================================================\n");
    printf("\tBem-Vindo ao Jogo de Adivinhação!\n");
    printf("=================================================\n");
    while (1){
        printf("Qual é o seu %d° palpite?\t", TENTATIVAS);
        scanf("%d", &chute);
        printf("Seu %do. palpite foi:\t%d", TENTATIVAS, chute);
        TENTATIVAS++;
        if (chute > numerosecreto){
            pontos_perdidos = (chute - numerosecreto) / 2.00;
        }else{
            pontos_perdidos = (numerosecreto - chute) / 2.00;
        };
        pontos -= pontos_perdidos;
        short int acertou = chute == numerosecreto;
        short int maior = chute > numerosecreto;
        unsigned int invalido = chute < 0;
        if (invalido){
            printf("\033[31mVocê não pode chutar números negativos!\033[m\n");
            TENTATIVAS--;
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
    printf("    Seus pontos:    %.2f\n", pontos);
    printf("---------------------------\n");
    printf("\tFim de Jogo!\n");
    printf("---------------------------\n");
    return 0;
};