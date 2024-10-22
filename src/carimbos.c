#ifndef CARIMBOS_C
#define CARIMBOS_C


#include "celula.h"


#define LINHAS 20
#define COLUNAS 80


void Carimbo_Estrela(celula tela[LINHAS][COLUNAS], int i, int j){
    tela[i][j].simbolo = '*';
    tela[i][j].preenchido = true;
}

bool Verificar_Espaço(celula tela[LINHAS][COLUNAS],int i, int j){
    bool linha1 = (tela[i][j].preenchido == false && tela[i][j+1].preenchido == false && tela[i][j+2].preenchido == false);
    bool linha2 = (tela[i+1][j].preenchido == false && tela[i+1][j+1].preenchido == false && tela[i+1][j+2].preenchido == false);
    bool linha3 = (tela[i+2][j].preenchido == false && tela[i+2][j+1].preenchido == false && tela[i+2][j+2].preenchido == false);
    return linha1 && linha2 && linha3;
}

void Carimbo_Soma(celula tela[LINHAS][COLUNAS], int i, int j){
    
    tela[i][j+1].simbolo = '*';
    tela[i+1][j].simbolo = '*';
    tela[i+1][j+1].simbolo = '*';
    tela[i+1][j+2].simbolo = '*';
    tela[i+2][j+1].simbolo = '*';

    for (int k = 0; k < 3; k++){
        for (int l = 0; l < 3; l++){
            tela[i+k][j+l].preenchido = true;
        }
    }
    
}

void Carimbo_X(celula tela[LINHAS][COLUNAS], int i, int j){
    
    tela[i][j].simbolo = '*';    
    tela[i][j+2].simbolo = '*';  
    tela[i+1][j+1].simbolo = '*';
    tela[i+2][j].simbolo = '*';
    tela[i+2][j+2].simbolo = '*';

    for (int k = 0; k < 3; k++){
        for (int l = 0; l < 3; l++){
            tela[i+k][j+l].preenchido = true;
        }
    }
}

bool Carimbo_Aleatorio(celula tela[LINHAS][COLUNAS], int i, int j,int tipo){
    bool carimbado;
    switch (tipo){
        case 0:
            if (tela[i][j].preenchido == false){
                Carimbo_Estrela(tela,i,j);
                carimbado = true;
            }
            else{
                carimbado = false;
            }
            break;
        case 1:
            if (Verificar_Espaço(tela,i,j)){
                Carimbo_Soma(tela,i,j);
                carimbado = true;
            }
            else{
                carimbado = false;
            }
            break;
        case 2:
            if (Verificar_Espaço(tela,i,j)) {
                Carimbo_X(tela,i,j);
                carimbado = true;
            }
            else{
                carimbado = false;
            }
            break;
    }
    return carimbado;
}

#endif // CARIMBOS_C