#ifndef MENUS_H
#define MENUS_H

#include "carimbos.h"

int Menu_seed();
int Menu_Quantidade();
void Imprime_desenho(int escolha);
void Menu_Desenhos(ConjuntoCarimbos* carimbos, int numPastas);
int Menu_Forma();
int Menu_Equacao();
bool Menu_Reinicio();
int Menu_Continuar();
int Menu_Quantidade_Estrelas();
int Menu_Quantidade_Naves();
bool Menu_Arquivo_Carregar();
int* Menu_Carregar(celula **tela,int linhas,int colunas);
void Menu_Arquivo(celula **tela,int linhas,int colunas,int seed,int rep,int formas,int naves);
void Quadro_Branco(celula** tela,int linhas,int colunas);
#endif // MENUS_H