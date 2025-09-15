#ifndef CARIMBO_H
#define CARIMBO_H

#include "celula.h"

typedef struct {
    char** desenho;
    int ordem[2];
    char nome[64];
} Carimbo;

typedef struct {
    int quantidade;
    Carimbo* carimbos;
} Carimbos_Num;

typedef struct {
    char nomePasta[128];
    int quantidade;
    Carimbo* carimbos;
} ConjuntoCarimbos;


void Carimbo_Estrela(celula **tela, int i, int j);
bool Verificar_3x3(celula **tela, int i, int j, int linhas, int colunas);
void Carimbo_Soma(celula **tela, int i, int j);
void Carimbo_X(celula **tela, int i, int j);
bool Carimbo_Aleatorio(celula **tela,int linhas,int colunas, int i, int j,int tipo);
bool Carimbar_Desenho(celula **tela,Carimbo* carimbo,int linhas, int colunas, int figura,int x, int y,int index);
long int Carimbar(celula **tela,ConjuntoCarimbos* carimbosPasta,int numPastas,int linhas, int colunas, int seed, int forma, int quantidade, int equacao, int naves);
void Imprimir_Quadro(celula **tela, int linhas, int colunas);
void Imprimir_Quadro_Cor(char **tela,int linhas, int colunas);
char** inverte_carimbo(char** carimbo,int linhas,int colunas);
bool verificar_Espaco(celula** tela,int linhas, int colunas, int ref_i, int ref_j, int linhas_carimbo, int colunas_carimbo);

#endif