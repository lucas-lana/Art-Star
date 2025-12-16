#ifndef CARIMBOS_C
#define CARIMBOS_C

#include "carimbos.h"

/*
 * Carimbo_Estrela
 *
 * Coloca um símbolo de estrela na posição (i, j) da tela.
 *
 * Parâmetros:
 * - celula **tela: A tela onde o carimbo será aplicado.
 * - int i: A linha onde o carimbo será aplicado.
 * - int j: A coluna onde o carimbo será aplicado.
*/
void Carimbo_Estrela(celula **tela, int i, int j){
    tela[i][j].simbolo = '*';
    tela[i][j].preenchido = true;
}


/*
 * Verificar_3x3
 *
 * Verifica se uma área 3x3 na posição (i, j) da tela está completamente vazia (não preenchida).
 * 
 * Parâmetros:
 * - celula **tela: A tela onde a verificação será feita.
 * - int i: A linha inicial da área 3x3.
 * - int j: A coluna inicial da área 3x3.
 * - int linhas: O número total de linhas na tela.
 * - int colunas: O número total de colunas na tela.
 * 
 * Output:
 * - bool: Retorna true se a área 3x3 estiver completamente vazia, caso contrário, retorna false.
*/
bool Verificar_3x3(celula **tela, int i, int j, int linhas, int colunas){
    if (i < 0 || j < 0 || i + 2 >= linhas || j + 2 >= colunas) {
        return false; // Fora dos limites da tela
    }
    bool linha1 = (tela[i][j].preenchido == false && tela[i][j+1].preenchido == false && tela[i][j+2].preenchido == false);
    bool linha2 = (tela[i+1][j].preenchido == false && tela[i+1][j+1].preenchido == false && tela[i+1][j+2].preenchido == false);
    bool linha3 = (tela[i+2][j].preenchido == false && tela[i+2][j+1].preenchido == false && tela[i+2][j+2].preenchido == false);
    return linha1 && linha2 && linha3;
}


/*
 * Carimbo_Soma
 *
 * Coloca um símbolo de soma na posição (i, j) da tela.
 *
 * Parâmetros:
 * - celula **tela: A tela onde o carimbo será aplicado.
 * - int i: A linha onde o carimbo será aplicado.
 * - int j: A coluna onde o carimbo será aplicado.
*/
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

/*
 * Carimbo_X
 *
 * Coloca um símbolo de X na posição (i, j) da tela.
 *
 * Parâmetros:
 * - celula **tela: A tela onde o carimbo será aplicado.
 * - int i: A linha onde o carimbo será aplicado.
 * - int j: A coluna onde o carimbo será aplicado.
*/
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



/*
 * Carimbo_Aleatorio
 *
 * Aplica um carimbo aleatório (Estrela, Soma ou X) na posição (i, j) da tela, se possível.
 *
 * Parâmetros:
 * - celula **tela: A tela onde o carimbo será aplicado.
 * - int linhas: O número total de linhas na tela.
 * - int colunas: O número total de colunas na tela.
 * - int i: A linha onde o carimbo será aplicado.
 * - int j: A coluna onde o carimbo será aplicado.
 * - int tipo: O tipo de carimbo a ser aplicado (0 para Estrela, 1 para Soma, 2 para X).
 * 
 * Output:
 * - bool: Retorna true se o carimbo foi aplicado com sucesso, caso contrário, retorna false.
*/
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


/*
 * inverte_carimbo
 * Inverte um carimbo verticalmente (coloca de cabeça para baixo). O chamador é responsável por liberar a memória alocada para o carimbo invertido.
 * 
 * Parâmetros:
 * - char** carimbo: O carimbo a ser invertido.
 * - int linhas: O número de linhas do carimbo.
 * - int colunas: O número de colunas do carimbo.
 * 
 * Output:
 * - char**: O carimbo invertido.
*/
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


/*
 * espelha_carimbo
 * Espelha um carimbo horizontalmente (da esquerda para a direita). O chamador é responsável por liberar a memória alocada para o carimbo espelhado.
 * 
 * Parâmetros:
 * - char** carimbo: O carimbo a ser espelhado.
 * - int linhas: O número de linhas do carimbo.
 * - int colunas: O número de colunas do carimbo.
 * 
 * Output:
 * - char**: O carimbo espelhado.
*/
char** espelha_carimbo(char** carimbo,int linhas,int colunas) {
    char **espelhado = (char **)malloc(linhas * sizeof(char *));
    for(int i = 0; i < linhas; i++) {
        espelhado[i] = (char *)malloc(colunas * sizeof(char));
    }
    
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            espelhado[i][colunas-1-j] = carimbo[i][j];
        }
    }

    return espelhado;
}


/*
 * esquerda_carimbo
 * Rotaciona um carimbo 90 graus para a esquerda. O chamador é responsável por liberar a memória alocada para o carimbo rotacionado.
 * 
 * Parâmetros:
 * - char** carimbo: O carimbo a ser rotacionado.
 * - int linhas: O número de linhas do carimbo.
 * - int colunas: O número de colunas do carimbo.
 * 
 * Output:
 * - char**: O carimbo rotacionado 90 graus para a esquerda.
*/
char** esquerda_carimbo(char** carimbo,int linhas,int colunas) {
    char **esquerdo = (char **)malloc(linhas * sizeof(char *));
    for(int i = 0; i < linhas; i++) {
        esquerdo[i] = (char *)malloc(colunas * sizeof(char));
    }
    
    for(int j = 0; j < colunas; j++) {
        for(int i = 0; i < linhas; i++) {
            esquerdo[i][colunas-1-j] = carimbo[i][j];
        }
    }

    return esquerdo;
}


/*
 * verificar_Espaco
 * 
 * Verifica se há espaço suficiente em uma área da tela para aplicar um carimbo.
 * 
 * Parâmetros:
 * - celula** tela: A tela onde o carimbo será aplicado.
 * - int linhas: O número total de linhas na tela.
 * - int colunas: O número total de colunas na tela.
 * - int ref_i: A linha inicial onde o carimbo será aplicado.
 * - int ref_j: A coluna inicial onde o carimbo será aplicado.
 * - int linhas_carimbo: O número de linhas do carimbo.
 * - int colunas_carimbo: O número de colunas do carimbo.
 * 
 * Output:
 * - bool: Retorna true se houver espaço suficiente para aplicar o carimbo, caso contrário, retorna false.
*/
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


/*
 * Carimbar_Desenho
 *
 * Aplica um carimbo em uma posição específica da tela, considerando a direção (normal ou invertida).
 *
 * Parâmetros:
 * - celula** tela: A tela onde o carimbo será aplicado.
 * - Carimbo* carimbo: O array de carimbos disponíveis.
 * - int linhas: O número total de linhas na tela.
 * - int colunas: O número total de colunas na tela.
 * - int figura: O índice do carimbo a ser aplicado.
 * - int x: A linha onde o carimbo será aplicado.
 * - int y: A coluna onde o carimbo será aplicado.
 * - int direcao: A direção do carimbo (0 para normal, 1 para invertido).
 *
 * Output:
 * - bool: Retorna true se o carimbo foi aplicado com sucesso, caso contrário, retorna false.
*/
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