#ifndef JOGADOR_H_INCLUDED
#define JOGADOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabuleiro.h"
typedef struct jogador jogador, *pJogador;

struct jogador
{
    int idJogador;
    //ppeca peca;
    pJogador prox;
};

pJogador criaJogador(pJogador pJog, pTabuleiro pTab);

void mostraJogadores(pJogador pJog);

#endif // JOGADOR_H_INCLUDED
