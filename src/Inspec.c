#include "celula.h"

void Carimbo_Estrela_Inspec(celula **tela, int i, int j){
    tela[i][j].simbolo = '*';
    tela[i][j].preenchido = true;
}

void Carimbo_Soma_Inspec(celula **tela, int i, int j){
    tela[i][j+1].simbolo = '*';
    tela[i+1][j].simbolo = '*';
    tela[i+1][j+1].simbolo = '*';
    tela[i+1][j+2].simbolo = '*';
    tela[i+2][j+1].simbolo = '*';    
}

void Carimbo_X_Inspec(celula **tela, int i, int j){
    tela[i][j].simbolo = '*';    
    tela[i][j+2].simbolo = '*';  
    tela[i+1][j+1].simbolo = '*';
    tela[i+2][j].simbolo = '*';
    tela[i+2][j+2].simbolo = '*';
}

void Carimbo_StarDestroyer_Inspec(celula **tela, int i, int j){
    tela[i][j+4].simbolo = '*'; tela[i][j+5].simbolo = '*';
    tela[i+1][j+3].simbolo = '*'; tela[i+1][j+4].simbolo = '*'; tela[i+1][j+5].simbolo = '*'; tela[i+1][j+6].simbolo = '*';
    tela[i+2][j+2].simbolo = '*'; tela[i+2][j+3].simbolo = '*'; tela[i+2][j+4].simbolo = '*'; tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+7].simbolo = '*';
    tela[i+3][j+3].simbolo = '*'; tela[i+3][j+4].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*';
    tela[i+4][j].simbolo = '*'; tela[i+4][j+1].simbolo = '*'; tela[i+4][j+2].simbolo = '*'; tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*'; tela[i+4][j+9].simbolo = '*';
    tela[i+5][j+4].simbolo = '*'; tela[i+5][j+5].simbolo = '*';
}

void Carimbo_StarDestroyer_Negativo_Inspec(celula **tela, int i, int j){
    tela[i][j+4].simbolo = '*'; tela[i][j+5].simbolo = '*';
    tela[i+1][j].simbolo = '*'; tela[i+1][j+1].simbolo = '*'; tela[i+1][j+2].simbolo = '*'; tela[i+1][j+3].simbolo = '*'; tela[i+1][j+4].simbolo = '*'; tela[i+1][j+5].simbolo = '*'; tela[i+1][j+6].simbolo = '*'; tela[i+1][j+7].simbolo = '*'; tela[i+1][j+8].simbolo = '*'; tela[i+1][j+9].simbolo = '*';
    tela[i+2][j+3].simbolo = '*'; tela[i+2][j+4].simbolo = '*'; tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*';
    tela[i+3][j+2].simbolo = '*'; tela[i+3][j+3].simbolo = '*'; tela[i+3][j+4].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*';
    tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*';
    tela[i+5][j+4].simbolo = '*'; tela[i+5][j+5].simbolo = '*';
}


void Carimbo_Fighter_Inspec(celula **tela, int i, int j){

    tela[i][j].simbolo = '*'; tela[i][j+12].simbolo = '*';
    tela[i+1][j].simbolo = '*'; tela[i+1][j+12].simbolo = '*';
    tela[i+2][j].simbolo = '*'; tela[i+2][j+1].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+11].simbolo = '*'; tela[i+2][j+12].simbolo = '*';
    tela[i+3][j].simbolo = '*'; tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+10].simbolo = '*'; tela[i+3][j+11].simbolo = '*'; tela[i+3][j+12].simbolo = '*';
    tela[i+4][j].simbolo = '*'; tela[i+4][j+1].simbolo = '*'; tela[i+4][j+2].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+10].simbolo = '*'; tela[i+4][j+11].simbolo = '*'; tela[i+4][j+12].simbolo = '*';
    tela[i+5][j].simbolo = '*'; tela[i+5][j+1].simbolo = '*'; tela[i+5][j+2].simbolo = '*'; tela[i+5][j+3].simbolo = '*'; tela[i+5][j+4].simbolo = '*'; tela[i+5][j+5].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+7].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+9].simbolo = '*'; tela[i+5][j+10].simbolo = '*'; tela[i+5][j+11].simbolo = '*'; tela[i+5][j+12].simbolo = '*';
    tela[i+6][j].simbolo = '*'; tela[i+6][j+1].simbolo = '*'; tela[i+6][j+2].simbolo = '*'; tela[i+6][j+3].simbolo = '*'; tela[i+6][j+4].simbolo = '*'; tela[i+6][j+5].simbolo = '*'; tela[i+6][j+6].simbolo = '*'; tela[i+6][j+7].simbolo = '*'; tela[i+6][j+8].simbolo = '*'; tela[i+6][j+9].simbolo = '*'; tela[i+6][j+10].simbolo = '*'; tela[i+6][j+11].simbolo = '*'; tela[i+6][j+12].simbolo = '*';
    tela[i+7][j].simbolo = '*'; tela[i+7][j+1].simbolo = '*'; tela[i+7][j+11].simbolo = '*'; tela[i+7][j+12].simbolo = '*';
    tela[i+8][j].simbolo = '*'; tela[i+8][j+1].simbolo = '*'; tela[i+8][j+2].simbolo = '*'; tela[i+8][j+10].simbolo = '*'; tela[i+8][j+11].simbolo = '*'; tela[i+8][j+12].simbolo = '*';
}

