#include <stdio.h>

int main(void){
    int chute, numerosecreto = 42;
    printf("Bem-Vindo ao Jogo de Adivinhação!\n");
    printf("Qual é o seu palpite?\t");
    scanf("%d", &chute);
    printf("Seu palpite foi:\t%d", chute);
    return 0;
};