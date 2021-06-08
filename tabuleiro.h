#ifndef TABULEIRO_H_INCLUDED
#define TABULEIRO_H_INCLUDED
#include "celulas.h"
typedef struct tabuleiro tabuleiro, *pTabuleiro;

struct tabuleiro
{
    int lin;
    int col;
    pCelula celulas;
    pTabuleiro prox;
};

//FUNCOES
//inicializa tabuleiro e aloca na memória
pTabuleiro inicializaTabuleiro(int *total);

//mostra tabuleiro
void mostraTabuleiro(pTabuleiro pTab);

//adiciona celula ao tabuleiro
int adicionaCelula(pTabuleiro pTab);

//adiciona coluna ao tabuleiro
pTabuleiro adicionaColuna(pTabuleiro pTab, int *total);

//adiciona linha ao tabuleiro
pTabuleiro adicionaLinha(pTabuleiro pTab, int *total);

pTabuleiro jogarTabuleiro(pTabuleiro pTab, int lin, int col, char peca);

//mudar de celula
int mudarCelula(pTabuleiro pTab, int lin, int col, char peca);
#endif // TABULEIRO_H_INCLUDED
