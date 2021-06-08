#include "jogadas.h"

int getUltimaJogada(pJogada lista)
{
    pJogada aux= lista;
    int jogada=0;
    if (lista==NULL){
        return 0;
    }
    else
    {
    while (aux->prox!=NULL)
    {
        aux= aux->prox;
        jogada= aux->numJogada;
    }
    return jogada;
    }
}


pJogada retrocede(pJogada lista, int recua)
{
    pJogada aux=lista;
    int numJog=getUltimaJogada(lista); //obtem o numero da ultima jogada
    int posAtual=numJog-recua;

    while(aux!=NULL)
    {
        if(aux->numJogada == posAtual)
        {
            //vai percorrer o resto da lista e elimina
            pJogada remove=aux->prox;
            aux->prox=NULL;
            while (remove!=NULL)
            {
                aux = remove;
                remove = remove->prox;
                free(aux);
            }
        }
        else
        {
            aux=aux->prox;
        }
    }
    return lista;
 }



void mostraJogada(pJogada lista)
{
    pJogada aux=lista;
    while (aux!=NULL)
    {
        printf("\nNUMERO JOGADA %d",aux->numJogada);
        printf("\n\n");
        aux= aux->prox;
    }
}


pJogada adicionaJogada(pJogada lista, int lin,int col, int idjogador)
{
    pJogada novo= NULL, aux=NULL;
    int numJogada= getUltimaJogada(lista);

    numJogada+=1;// adicionamos uma jogada

    //alocar jogadas
    novo=(pJogada)malloc(sizeof(jogada));

    if(novo==NULL)
    {
        printf("Erro na alocacacao de memoria");
        return lista;
    }

//    novo->atual=NULL;
    novo->numJogada=numJogada;
    novo->idjogador=idjogador;
    novo->col=col;
    novo->lin=lin;

    novo->prox= NULL;



    if(lista==NULL)
    {
        lista=novo;
    }else
    {
        aux= lista;
        while (aux->prox!=NULL)
        {
            aux= aux->prox;
        }
        aux->prox=novo;
    }
    printf("\n\n\n%d %d %d %d", lista->idjogador, lista->numJogada, lista->col, lista->lin);
    return  lista;
}


