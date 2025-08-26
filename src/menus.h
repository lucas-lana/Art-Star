#ifndef MENUS_H
#define MENUS_H

#include "celula.h"
#define LINHAS 20
#define COLUNAS 80

int Menu_seed();
int Menu_Quantidade();
void Imprime_desenho(int escolha);
void Menu_Desenhos();
int Menu_Forma();
int Menu_Equacao();
bool Menu_Reinicio();
int Menu_Continuar();
int Menu_Quantidade_Estrelas();
int Menu_Quantidade_Naves();
bool Menu_Arquivo_Carregar();
int *Menu_Carregar(celula tela[LINHAS][COLUNAS]);
void Menu_Arquivo(celula tela[LINHAS][COLUNAS],int seed,int rep,int formas,int naves);
void Quadro_Branco(celula tela[LINHAS][COLUNAS]);
#endif // MENUS_H