#include <stdio.h>

int main(void){
    int chute, numerosecreto = 42;
    printf("Bem-Vindo ao Jogo de Adivinhação!\n");
    printf("Qual é o seu palpite?\t");
    scanf("%d", &chute);
    printf("Seu palpite foi:\t%d", chute);
    int acertou = chute == numerosecreto;
    if(acertou){
        printf("\033[32m\nParabéns, Você acertou!\033[m\n");
    }else{
        int maior = chute > numerosecreto;
        if(maior){
            printf("\033[33m\nSeu Chute foi maior do que o número secreto! Mas não desanime, jogue novamente!\033[m\n");
        }else{
            printf("\033[33m\nSeu chute foi menor do que o número secreto! Mas não desanime, jogue novamente!\033[m\n");
        };
    };
    return 0;
};