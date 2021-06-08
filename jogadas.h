#ifndef JOGADAS_H_INCLUDED
#define JOGADAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogador.h"

typedef struct jogada jogada, *pJogada;

struct jogada
{
    int numJogada;
    int lin;
    int col;
    int idjogador;
    pJogada prox;
};

int getUltimaJogada(pJogada lista);

//pJogada adicionaJogada(pJogador jogAtual, pJogada lista);

void mostraJogada(pJogada lista);

pJogada retrocede(pJogada lista, int recua);


#endif // JOGADAS_H_INCLUDED
