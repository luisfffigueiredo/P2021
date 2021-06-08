#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tabuleiro.h"

#include "utils.h"

#define MINLIN 3
#define MAXLIN 5

pTabuleiro inicializaTabuleiro(int *total){
    pTabuleiro pTab=NULL;

    pTab = malloc(sizeof(tabuleiro));
    initRandom();

    pTab->lin = pTab->col = intUniformRnd(MINLIN,MAXLIN);

    pTab->celulas = malloc(sizeof(celula) * pTab->lin * pTab->col);
    pTab->prox = NULL;


    *total += 1;

    while(adicionaCelula(pTab));
    return pTab;
}


void mostraXTabuleiro(pTabuleiro pTab, int kx, int total){
    pTabuleiro aux = pTab;

    for(int i = 0; i < total-kx; i++)
        aux = aux->prox;

    for(int i = 0; i < kx; i++){
        mostraTabuleiro(aux);
        printf("\n");
        aux = aux->prox;
    }
}

void mostraUltTabuleiro(pTabuleiro pTab){
    pTabuleiro pTabu = pTab;

    while(pTabu->prox != NULL)
        pTabu = pTabu->prox;

    mostraTabuleiro(pTabu);
}

void mostraTabuleiro(pTabuleiro pTab) {
    int n = 0;
    while (n < pTab->lin * pTab->col) {
        for (int i = 0; i < pTab->lin; i++) {
            printf("\t");
            for (int j = 0; j < pTab->col; j++)
            {
                printf("%c ", pTab->celulas[n].peca);
                n++;
            }
            printf("\n");
        }
    }
}

pTabuleiro adicionaLinha(pTabuleiro pTab, int *total){
    pTabuleiro novo, aux;

    novo = malloc(sizeof(pTab));
    if(novo  == NULL){
        printf("Erro na alocacao de memória\n");
        return pTab;
    }

    aux = pTab;
    while(aux->prox != NULL)
        aux = aux->prox;

    acrescentaTabuleiro(novo, aux);

    novo->lin += 1;


    while(adicionaCelula(novo));

    *total += 1;
    return pTab;
}

pTabuleiro adicionaColuna(pTabuleiro pTab, int *total){
    pTabuleiro novo, aux;

    novo = malloc(sizeof(pTab));
    if(novo  == NULL){
        printf("Erro na alocacao de memória\n");
        return pTab;
    }

    aux = pTab;

    while(aux->prox != NULL)
        aux = aux->prox;

    acrescentaTabuleiro(novo, aux);

    novo->col += 1;

    while(adicionaCelula(novo));

    *total += 1;
    return pTab;
}

int adicionaCelula(pTabuleiro pTab){
    int n = 0;
    celula *c  = malloc(sizeof(celula) * pTab->lin * pTab->col);
    if(c == NULL){
        puts("Erro na alocacao de memoria");
        return 1;
    }
    pTab->celulas = c;

    while(n < pTab->lin*pTab->col) {
        for (int i = 0; i < pTab->lin; i++) {

            for (int j = 0; j < pTab->col; j++) {
                pTab->celulas[n].peca = '_';
                pTab->celulas[n].lin = i;
                pTab->celulas[n].col = j;
                n++;
            }
        }
    }
    return 0;
}

pTabuleiro jogarTabuleiro(pTabuleiro pTab, int lin, int col, char peca) {
    pTabuleiro novo, aux;
    pJogada jogada;
    jogada = malloc(sizeof(pJogada));
    if (jogada == NULL)
    {
        printf("Erro na alocacao de memória para jogada\n");
        return jogada;
    }
    jogada=NULL;
       // jogada->prox=NULL;

    novo = malloc(sizeof(pTab));
    if (novo == NULL) {
        printf("Erro na alocacao de memória\n");
        return pTab;
    }
    aux = pTab;
    while (aux->prox != NULL)
        aux = aux->prox;
    acrescentaTabuleiro(novo, aux);
    adicionaCelula(novo);

    while(!mudarCelula(novo,lin,col,peca));
    adicionaJogada(jogada,lin,col,123);
    return novo;
}


int mudarCelula(pTabuleiro pTab, int lin, int col, char peca){
    int n = 0;
    while(n < pTab->lin*pTab->col)
    {
        for (int i = 0; i < lin; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if (pTab->celulas[n].lin == lin - 1  && pTab->celulas[n].col == col -1 )
                {
                    if (pTab->celulas[n].peca == '_') {
                        pTab->celulas[n].peca = peca;
                        return 1;
                    } else {
                        printf("Ja existe peca na posicao\n");
                        return 0;
                    }
                }
                n++;
            }
        }
    }
    printf("Nao foi possivel colocar a peca\n");
    return 0;
}




void acrescentaTabuleiro(pTabuleiro novo, pTabuleiro ultimo){
    novo->lin = ultimo->lin;
    novo->col = ultimo->col;
    novo->celulas = malloc(sizeof(celula));
    novo->prox=NULL;
    ultimo->prox = novo;
}
