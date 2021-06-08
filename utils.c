// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2020-2021

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

void initRandom(){
    srand(time(NULL));
}

int intUniformRnd(int a, int b){
    return a + rand()%(b-a+1);
}

int probEvento(float prob){
    return prob > ((float)rand()/RAND_MAX);
}

void cabecalho()
{
    printf("\t\t\t\t JOGO DO SEMAFORO\n");
    printf("Trabalho realizado por Luis Figueiredo - 2015011975\n");
}


int menuInicial(pJogador pJog, pTabuleiro pTab, int global, pJogada pJ)
 {
    int opcao = 0;
    int res = 0;
    int flag = 0;
    char c;
    do {
        printf("\n\t\t\t\t----------\n");
        printf("\t\t\t\t   MENU\n");
        printf("\t\t\t\t----------\n");
        printf("1 - Jogo\n");
        printf("2 - Carregar Jogo\n");
        printf("3 - Sair\n");
        printf("Opcao: ");

        do {
            flag = 0;
            if (((scanf(" %d%c", &opcao, &c)) != 2) || c != '\n') {
                flag = 1;
                limpaBuffer();
                opcao = 0;
            }
            flag = 0;
        } while (flag == 1);

        switch (opcao) {
            case 1:
                res = menuJogo(pJog, pTab, global, pJ);
            case 2:
                //carregar jogo

            case 3:
                res = -1;
                break;
            default:
                break;
        }
        if (res == -1) {
            return -1;
        }

    } while (opcao != 2);
}

void limpaBuffer()
{
    while (getchar() != '\n');
}

int menuJogo(pJogador pJog, pTabuleiro pTab, int global, pJogada pJ) {
    int op = 0;
    int flag = 0;
    int res = 0;
    int jogada = 0;
    char c;
    do
    {
        printf("\n\t\t\t\t--------------\n");
        printf("\t\t\t\t   MENU JOGO \n");
        printf("\t\t\t\t--------------\n");
        printf("1- Avancar uma jogada\n");
        printf("2- Apresentar estatistica\n");
        printf("3- Mostrar Jogadores\n");
        printf("4- Adicionar Jogador\n");
        printf("5- Transferir pessoas\n");
        printf("6- Recuar x Jogadas\n");
        printf("7- Terminar Jogo\n");
        printf("Opcao:");

        if (scanf(" %d%c", &op, &c) != 2 || c != '\n')
        {
            limpaBuffer();
            op = 0;
        }

        switch (op) {
            case 1:
                //pJ = avancar(p, sal, global, pJ);
                break;
            case 2:
                //taxasinfo(p);
                //DisPessoaSala(p, sal, global);
                break;
            case 3:
                //mostradados(p);
                break;
            case 4:
                //p = criapessoa(p, sal, global);
                break;
            case 5:
                //p = transf_pess(sal, p, global);
                //mostradados(p);
                break;
            case 6:
                if (pJ != NULL)
                    {
                    if (getUltimaJogada(pJ) != 0)
                    {
                        do
                        {
                            flag = 0;
                            printf("\nInsira Quantas iteracoes quer recuar (MAX 3):");
                            if (scanf(" %d%c", &jogada, &c) != 2 || c != '\n')
                            {
                                limpaBuffer();
                                jogada = 5;
                                flag == 1;
                            }

                            res = getUltimaJogada(pJ) - jogada;

                        } while (jogada > 3 || res < 0 || flag == 1);
                        pJ = retrocede(pJ, jogada);
                        mostraTabuleiro(pJ);
//                        p = actualiza(pJ, p);
                    }else
                    {
                        printf("Apenas existe uma iteracao da jogada\n");
                    }
                } else
                {
                    printf("Nao existe qualquer jogada\n");
                }
                break;
            case 7:
//                term_sim(p);
   //             print_last(p);
                return -1;
            default:
                break;
        }

    } while (op != 7);
}
