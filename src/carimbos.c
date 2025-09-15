#ifndef CARIMBOS_C
#define CARIMBOS_C

#include "carimbos.h"


void Carimbo_Estrela(celula **tela, int i, int j){
    tela[i][j].simbolo = '*';
    tela[i][j].preenchido = true;
}

bool Verificar_3x3(celula **tela, int i, int j, int linhas, int colunas){
    if (i < 0 || j < 0 || i + 2 >= linhas || j + 2 >= colunas) {
        return false; // Fora dos limites da tela
    }
    bool linha1 = (tela[i][j].preenchido == false && tela[i][j+1].preenchido == false && tela[i][j+2].preenchido == false);
    bool linha2 = (tela[i+1][j].preenchido == false && tela[i+1][j+1].preenchido == false && tela[i+1][j+2].preenchido == false);
    bool linha3 = (tela[i+2][j].preenchido == false && tela[i+2][j+1].preenchido == false && tela[i+2][j+2].preenchido == false);
    return linha1 && linha2 && linha3;
}

void Carimbo_Soma(celula **tela, int i, int j){

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

void Carimbo_X(celula **tela, int i, int j){

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

bool Carimbo_Aleatorio(celula **tela,int linhas,int colunas, int i, int j,int tipo){
    bool carimbado;
    switch (tipo){
        case 0:
            if (tela[i][j].preenchido == false){
                Carimbo_Estrela(tela,i,j);
                carimbado = true;
            }
            break;
        case 1:
            if (Verificar_3x3(tela,i,j,linhas,colunas)){
                Carimbo_Soma(tela,i,j);
                carimbado = true;
            }
            break;
        case 2:
            if (Verificar_3x3(tela,i,j,linhas,colunas)) {
                Carimbo_X(tela,i,j);
                carimbado = true;
            }
            break;
    }
    return carimbado;
}

char** inverte_carimbo(char** carimbo,int linhas,int colunas) {
    char **invertido = (char **)malloc(linhas * sizeof(char *));
    for(int i = 0; i < linhas; i++) {
        invertido[i] = (char *)malloc(colunas * sizeof(char));
    }
    
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            invertido[linhas-1-i][j] = carimbo[i][j];
        }
    }

    return invertido;
}

bool verificar_Espaco(celula** tela,int linhas, int colunas, int ref_i, int ref_j, int linhas_carimbo, int colunas_carimbo) {
    for (int i = 0; i < linhas_carimbo; i++) {
        for ( int j = 0; j < colunas_carimbo; j++) {

            if (ref_i + i < 0 || ref_j + j < 0 || ref_i + i >= linhas || ref_j + j >= colunas) {
                return false; // Fora dos limites da tela
            }

            if (tela [ref_i + i][ref_j + j].preenchido == true) {
                return false;
            }
        }
    }
    return true;
}

bool Carimbar_Desenho(celula** tela,Carimbo* carimbo,int linhas, int colunas,int figura,int x, int y,int direcao){
    bool carimbado = false;

    if (verificar_Espaco(tela,linhas,colunas,x,y,carimbo[figura].ordem[0],carimbo[figura].ordem[1])){
        if(direcao == 0){
            for (int i = 0; i < carimbo[figura].ordem[0]; i++){
                for (int j = 0; j < carimbo[figura].ordem[1]; j++){
                    if (carimbo[figura].desenho[i][j] != ' '){
                        tela[x+i][y+j].simbolo = carimbo[figura].desenho[i][j];
                    }
                    tela[x+i][y+j].preenchido = true;
                }
            }
        }
        
        else{
            
            // Alocar memória para a matriz temporária
            char** temp = (char**)malloc(carimbo[figura].ordem[0]*sizeof(char*));
            for (int i = 0; i < carimbo[figura].ordem[0]; i++){
                temp[i] = (char*)malloc(carimbo[figura].ordem[1]*sizeof(char));
            }
            temp = inverte_carimbo(carimbo[figura].desenho,carimbo[figura].ordem[0],carimbo[figura].ordem[1]);

            for (int i = 0; i < carimbo[figura].ordem[0]; i++){
                for (int j = 0; j < carimbo[figura].ordem[1]; j++){
                    if (temp[i][j] != ' '){
                        tela[x+i][y+j].simbolo = temp[i][j];
                    }
                    tela[x+i][y+j].preenchido = true;
                }
            }
                    
            // Liberar a memória alocada para temp
            for (int i = 0; i < carimbo[figura].ordem[0]; i++){
                free(temp[i]);
            }
            free(temp);
        }
        carimbado = true;
    }
    return carimbado;
}

#endif // CARIMBOS_C