void Carimbo_Fighter_Negativo_Inspec(celula **tela, int i, int j){

    tela[i][j].simbolo = '*'; tela[i][j+1].simbolo = '*'; tela[i][j+2].simbolo = '*'; tela[i][j+10].simbolo = '*'; tela[i][j+11].simbolo = '*'; tela[i][j+12].simbolo = '*';
    tela[i+1][j].simbolo = '*'; tela[i+1][j+1].simbolo = '*'; tela[i+1][j+11].simbolo = '*'; tela[i+1][j+12].simbolo = '*';
    tela[i+2][j].simbolo = '*'; tela[i+2][j+1].simbolo = '*'; tela[i+2][j+2].simbolo = '*'; tela[i+2][j+3].simbolo = '*'; tela[i+2][j+4].simbolo = '*'; tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+7].simbolo = '*'; tela[i+2][j+8].simbolo = '*'; tela[i+2][j+9].simbolo = '*'; tela[i+2][j+10].simbolo = '*'; tela[i+2][j+11].simbolo = '*'; tela[i+2][j+12].simbolo = '*';
    tela[i+3][j].simbolo = '*'; tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+10].simbolo = '*'; tela[i+3][j+11].simbolo = '*'; tela[i+3][j+12].simbolo = '*';
    tela[i+4][j].simbolo = '*'; tela[i+4][j+1].simbolo = '*'; tela[i+4][j+2].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+10].simbolo = '*'; tela[i+4][j+11].simbolo = '*'; tela[i+4][j+12].simbolo = '*';
    tela[i+5][j].simbolo = '*'; tela[i+5][j+1].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+11].simbolo = '*'; tela[i+5][j+12].simbolo = '*';
    tela[i+6][j].simbolo = '*'; tela[i+6][j+12].simbolo = '*';
    tela[i+7][j].simbolo = '*'; tela[i+7][j+12].simbolo = '*';
    tela[i+8][j].simbolo = '*'; tela[i+8][j+12].simbolo = '*';
}


void Carimbo_AWing_Inspec(celula **tela, int i, int j){

    tela[i][j+5].simbolo = '*';
    tela[i+1][j+4].simbolo = '*'; tela[i+1][j+5].simbolo = '*'; tela[i+1][j+6].simbolo = '*';
    tela[i+2][j+3].simbolo = '*'; tela[i+2][j+4].simbolo = '*'; tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+7].simbolo = '*';
    tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+3].simbolo = '*'; tela[i+3][j+4].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+8].simbolo = '*'; tela[i+3][j+9].simbolo = '*';
    tela[i+4][j].simbolo = '*'; tela[i+4][j+1].simbolo = '*'; tela[i+4][j+2].simbolo = '*'; tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*'; tela[i+4][j+9].simbolo = '*'; tela[i+4][j+10].simbolo = '*';
    tela[i+5][j].simbolo = '*'; tela[i+5][j+1].simbolo = '*'; tela[i+5][j+2].simbolo = '*'; tela[i+5][j+3].simbolo = '*'; tela[i+5][j+4].simbolo = '*'; tela[i+5][j+5].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+7].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+9].simbolo = '*'; tela[i+5][j+10].simbolo = '*';
    tela[i+6][j].simbolo = '*'; tela[i+6][j+1].simbolo = '*'; tela[i+6][j+2].simbolo = '*'; tela[i+6][j+4].simbolo = '*'; tela[i+6][j+5].simbolo = '*'; tela[i+6][j+6].simbolo = '*'; tela[i+6][j+8].simbolo = '*'; tela[i+6][j+9].simbolo = '*'; tela[i+6][j+10].simbolo = '*';
    tela[i+7][j+1].simbolo = '*'; tela[i+7][j+5].simbolo = '*'; tela[i+7][j+9].simbolo = '*';
}

