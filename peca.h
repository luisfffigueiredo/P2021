#ifndef PECA_H_INCLUDED
#define PECA_H_INCLUDED
#include "celulas.h"

typedef struct peca peca, *pPeca;

struct peca
{
    int idPeca;
    char corPeca[20];
};

#endif // PECA_H_INCLUDED
