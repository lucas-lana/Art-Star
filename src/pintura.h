#ifndef PINTURA_H
#define PINTURA_H

#include "carimbos.h"
void imprime_char_colorido(char c);
void Quadro_Branco(celula** tela,int linhas,int colunas);
void Imprimir_Quadro(celula **tela, int linhas, int colunas,bool colorido);
void imprime_elemento(char** carimbo,int linhas,int colunas,bool colorido);
int limite_desenho(ConjuntoCarimbos* Pastas,int numPastas,char* nomePasta,int linhas,int colunas);
int Get_Coordenada(int linhas, int colunas,int seed,int i,int old_coordenada,bool tipo,int equacao);
long int Carimbar(celula** tela,ConjuntoCarimbos* carimbosPasta,int numPastas,int linhas, int colunas, int seed,int carimbo,int carimbadas,int equacao,int index);
#endif