void Carimbo_AWing_Negativo_Inspec(celula **tela, int i, int j){

    tela[i][j+1].simbolo = '*'; tela[i][j+5].simbolo = '*'; tela[i][j+9].simbolo = '*';
    tela[i+1][j].simbolo = '*'; tela[i+1][j+1].simbolo = '*'; tela[i+1][j+2].simbolo = '*'; tela[i+1][j+4].simbolo = '*'; tela[i+1][j+5].simbolo = '*'; tela[i+1][j+6].simbolo = '*'; tela[i+1][j+8].simbolo = '*'; tela[i+1][j+9].simbolo = '*'; tela[i+1][j+10].simbolo = '*';
    tela[i+2][j].simbolo = '*'; tela[i+2][j+1].simbolo = '*'; tela[i+2][j+2].simbolo = '*'; tela[i+2][j+3].simbolo = '*'; tela[i+2][j+4].simbolo = '*'; tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+7].simbolo = '*'; tela[i+2][j+8].simbolo = '*'; tela[i+2][j+9].simbolo = '*'; tela[i+2][j+10].simbolo = '*';
    tela[i+3][j].simbolo = '*'; tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+3].simbolo = '*'; tela[i+3][j+4].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+8].simbolo = '*'; tela[i+3][j+9].simbolo = '*'; tela[i+3][j+10].simbolo = '*';
    tela[i+4][j+1].simbolo = '*'; tela[i+4][j+2].simbolo = '*'; tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*'; tela[i+4][j+9].simbolo = '*';
    tela[i+5][j+3].simbolo = '*'; tela[i+5][j+4].simbolo = '*'; tela[i+5][j+5].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+7].simbolo = '*';
    tela[i+6][j+4].simbolo = '*'; tela[i+6][j+5].simbolo = '*'; tela[i+6][j+6].simbolo = '*';
    tela[i+7][j+5].simbolo = '*';
}


void Carimbo_Interceptor_Inspec(celula **tela, int i, int j){

    tela[i][j].simbolo = '*'; tela[i][j+10].simbolo = '*';
    tela[i+1][j].simbolo = '*'; tela[i+1][j+1].simbolo = '*'; tela[i+1][j+9].simbolo = '*'; tela[i+1][j+10].simbolo = '*'; 
    tela[i+2][j].simbolo = '*'; tela[i+2][j+1].simbolo = '*'; tela[i+2][j+9].simbolo = '*'; tela[i+2][j+10].simbolo = '*';
    tela[i+3][j].simbolo = '*'; tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+8].simbolo = '*'; tela[i+3][j+9].simbolo = '*'; tela[i+3][j+10].simbolo = '*';
    tela[i+4][j].simbolo = '*'; tela[i+4][j+1].simbolo = '*'; tela[i+4][j+2].simbolo = '*'; tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*'; tela[i+4][j+9].simbolo = '*'; tela[i+4][j+10].simbolo = '*';
    tela[i+5][j].simbolo = '*'; tela[i+5][j+1].simbolo = '*'; tela[i+5][j+2].simbolo = '*'; tela[i+5][j+3].simbolo = '*'; tela[i+5][j+4].simbolo = '*'; tela[i+5][j+5].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+7].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+9].simbolo = '*'; tela[i+5][j+10].simbolo = '*';
    tela[i+6][j].simbolo = '*'; tela[i+6][j+1].simbolo = '*'; tela[i+6][j+2].simbolo = '*'; tela[i+6][j+3].simbolo = '*'; tela[i+6][j+4].simbolo = '*'; tela[i+6][j+5].simbolo = '*'; tela[i+6][j+6].simbolo = '*'; tela[i+6][j+7].simbolo = '*'; tela[i+6][j+8].simbolo = '*'; tela[i+6][j+9].simbolo = '*'; tela[i+6][j+10].simbolo = '*';
    tela[i+7][j].simbolo = '*'; tela[i+7][j+1].simbolo = '*'; tela[i+7][j+3].simbolo = '*'; tela[i+7][j+4].simbolo = '*'; tela[i+7][j+5].simbolo = '*'; tela[i+7][j+6].simbolo = '*'; tela[i+7][j+7].simbolo = '*'; tela[i+7][j+9].simbolo = '*'; tela[i+7][j+10].simbolo = '*';
    tela[i+8][j+4].simbolo = '*'; tela[i+8][j+5].simbolo = '*'; tela[i+8][j+6].simbolo = '*';
}

