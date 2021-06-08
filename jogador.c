#include "jogador.h"

//inserção à cauda
pJogador criaJogador(pJogador pJog, pTabuleiro pTab)
{
    int i=0;
    pJogador novo=NULL;
    novo=malloc(sizeof(jogador));
    if(novo == NULL)
    {
        printf("Erro na alocacao de memoria\n");
        return pJog;
    }
    else
    {
        novo->prox = pJog;
        pJog = novo;
        for(i=0; i < sizeof(jogador);i++)
        {
            if(novo[i].idJogador > 2)
                novo[i].idJogador = 1;
            else
            {
                if(novo[i].idJogador == 0 || novo[i].idJogador > 0)
                {
                    novo[i].idJogador += 1;
                    novo[i].prox = NULL;
                }
            }

        }
    }
    return novo;
}

void mostraJogadores(pJogador pJog)
{
    if(pJog == NULL)
    {
        printf("\nNão existem jogadores na lista");
    }else
    {
        while(pJog != NULL)
        {
            printf("\nID Jogador: %d", pJog->idJogador);
            pJog = pJog->prox;
        }
    }
    printf("\n---------------------------\n");
}
