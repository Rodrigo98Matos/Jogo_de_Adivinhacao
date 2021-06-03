#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int rand0_99(){
    return rand() % 100;// Função retorna um número entre 0 e 99
};

int continuar(){
    int resposta;
    printf("Continuar?\n[0]\tNão\n[1]\tSim\n>>>\t");
    scanf("%d",&resposta);
    return resposta;
};

int main(void){
    short int acertou;
    int segundos = time(0);
    srand(segundos);
    int chute; double pontos = 1000, pontos_perdidos;
    unsigned int dificuldade,quantidade_tentativas;
    printf("=================================================\n");
    printf("\tBem-Vindo ao Jogo de Adivinhação!\n");
    printf("=================================================\n");
    while (1){
        printf("=================================================\n");
        printf("Qual o nivel de dificuldade?\n");
        printf("[1]\tFacil\n[2]\tMédio\n[3]\tDificil\n");
        printf("=================================================\n");
        printf("\n>>>\t");
        scanf("%d", &dificuldade);
        switch(dificuldade){
            case 1:
                quantidade_tentativas = 20;
                break;
            case 2:
                quantidade_tentativas = 15;
                break;
            case 3:
                quantidade_tentativas = 5;
                break;
            default:
                printf("\033[31mEncolha uma opção válida!\033[m");
                break;
        };
        unsigned int  TENTATIVAS = 1, numerosecreto = rand0_99();/*Gera um número aleatorio entre 0 e 99*/
        for (int tent = 1;tent <= quantidade_tentativas;tent++){
            printf("Tentativa %d de %d",tent, quantidade_tentativas);
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
            acertou = chute == numerosecreto;
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
            if (!acertou){
                printf("\033[31mVocê perdeu!\033[m\n");

            }else{
                printf("---------------------------\n");
                printf("    Seus pontos:    %.2f\n", pontos);
                printf("---------------------------\n");
            };
            if (!continuar()){
                break;
            };
        };
    printf("---------------------------\n");
    printf("\tFim de Jogo!\n");
    printf("---------------------------\n");
    return 0;
};