void Carimbo_Interceptor_Negativo_Inspec(celula **tela, int i, int j){

    tela[i][j+4].simbolo = '*'; tela[i][j+5].simbolo = '*'; tela[i][j+6].simbolo = '*';
    tela[i+1][j].simbolo = '*'; tela[i+1][j+1].simbolo = '*'; tela[i+1][j+3].simbolo = '*'; tela[i+1][j+4].simbolo = '*'; tela[i+1][j+5].simbolo = '*'; tela[i+1][j+6].simbolo = '*'; tela[i+1][j+7].simbolo = '*'; tela[i+1][j+9].simbolo = '*'; tela[i+1][j+10].simbolo = '*';
    tela[i+2][j].simbolo = '*'; tela[i+2][j+1].simbolo = '*'; tela[i+2][j+2].simbolo = '*'; tela[i+2][j+3].simbolo = '*'; tela[i+2][j+4].simbolo = '*'; tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+7].simbolo = '*'; tela[i+2][j+8].simbolo = '*'; tela[i+2][j+9].simbolo = '*'; tela[i+2][j+10].simbolo = '*';
    tela[i+3][j].simbolo = '*'; tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+3].simbolo = '*'; tela[i+3][j+4].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+8].simbolo = '*'; tela[i+3][j+9].simbolo = '*'; tela[i+3][j+10].simbolo = '*';
    tela[i+4][j].simbolo = '*'; tela[i+4][j+1].simbolo = '*'; tela[i+4][j+2].simbolo = '*'; tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*'; tela[i+4][j+9].simbolo = '*'; tela[i+4][j+10].simbolo = '*';
    tela[i+5][j].simbolo = '*'; tela[i+5][j+1].simbolo = '*'; tela[i+5][j+2].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+9].simbolo = '*'; tela[i+5][j+10].simbolo = '*';
    tela[i+6][j].simbolo = '*'; tela[i+6][j+1].simbolo = '*'; tela[i+6][j+9].simbolo = '*'; tela[i+6][j+10].simbolo = '*';
    tela[i+7][j].simbolo = '*'; tela[i+7][j+1].simbolo = '*'; tela[i+7][j+9].simbolo = '*'; tela[i+7][j+10].simbolo = '*';
    tela[i+8][j].simbolo = '*'; tela[i+8][j+10].simbolo = '*';
}

void Carimbo_YWing_Inspec(celula **tela, int i, int j){

    tela[i][j+5].simbolo = '*';
    tela[i+1][j+4].simbolo = '*'; tela[i+1][j+5].simbolo = '*'; tela[i+1][j+6].simbolo = '*';
    tela[i+2][j+3].simbolo = '*'; tela[i+2][j+4].simbolo = '*'; tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+7].simbolo = '*';
    tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+3].simbolo = '*'; tela[i+3][j+4].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+8].simbolo = '*'; tela[i+3][j+9].simbolo = '*';
    tela[i+4][j].simbolo = '*'; tela[i+4][j+1].simbolo = '*'; tela[i+4][j+2].simbolo = '*'; tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*'; tela[i+4][j+9].simbolo = '*'; tela[i+4][j+10].simbolo = '*';
    tela[i+5][j].simbolo = '*'; tela[i+5][j+1].simbolo = '*'; tela[i+5][j+2].simbolo = '*'; tela[i+5][j+3].simbolo = '*'; tela[i+5][j+4].simbolo = '*'; tela[i+5][j+5].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+7].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+9].simbolo = '*'; tela[i+5][j+10].simbolo = '*';
    tela[i+6][j].simbolo = '*'; tela[i+6][j+1].simbolo = '*'; tela[i+6][j+2].simbolo = '*'; tela[i+6][j+8].simbolo = '*'; tela[i+6][j+9].simbolo = '*'; tela[i+6][j+10].simbolo = '*';
    tela[i+7][j].simbolo = '*'; tela[i+7][j+1].simbolo = '*'; tela[i+7][j+2].simbolo = '*'; tela[i+7][j+8].simbolo = '*'; tela[i+7][j+9].simbolo = '*'; tela[i+7][j+10].simbolo = '*';
    tela[i+8][j].simbolo = '*'; tela[i+8][j+1].simbolo = '*'; tela[i+8][j+9].simbolo = '*'; tela[i+8][j+10].simbolo = '*';
}

