#ifndef CELULAS_H_INCLUDED
#define CELULAS_H_INCLUDED
#include "peca.h"

typedef struct celulas celula, *pCelula;

struct celulas
{
    int lin;
    int col;

    pPeca peca;
    pCelula prox;
};


#endif // CELULAS_H_INCLUDED
