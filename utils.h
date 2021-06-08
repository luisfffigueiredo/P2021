// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2020-2021

#ifndef UTILS_H
#define UTILS_H
#include "tabuleiro.h"
#include "jogadas.h"

// Inicializa o gerador de numeros aleatorios.
// Esta funcao deve ser chamada apenas uma vez no inicio da execucao do programa
void initRandom();

//Devolve um valor inteiro aleatorio distribuido uniformemente entre [a, b]
int intUniformRnd(int a, int b);

// Devolve o valor 1 com probabilidade prob. Caso contrario, devolve 0
int probEvento(float prob);

void cabecalho();

int menuInicial(pJogador pJog, pTabuleiro pTab, int global, pJogada pJ);

void limpaBuffer();

int menuJogo(pJogador pJog, pTabuleiro pTab, int global, pJogada pJ);

/*



void libertaMemoriaJogada(pJogada pJ);

void libertaMemoriaJogador(pJogador pJog);

int menuInicial(pJogador pJog, pTabuleiro pTab, pJogada pJ)

*/
#endif /* UTILS_H */
