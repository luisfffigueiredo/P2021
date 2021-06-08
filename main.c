#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"
#include "celulas.h"
#include "utils.h"
#include "jogadas.h"
#include "jogador.h"
int main()
{
    int global=0;
    pTabuleiro pTab = NULL;
    pJogador pJog = NULL;
    pJogada pJ = NULL;

    //TABULEIRO
    pTab = inicializaTabuleiro(&global);
    mostraTabuleiro(pTab);
    pTab = jogarTabuleiro(pTab, 2, 2, 'G');
    mostraTabuleiro(pTab);

    //JOGADORES
    pJog = criaJogador(pJog, pTab);
    mostraJogadores(pJog);

    //MENU
    //int res = menuInicial(pJog, pTab, global, pJ);
    /*if(res == -1)
    {
        free(pTab);

    }*/
    //pTab = jogarTabuleiro(pTab, 2, 2, 'G');
    //mostraTabuleiro(pTab);
    return 0;
}