void Carimbo_YWing_Negativo_Inspec(celula **tela, int i, int j){

    tela[i][j].simbolo = '*'; tela[i][j+1].simbolo = '*'; tela[i][j+9].simbolo = '*'; tela[i][j+10].simbolo = '*';
    tela[i+1][j].simbolo = '*'; tela[i+1][j+1].simbolo = '*'; tela[i+1][j+2].simbolo = '*'; tela[i+1][j+8].simbolo = '*'; tela[i+1][j+9].simbolo = '*'; tela[i+1][j+10].simbolo = '*';
    tela[i+2][j].simbolo = '*'; tela[i+2][j+1].simbolo = '*'; tela[i+2][j+2].simbolo = '*'; tela[i+2][j+8].simbolo = '*'; tela[i+2][j+9].simbolo = '*'; tela[i+2][j+10].simbolo = '*';
    tela[i+3][j].simbolo = '*'; tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+3].simbolo = '*'; tela[i+3][j+4].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+8].simbolo = '*'; tela[i+3][j+9].simbolo = '*'; tela[i+3][j+10].simbolo = '*';
    tela[i+4][j].simbolo = '*'; tela[i+4][j+1].simbolo = '*'; tela[i+4][j+2].simbolo = '*'; tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*'; tela[i+4][j+9].simbolo = '*'; tela[i+4][j+10].simbolo = '*';
    tela[i+5][j+1].simbolo = '*'; tela[i+5][j+2].simbolo = '*'; tela[i+5][j+3].simbolo = '*'; tela[i+5][j+4].simbolo = '*'; tela[i+5][j+5].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+7].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+9].simbolo = '*';
    tela[i+6][j+3].simbolo = '*'; tela[i+6][j+4].simbolo = '*'; tela[i+6][j+5].simbolo = '*'; tela[i+6][j+6].simbolo = '*'; tela[i+6][j+7].simbolo = '*';
    tela[i+7][j+4].simbolo = '*'; tela[i+7][j+5].simbolo = '*'; tela[i+7][j+6].simbolo = '*';
    tela[i+8][j+5].simbolo = '*';
}


void Carimbo_N1_Inspec(celula **tela, int i, int j){

    tela[i][j+4].simbolo = '*';
    tela[i+1][j+3].simbolo = '*'; tela[i+1][j+4].simbolo = '*'; tela[i+1][j+5].simbolo = '*';
    tela[i+2][j+1].simbolo = '*'; tela[i+2][j+2].simbolo = '*'; tela[i+2][j+3].simbolo = '*'; tela[i+2][j+4].simbolo = '*'; tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+7].simbolo = '*';
    tela[i+3][j].simbolo = '*'; tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+3].simbolo = '*'; tela[i+3][j+4].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+8].simbolo = '*';
    tela[i+4][j].simbolo = '*'; tela[i+4][j+1].simbolo = '*'; tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*';
    tela[i+5][j].simbolo = '*'; tela[i+5][j+4].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; 
}

void Carimbo_N1_Negativo_Inspec(celula **tela, int i, int j){

    tela[i][j].simbolo = '*'; tela[i][j+4].simbolo = '*'; tela[i][j+8].simbolo = '*';
    tela[i+1][j].simbolo = '*'; tela[i+1][j+1].simbolo = '*'; tela[i+1][j+3].simbolo = '*'; tela[i+1][j+4].simbolo = '*'; tela[i+1][j+5].simbolo = '*'; tela[i+1][j+7].simbolo = '*'; tela[i+1][j+8].simbolo = '*';
    tela[i+2][j].simbolo = '*'; tela[i+2][j+1].simbolo = '*'; tela[i+2][j+2].simbolo = '*'; tela[i+2][j+3].simbolo = '*'; tela[i+2][j+4].simbolo = '*'; tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+7].simbolo = '*'; tela[i+2][j+8].simbolo = '*';
    tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+3].simbolo = '*'; tela[i+3][j+4].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*';
    tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*';
    tela[i+5][j+4].simbolo = '*';
}

