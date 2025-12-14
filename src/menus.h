#ifndef MENUS_H
#define MENUS_H

#include "carimbos.h"

int Menu_Seed();
int Menu_Quantidade();
void Menu_Desenhos(ConjuntoCarimbos* carimbos, int numPastas);
int Menu_Forma(ConjuntoCarimbos* pastas,int numPastas);
int Menu_Quantidade_Estrelas(int linhas, int colunas);
bool Menu_Arquivo_Carregar();
int* Menu_Carregar(celula **tela,int linhas,int colunas);
void Menu_Arquivo(celula **tela,int linhas,int colunas,int seed,int rep,int formas,int naves);
void Quadro_Branco(celula** tela,int linhas,int colunas);
#endif // MENUS_H