void Carimbo_XWing_Inspec(celula **tela, int i, int j){

    tela[i][j].simbolo = '*'; tela[i][j+1].simbolo = '*'; tela[i][j+11].simbolo = '*'; tela[i][j+12].simbolo = '*';
    tela[i+1][j].simbolo = '*'; tela[i+1][j+1].simbolo = '*'; tela[i+1][j+11].simbolo = '*'; tela[i+1][j+12].simbolo = '*'; 
    tela[i+2][j].simbolo = '*'; tela[i+2][j+1].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+11].simbolo = '*'; tela[i+2][j+12].simbolo = '*';
    tela[i+3][j].simbolo = '*'; tela[i+3][j+1].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+11].simbolo = '*'; tela[i+3][j+12].simbolo = '*';
    tela[i+4][j].simbolo = '*'; tela[i+4][j+1].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+11].simbolo = '*'; tela[i+4][j+12].simbolo = '*';
    tela[i+5][j].simbolo = '*'; tela[i+5][j+1].simbolo = '*'; tela[i+5][j+5].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+7].simbolo = '*'; tela[i+5][j+11].simbolo = '*'; tela[i+5][j+12].simbolo = '*';
    tela[i+6][j].simbolo = '*'; tela[i+6][j+1].simbolo = '*'; tela[i+6][j+4].simbolo = '*'; tela[i+6][j+5].simbolo = '*'; tela[i+6][j+6].simbolo = '*'; tela[i+6][j+7].simbolo = '*'; tela[i+6][j+8].simbolo = '*'; tela[i+6][j+11].simbolo = '*'; tela[i+6][j+12].simbolo = '*';
    tela[i+7][j].simbolo = '*'; tela[i+7][j+1].simbolo = '*'; tela[i+7][j+2].simbolo = '*'; tela[i+7][j+3].simbolo = '*'; tela[i+7][j+4].simbolo = '*'; tela[i+7][j+5].simbolo = '*'; tela[i+7][j+6].simbolo = '*'; tela[i+7][j+7].simbolo = '*'; tela[i+7][j+8].simbolo = '*'; tela[i+7][j+9].simbolo = '*'; tela[i+7][j+10].simbolo = '*'; tela[i+7][j+11].simbolo = '*'; tela[i+7][j+12].simbolo = '*';
    tela[i+8][j+5].simbolo = '*'; tela[i+8][j+6].simbolo = '*'; tela[i+8][j+7].simbolo = '*'; 
}

void Carimbo_XWing_Negativo_Inspec(celula **tela, int i, int j){

    tela[i][j+5].simbolo = '*'; tela[i][j+6].simbolo = '*'; tela[i][j+7].simbolo = '*'; 
    tela[i+1][j].simbolo = '*'; tela[i+1][j+1].simbolo = '*'; tela[i+1][j+2].simbolo = '*'; tela[i+1][j+3].simbolo = '*'; tela[i+1][j+4].simbolo = '*'; tela[i+1][j+5].simbolo = '*'; tela[i+1][j+6].simbolo = '*'; tela[i+1][j+7].simbolo = '*'; tela[i+1][j+8].simbolo = '*'; tela[i+1][j+9].simbolo = '*'; tela[i+1][j+10].simbolo = '*'; tela[i+1][j+11].simbolo = '*'; tela[i+1][j+12].simbolo = '*';
    tela[i+2][j].simbolo = '*'; tela[i+2][j+1].simbolo = '*'; tela[i+2][j+4].simbolo = '*'; tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+7].simbolo = '*'; tela[i+2][j+8].simbolo = '*'; tela[i+2][j+11].simbolo = '*'; tela[i+2][j+12].simbolo = '*';
    tela[i+3][j].simbolo = '*'; tela[i+3][j+1].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+11].simbolo = '*'; tela[i+3][j+12].simbolo = '*';
    tela[i+4][j].simbolo = '*'; tela[i+4][j+1].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+11].simbolo = '*'; tela[i+4][j+12].simbolo = '*';
    tela[i+5][j].simbolo = '*'; tela[i+5][j+1].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+11].simbolo = '*'; tela[i+5][j+12].simbolo = '*';
    tela[i+6][j].simbolo = '*'; tela[i+6][j+1].simbolo = '*'; tela[i+6][j+11].simbolo = '*'; tela[i+6][j+12].simbolo = '*';
    tela[i+7][j].simbolo = '*'; tela[i+7][j+1].simbolo = '*'; tela[i+7][j+11].simbolo = '*'; tela[i+7][j+12].simbolo = '*';
    tela[i+8][j].simbolo = '*'; tela[i+8][j+1].simbolo = '*'; tela[i+8][j+11].simbolo = '*'; tela[i+8][j+12].simbolo = '*';
}