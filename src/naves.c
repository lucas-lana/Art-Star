#include "carimbos.c"

bool Verificar_Espaço_StarDestroyer(celula **tela,int i, int j){
    for (int k = 0; k < 9; k++){
        for (int l = 0; l < 12; l++){
            if (tela[i+k][j+l].preenchido == true){
                return false;
            }
        }
    }
    return true;
}

void Carimbo_StarDestroyer(celula **tela, int i, int j){

    tela[i+1][j+5].simbolo = '*'; tela[i+1][j+6].simbolo = '*';
    tela[i+2][j+4].simbolo = '*'; tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+7].simbolo = '*';
    tela[i+3][j+3].simbolo = '*'; tela[i+3][j+4].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+8].simbolo = '*';
    tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*';
    tela[i+5][j+1].simbolo = '*'; tela[i+5][j+2].simbolo = '*'; tela[i+5][j+3].simbolo = '*'; tela[i+5][j+4].simbolo = '*'; tela[i+5][j+5].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+7].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+9].simbolo = '*'; tela[i+5][j+10].simbolo = '*';
    tela[i+6][j+5].simbolo = '*'; tela[i+6][j+6].simbolo = '*';


    for (int k = 0; k < 9; k++){
        for (int l = 0; l < 12; l++){
            tela[i+k][j+l].preenchido = true;
        }
    }
}

void Carimbo_StarDestroyer_Negativo(celula **tela,int i, int j){

    tela[i+1][j+5].simbolo = '*'; tela[i+1][j+6].simbolo = '*';
    tela[i+2][j+1].simbolo = '*'; tela[i+2][j+2].simbolo = '*'; tela[i+2][j+3].simbolo = '*'; tela[i+2][j+4].simbolo = '*'; tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+7].simbolo = '*'; tela[i+2][j+8].simbolo = '*'; tela[i+2][j+9].simbolo = '*'; tela[i+2][j+10].simbolo = '*';
    tela[i+3][j+4].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*';
    tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*';
    tela[i+5][j+4].simbolo = '*'; tela[i+5][j+5].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+7].simbolo = '*';
    tela[i+6][j+5].simbolo = '*'; tela[i+6][j+6].simbolo = '*';


    for (int k = 0; k < 9; k++){
        for (int l = 0; l < 12; l++){
            tela[i+k][j+l].preenchido = true;
        }
    }
}

bool Verificar_Espaço_9x13(celula **tela,int i, int j){
    for (int k = 0; k <11; k++){
        for (int l = 0; l < 15; l++){
            if (tela[i+k][j+l].preenchido == true){
                return false;
            }
        }
    }
    return true;
}

void Carimbo_Fighter(celula **tela, int i, int j){

    tela[i+1][j+1].simbolo = '*'; tela[i+1][j+13].simbolo = '*';
    tela[i+2][j+1].simbolo = '*'; tela[i+2][j+13].simbolo = '*';
    tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+12].simbolo = '*'; tela[i+3][j+13].simbolo = '*';
    tela[i+4][j+1].simbolo = '*'; tela[i+4][j+2].simbolo = '*'; tela[i+4][j+3].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*'; tela[i+4][j+11].simbolo = '*'; tela[i+4][j+12].simbolo = '*'; tela[i+4][j+13].simbolo = '*';
    tela[i+5][j+1].simbolo = '*'; tela[i+5][j+2].simbolo = '*'; tela[i+5][j+3].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+7].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+11].simbolo = '*'; tela[i+5][j+12].simbolo = '*'; tela[i+5][j+13].simbolo = '*';
    tela[i+6][j+1].simbolo = '*'; tela[i+6][j+2].simbolo = '*'; tela[i+6][j+3].simbolo = '*'; tela[i+6][j+4].simbolo = '*'; tela[i+6][j+5].simbolo = '*'; tela[i+6][j+6].simbolo = '*'; tela[i+6][j+7].simbolo = '*'; tela[i+6][j+8].simbolo = '*'; tela[i+6][j+9].simbolo = '*'; tela[i+6][j+10].simbolo = '*'; tela[i+6][j+11].simbolo = '*'; tela[i+6][j+12].simbolo = '*'; tela[i+6][j+13].simbolo = '*';
    tela[i+7][j+1].simbolo = '*'; tela[i+7][j+2].simbolo = '*'; tela[i+7][j+3].simbolo = '*'; tela[i+7][j+4].simbolo = '*'; tela[i+7][j+5].simbolo = '*'; tela[i+7][j+6].simbolo = '*'; tela[i+7][j+7].simbolo = '*'; tela[i+7][j+8].simbolo = '*'; tela[i+7][j+9].simbolo = '*'; tela[i+7][j+10].simbolo = '*'; tela[i+7][j+11].simbolo = '*'; tela[i+7][j+12].simbolo = '*'; tela[i+7][j+13].simbolo = '*';
    tela[i+8][j+1].simbolo = '*'; tela[i+8][j+2].simbolo = '*'; tela[i+8][j+12].simbolo = '*'; tela[i+8][j+13].simbolo = '*';
    tela[i+9][j+1].simbolo = '*'; tela[i+9][j+2].simbolo = '*'; tela[i+9][j+3].simbolo = '*'; tela[i+9][j+11].simbolo = '*'; tela[i+9][j+12].simbolo = '*'; tela[i+9][j+13].simbolo = '*';


    for (int k = 0; k < 11; k++){
        for (int l = 0; l < 15; l++){
            tela[i+k][j+l].preenchido = true;
        }
    }
}

void Carimbo_Fighter_Negativo(celula **tela, int i, int j){

    tela[i+1][j+1].simbolo = '*'; tela[i+1][j+2].simbolo = '*'; tela[i+1][j+3].simbolo = '*'; tela[i+1][j+11].simbolo = '*'; tela[i+1][j+12].simbolo = '*'; tela[i+1][j+13].simbolo = '*';
    tela[i+2][j+1].simbolo = '*'; tela[i+2][j+2].simbolo = '*'; tela[i+2][j+12].simbolo = '*'; tela[i+2][j+13].simbolo = '*';
    tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+3].simbolo = '*'; tela[i+3][j+4].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+8].simbolo = '*'; tela[i+3][j+9].simbolo = '*'; tela[i+3][j+10].simbolo = '*'; tela[i+3][j+11].simbolo = '*'; tela[i+3][j+12].simbolo = '*'; tela[i+3][j+13].simbolo = '*';
    tela[i+4][j+1].simbolo = '*'; tela[i+4][j+2].simbolo = '*'; tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*'; tela[i+4][j+9].simbolo = '*'; tela[i+4][j+10].simbolo = '*'; tela[i+4][j+11].simbolo = '*'; tela[i+4][j+12].simbolo = '*'; tela[i+4][j+13].simbolo = '*';
    
    tela[i+5][j+1].simbolo = '*'; tela[i+5][j+2].simbolo = '*'; tela[i+5][j+3].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+7].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+11].simbolo = '*'; tela[i+5][j+12].simbolo = '*'; tela[i+5][j+13].simbolo = '*';
    tela[i+6][j+1].simbolo = '*'; tela[i+6][j+2].simbolo = '*'; tela[i+6][j+3].simbolo = '*'; tela[i+6][j+6].simbolo = '*'; tela[i+6][j+7].simbolo = '*'; tela[i+6][j+8].simbolo = '*'; tela[i+6][j+11].simbolo = '*'; tela[i+6][j+12].simbolo = '*'; tela[i+6][j+13].simbolo = '*';
    tela[i+7][j+1].simbolo = '*'; tela[i+7][j+2].simbolo = '*'; tela[i+7][j+7].simbolo = '*'; tela[i+7][j+12].simbolo = '*'; tela[i+7][j+13].simbolo = '*';
    tela[i+8][j+1].simbolo = '*'; tela[i+8][j+13].simbolo = '*';
    tela[i+9][j+1].simbolo = '*'; tela[i+9][j+13].simbolo = '*';



    for (int k = 0; k < 11; k++){
        for (int l = 0; l < 15; l++){
            tela[i+k][j+l].preenchido = true;
        }
    }
}

// A-Wing

bool Verificar_Espaço_AWing(celula **tela,int i, int j){
    for (int k = 0; k < 10; k++){
        for (int l = 0; l < 13; l++){
            if (tela[i+k][j+l].preenchido == true){
                return false;
            }
        }
    }
    return true;
}

void Carimbo_AWing(celula **tela, int i, int j){

    tela[i+1][j+6].simbolo = '*';
    tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+7].simbolo = '*';
    tela[i+3][j+4].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+8].simbolo = '*';
    tela[i+4][j+2].simbolo = '*'; tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*'; tela[i+4][j+9].simbolo = '*'; tela[i+4][j+10].simbolo = '*';
    tela[i+5][j+1].simbolo = '*'; tela[i+5][j+2].simbolo = '*'; tela[i+5][j+3].simbolo = '*'; tela[i+5][j+4].simbolo = '*'; tela[i+5][j+5].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+7].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+9].simbolo = '*'; tela[i+5][j+10].simbolo = '*'; tela[i+5][j+11].simbolo = '*';
    tela[i+6][j+1].simbolo = '*'; tela[i+6][j+2].simbolo = '*'; tela[i+6][j+3].simbolo = '*'; tela[i+6][j+4].simbolo = '*'; tela[i+6][j+5].simbolo = '*'; tela[i+6][j+6].simbolo = '*'; tela[i+6][j+7].simbolo = '*'; tela[i+6][j+8].simbolo = '*'; tela[i+6][j+9].simbolo = '*'; tela[i+6][j+10].simbolo = '*'; tela[i+6][j+11].simbolo = '*';
    tela[i+7][j+1].simbolo = '*'; tela[i+7][j+2].simbolo = '*'; tela[i+7][j+3].simbolo = '*'; tela[i+7][j+5].simbolo = '*'; tela[i+7][j+6].simbolo = '*'; tela[i+7][j+7].simbolo = '*'; tela[i+7][j+9].simbolo = '*'; tela[i+7][j+10].simbolo = '*'; tela[i+7][j+11].simbolo = '*';
    tela[i+8][j+2].simbolo = '*'; tela[i+8][j+6].simbolo = '*'; tela[i+8][j+10].simbolo = '*';


    for (int k = 0; k < 10; k++){
        for (int l = 0; l < 13; l++){
            tela[i+k][j+l].preenchido = true;
        }
    }
}

void Carimbo_AWing_Negativo(celula **tela,int i,int j){

    tela[i+1][j+2].simbolo = '*'; tela[i+1][j+6].simbolo = '*'; tela[i+1][j+10].simbolo = '*';
    tela[i+2][j+1].simbolo = '*'; tela[i+2][j+2].simbolo = '*'; tela[i+2][j+3].simbolo = '*'; tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+7].simbolo = '*'; tela[i+2][j+9].simbolo = '*'; tela[i+2][j+10].simbolo = '*'; tela[i+2][j+11].simbolo = '*';
    tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+3].simbolo = '*'; tela[i+3][j+4].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+8].simbolo = '*'; tela[i+3][j+9].simbolo = '*'; tela[i+3][j+10].simbolo = '*'; tela[i+3][j+11].simbolo = '*';
    tela[i+4][j+1].simbolo = '*'; tela[i+4][j+2].simbolo = '*'; tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*'; tela[i+4][j+9].simbolo = '*'; tela[i+4][j+10].simbolo = '*'; tela[i+4][j+11].simbolo = '*';
    tela[i+5][j+2].simbolo = '*'; tela[i+5][j+3].simbolo = '*'; tela[i+5][j+4].simbolo = '*'; tela[i+5][j+5].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+7].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+9].simbolo = '*'; tela[i+5][j+10].simbolo = '*';
    tela[i+6][j+4].simbolo = '*'; tela[i+6][j+5].simbolo = '*'; tela[i+6][j+6].simbolo = '*'; tela[i+6][j+7].simbolo = '*'; tela[i+6][j+8].simbolo = '*';
    tela[i+7][j+5].simbolo = '*'; tela[i+7][j+6].simbolo = '*'; tela[i+7][j+7].simbolo = '*';
    tela[i+8][j+6].simbolo = '*';


    for (int k = 0; k < 10; k++){
        for (int l = 0; l < 13; l++){
            tela[i+k][j+l].preenchido = true;
        }
    }
}

// Interceptor

bool Verificar_Espaço_9x11(celula **tela,int i, int j){
    for (int k = 0; k < 11; k++){
        for (int l = 0; l < 13; l++){
            if (tela[i+k][j+l].preenchido == true){
                return false;
            }
        }
    }
    return true;
}

void Carimbo_Interceptor(celula **tela, int i, int j){

    tela[i+1][j+1].simbolo = '*'; tela[i+1][j+11].simbolo = '*';
    tela[i+2][j+1].simbolo = '*'; tela[i+2][j+2].simbolo = '*'; tela[i+2][j+10].simbolo = '*'; tela[i+2][j+11].simbolo = '*';
    tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+10].simbolo = '*'; tela[i+3][j+11].simbolo = '*';
    tela[i+4][j+1].simbolo = '*'; tela[i+4][j+2].simbolo = '*'; tela[i+4][j+3].simbolo = '*'; tela[i+4][j+9].simbolo = '*'; tela[i+4][j+10].simbolo = '*'; tela[i+4][j+11].simbolo = '*';
    tela[i+5][j+1].simbolo = '*'; tela[i+5][j+2].simbolo = '*'; tela[i+5][j+3].simbolo = '*'; tela[i+5][j+4].simbolo = '*'; tela[i+5][j+5].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+7].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+9].simbolo = '*'; tela[i+5][j+10].simbolo = '*'; tela[i+5][j+11].simbolo = '*';
    tela[i+6][j+1].simbolo = '*'; tela[i+6][j+2].simbolo = '*'; tela[i+6][j+3].simbolo = '*'; tela[i+6][j+4].simbolo = '*'; tela[i+6][j+5].simbolo = '*'; tela[i+6][j+6].simbolo = '*'; tela[i+6][j+7].simbolo = '*'; tela[i+6][j+8].simbolo = '*'; tela[i+6][j+9].simbolo = '*'; tela[i+6][j+10].simbolo = '*'; tela[i+6][j+11].simbolo = '*';
    tela[i+7][j+1].simbolo = '*'; tela[i+7][j+2].simbolo = '*'; tela[i+7][j+3].simbolo = '*'; tela[i+7][j+4].simbolo = '*'; tela[i+7][j+5].simbolo = '*'; tela[i+7][j+6].simbolo = '*'; tela[i+7][j+7].simbolo = '*'; tela[i+7][j+8].simbolo = '*'; tela[i+7][j+9].simbolo = '*'; tela[i+7][j+10].simbolo = '*'; tela[i+7][j+11].simbolo = '*';
    tela[i+8][j+1].simbolo = '*'; tela[i+8][j+2].simbolo = '*'; tela[i+8][j+4].simbolo = '*'; tela[i+8][j+5].simbolo = '*'; tela[i+8][j+6].simbolo = '*'; tela[i+8][j+7].simbolo = '*'; tela[i+8][j+8].simbolo = '*'; tela[i+8][j+10].simbolo = '*'; tela[i+8][j+11].simbolo = '*';
    tela[i+9][j+5].simbolo = '*'; tela[i+9][j+6].simbolo = '*'; tela[i+9][j+7].simbolo = '*';



    for (int k = 0; k < 11; k++){
        for (int l = 0; l < 13; l++){
            tela[i+k][j+l].preenchido = true;
        }
    }
}

void Carimbo_Interceptor_Negativo(celula **tela,int i,int j){

    tela[i+1][j+5].simbolo = '*'; tela[i+1][j+6].simbolo = '*'; tela[i+1][j+7].simbolo = '*';
    tela[i+2][j+1].simbolo = '*'; tela[i+2][j+2].simbolo = '*'; tela[i+2][j+4].simbolo = '*'; tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+7].simbolo = '*'; tela[i+2][j+8].simbolo = '*'; tela[i+2][j+10].simbolo = '*'; tela[i+2][j+11].simbolo = '*';
    tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+3].simbolo = '*'; tela[i+3][j+4].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+8].simbolo = '*'; tela[i+3][j+9].simbolo = '*'; tela[i+3][j+10].simbolo = '*'; tela[i+3][j+11].simbolo = '*';
    tela[i+4][j+1].simbolo = '*'; tela[i+4][j+2].simbolo = '*'; tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*'; tela[i+4][j+9].simbolo = '*'; tela[i+4][j+10].simbolo = '*'; tela[i+4][j+11].simbolo = '*';
    tela[i+5][j+1].simbolo = '*'; tela[i+5][j+2].simbolo = '*'; tela[i+5][j+3].simbolo = '*'; tela[i+5][j+4].simbolo = '*'; tela[i+5][j+5].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+7].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+9].simbolo = '*'; tela[i+5][j+10].simbolo = '*'; tela[i+5][j+11].simbolo = '*';
    tela[i+6][j+1].simbolo = '*'; tela[i+6][j+2].simbolo = '*'; tela[i+6][j+3].simbolo = '*'; tela[i+6][j+9].simbolo = '*'; tela[i+6][j+10].simbolo = '*'; tela[i+6][j+11].simbolo = '*';
    tela[i+7][j+1].simbolo = '*'; tela[i+7][j+2].simbolo = '*'; tela[i+7][j+10].simbolo = '*'; tela[i+7][j+11].simbolo = '*';
    tela[i+8][j+1].simbolo = '*'; tela[i+8][j+2].simbolo = '*'; tela[i+8][j+10].simbolo = '*'; tela[i+8][j+11].simbolo = '*';
    tela[i+9][j+1].simbolo = '*'; tela[i+9][j+11].simbolo = '*';


    for (int k = 0; k < 11; k++){
        for (int l = 0; l < 13; l++){
            tela[i+k][j+l].preenchido = true;
        }
    }
}

// Y-Wing

void Carimbo_YWing(celula **tela, int i, int j){

    tela[i+1][j+6].simbolo = '*';
    tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+7].simbolo = '*';
    tela[i+3][j+4].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+8].simbolo = '*';
    tela[i+4][j+2].simbolo = '*'; tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*'; tela[i+4][j+9].simbolo = '*'; tela[i+4][j+10].simbolo = '*';
    tela[i+5][j+1].simbolo = '*'; tela[i+5][j+2].simbolo = '*'; tela[i+5][j+3].simbolo = '*'; tela[i+5][j+4].simbolo = '*'; tela[i+5][j+5].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+7].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+9].simbolo = '*'; tela[i+5][j+10].simbolo = '*'; tela[i+5][j+11].simbolo = '*';
    tela[i+6][j+1].simbolo = '*'; tela[i+6][j+2].simbolo = '*'; tela[i+6][j+3].simbolo = '*'; tela[i+6][j+4].simbolo = '*'; tela[i+6][j+5].simbolo = '*'; tela[i+6][j+6].simbolo = '*'; tela[i+6][j+7].simbolo = '*'; tela[i+6][j+8].simbolo = '*'; tela[i+6][j+9].simbolo = '*'; tela[i+6][j+10].simbolo = '*'; tela[i+6][j+11].simbolo = '*';
    tela[i+7][j+1].simbolo = '*'; tela[i+7][j+2].simbolo = '*'; tela[i+7][j+3].simbolo = '*'; tela[i+7][j+9].simbolo = '*'; tela[i+7][j+10].simbolo = '*'; tela[i+7][j+11].simbolo = '*';
    tela[i+8][j+1].simbolo = '*'; tela[i+8][j+2].simbolo = '*'; tela[i+8][j+3].simbolo = '*'; tela[i+8][j+9].simbolo = '*'; tela[i+8][j+10].simbolo = '*'; tela[i+8][j+11].simbolo = '*';
    tela[i+9][j+1].simbolo = '*'; tela[i+9][j+2].simbolo = '*'; tela[i+9][j+10].simbolo = '*'; tela[i+9][j+11].simbolo = '*';


    for (int k = 0; k < 11; k++){
        for (int l = 0; l < 13; l++){
            tela[i+k][j+l].preenchido = true;
        }
    }
}

void Carimbo_YWing_Negativo(celula **tela,int i, int j){

    tela[i+1][j+1].simbolo = '*'; tela[i+1][j+2].simbolo = '*'; tela[i+1][j+10].simbolo = '*'; tela[i+1][j+11].simbolo = '*';
    tela[i+2][j+1].simbolo = '*'; tela[i+2][j+2].simbolo = '*'; tela[i+2][j+3].simbolo = '*'; tela[i+2][j+9].simbolo = '*'; tela[i+2][j+10].simbolo = '*'; tela[i+2][j+11].simbolo = '*';
    tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+3].simbolo = '*'; tela[i+3][j+9].simbolo = '*'; tela[i+3][j+10].simbolo = '*'; tela[i+3][j+11].simbolo = '*';
    tela[i+4][j+1].simbolo = '*'; tela[i+4][j+2].simbolo = '*'; tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+8].simbolo = '*'; tela[i+4][j+8].simbolo = '*'; tela[i+4][j+9].simbolo = '*'; tela[i+4][j+10].simbolo = '*'; tela[i+4][j+11].simbolo = '*';
    tela[i+5][j+1].simbolo = '*'; tela[i+5][j+2].simbolo = '*'; tela[i+5][j+3].simbolo = '*'; tela[i+5][j+4].simbolo = '*'; tela[i+5][j+5].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+9].simbolo = '*'; tela[i+5][j+10].simbolo = '*'; tela[i+5][j+11].simbolo = '*';
    tela[i+6][j+2].simbolo = '*'; tela[i+6][j+3].simbolo = '*'; tela[i+6][j+4].simbolo = '*'; tela[i+6][j+5].simbolo = '*'; tela[i+6][j+6].simbolo = '*'; tela[i+6][j+7].simbolo = '*'; tela[i+6][j+9].simbolo = '*'; tela[i+6][j+9].simbolo = '*'; tela[i+6][j+10].simbolo = '*';
    tela[i+7][j+4].simbolo = '*'; tela[i+7][j+5].simbolo = '*'; tela[i+7][j+6].simbolo = '*'; tela[i+7][j+7].simbolo = '*'; tela[i+7][j+8].simbolo = '*';
    tela[i+8][j+5].simbolo = '*'; tela[i+8][j+6].simbolo = '*'; tela[i+8][j+7].simbolo = '*';
    tela[i+9][j+6].simbolo = '*';


    for (int k = 0; k < 11; k++){
        for (int l = 0; l < 13; l++){
            tela[i+k][j+l].preenchido = true;
        }
    }
}

//Star Fighter N1

bool Verificar_Espaço_N1(celula **tela,int i, int j){
    for (int k = 0; k < 8; k++){
        for (int l = 0; l < 11; l++){
            if (tela[i+k][j+l].preenchido == true){
                return false;
            }
        }
    }
    return true;
}

void Carimbo_N1(celula **tela, int i, int j){

    tela[i+1][j+5].simbolo = '*';
    tela[i+2][j+4].simbolo = '*'; tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*';
    tela[i+3][j+2].simbolo = '*'; tela[i+3][j+3].simbolo = '*'; tela[i+3][j+4].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+8].simbolo = '*';
    tela[i+4][j+1].simbolo = '*'; tela[i+4][j+2].simbolo = '*'; tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*'; tela[i+4][j+9].simbolo = '*';
    tela[i+5][j+1].simbolo = '*'; tela[i+5][j+2].simbolo = '*'; tela[i+5][j+4].simbolo = '*'; tela[i+5][j+5].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+9].simbolo = '*';
    tela[i+6][j+1].simbolo = '*'; tela[i+6][j+5].simbolo = '*'; tela[i+6][j+9].simbolo = '*';


    for (int k = 0; k < 8; k++){
        for (int l = 0; l < 11; l++){
            tela[i+k][j+l].preenchido = true;
        }
    }   
}

void Carimbo_N1_Negativo(celula **tela,int i,int j){

    tela[i+1][j+1].simbolo = '*'; tela[i+1][j+5].simbolo = '*'; tela[i+1][j+9].simbolo = '*';
    tela[i+2][j+1].simbolo = '*'; tela[i+2][j+2].simbolo = '*'; tela[i+2][j+4].simbolo = '*'; tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+8].simbolo = '*'; tela[i+2][j+9].simbolo = '*';
    tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+3].simbolo = '*'; tela[i+3][j+4].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+8].simbolo = '*'; tela[i+3][j+9].simbolo = '*';
    tela[i+4][j+2].simbolo = '*'; tela[i+4][j+3].simbolo = '*'; tela[i+4][j+4].simbolo = '*'; tela[i+4][j+5].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*';
    tela[i+5][j+4].simbolo = '*'; tela[i+5][j+5].simbolo = '*'; tela[i+5][j+6].simbolo = '*';
    tela[i+6][j+5].simbolo = '*';

    for (int k = 0; k < 8; k++){
        for (int l = 0; l < 11; l++){
            tela[i+k][j+l].preenchido = true;
        }
    }
}

//X-Wing

void Carimbo_XWing(celula **tela, int i, int j){

    tela[i+1][j+1].simbolo = '*'; tela[i+1][j+2].simbolo = '*'; tela[i+1][j+12].simbolo = '*'; tela[i+1][j+13].simbolo = '*';
    tela[i+2][j+1].simbolo = '*'; tela[i+2][j+2].simbolo = '*'; tela[i+2][j+12].simbolo = '*'; tela[i+2][j+13].simbolo = '*'; 
    tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+12].simbolo = '*'; tela[i+3][j+13].simbolo = '*';
    tela[i+4][j+1].simbolo = '*'; tela[i+4][j+2].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*'; tela[i+4][j+12].simbolo = '*'; tela[i+4][j+13].simbolo = '*';
    tela[i+5][j+1].simbolo = '*'; tela[i+5][j+2].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+7].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+12].simbolo = '*'; tela[i+5][j+13].simbolo = '*';
    tela[i+6][j+1].simbolo = '*'; tela[i+6][j+2].simbolo = '*'; tela[i+6][j+6].simbolo = '*'; tela[i+6][j+7].simbolo = '*'; tela[i+6][j+8].simbolo = '*'; tela[i+6][j+12].simbolo = '*'; tela[i+6][j+13].simbolo = '*';
    tela[i+7][j+1].simbolo = '*'; tela[i+7][j+2].simbolo = '*'; tela[i+7][j+5].simbolo = '*'; tela[i+7][j+6].simbolo = '*'; tela[i+7][j+7].simbolo = '*'; tela[i+7][j+8].simbolo = '*'; tela[i+7][j+9].simbolo = '*'; tela[i+7][j+12].simbolo = '*'; tela[i+7][j+13].simbolo = '*';
    tela[i+8][j+1].simbolo = '*'; tela[i+8][j+2].simbolo = '*'; tela[i+8][j+3].simbolo = '*'; tela[i+8][j+4].simbolo = '*'; tela[i+8][j+5].simbolo = '*'; tela[i+8][j+6].simbolo = '*'; tela[i+8][j+7].simbolo = '*'; tela[i+8][j+8].simbolo = '*'; tela[i+8][j+9].simbolo = '*'; tela[i+8][j+10].simbolo = '*'; tela[i+8][j+11].simbolo = '*'; tela[i+8][j+12].simbolo = '*'; tela[i+8][j+13].simbolo = '*';
    tela[i+9][j+6].simbolo = '*'; tela[i+9][j+7].simbolo = '*'; tela[i+9][j+8].simbolo = '*';

    
    for (int k = 0; k < 11; k++){
        for (int l = 0; l < 15; l++){
            tela[i+k][j+l].preenchido = true;
        }
    }
}

void Carimbo_XWing_Negativo(celula **tela, int i, int j){

    tela[i+1][j+6].simbolo = '*'; tela[i+1][j+7].simbolo = '*'; tela[i+1][j+8].simbolo = '*';
    tela[i+2][j+1].simbolo = '*'; tela[i+2][j+2].simbolo = '*'; tela[i+2][j+3].simbolo = '*'; tela[i+2][j+4].simbolo = '*'; tela[i+2][j+5].simbolo = '*'; tela[i+2][j+6].simbolo = '*'; tela[i+2][j+7].simbolo = '*'; tela[i+2][j+8].simbolo = '*'; tela[i+2][j+9].simbolo = '*'; tela[i+2][j+10].simbolo = '*'; tela[i+2][j+11].simbolo = '*'; tela[i+2][j+12].simbolo = '*'; tela[i+2][j+13].simbolo = '*';
    tela[i+3][j+1].simbolo = '*'; tela[i+3][j+2].simbolo = '*'; tela[i+3][j+5].simbolo = '*'; tela[i+3][j+6].simbolo = '*'; tela[i+3][j+7].simbolo = '*'; tela[i+3][j+8].simbolo = '*'; tela[i+3][j+9].simbolo = '*'; tela[i+3][j+12].simbolo = '*'; tela[i+3][j+13].simbolo = '*';
    tela[i+4][j+1].simbolo = '*'; tela[i+4][j+2].simbolo = '*'; tela[i+4][j+6].simbolo = '*'; tela[i+4][j+7].simbolo = '*'; tela[i+4][j+8].simbolo = '*'; tela[i+4][j+12].simbolo = '*'; tela[i+4][j+13].simbolo = '*';
    tela[i+5][j+1].simbolo = '*'; tela[i+5][j+2].simbolo = '*'; tela[i+5][j+6].simbolo = '*'; tela[i+5][j+7].simbolo = '*'; tela[i+5][j+8].simbolo = '*'; tela[i+5][j+12].simbolo = '*'; tela[i+5][j+13].simbolo = '*';
    tela[i+6][j+1].simbolo = '*'; tela[i+6][j+2].simbolo = '*'; tela[i+6][j+7].simbolo = '*'; tela[i+6][j+12].simbolo = '*'; tela[i+6][j+13].simbolo = '*';
    tela[i+7][j+1].simbolo = '*'; tela[i+7][j+2].simbolo = '*'; tela[i+7][j+12].simbolo = '*'; tela[i+7][j+13].simbolo = '*';
    tela[i+8][j+1].simbolo = '*'; tela[i+8][j+2].simbolo = '*'; tela[i+8][j+12].simbolo = '*'; tela[i+8][j+13].simbolo = '*';
    tela[i+9][j+1].simbolo = '*'; tela[i+9][j+2].simbolo = '*'; tela[i+9][j+12].simbolo = '*'; tela[i+9][j+13].simbolo = '*';


    for (int k = 0; k < 11; k++){
        for (int l = 0; l < 15; l++){
            tela[i+k][j+l].preenchido = true;
        }
    }
}

bool Carimbar_Nave(celula** tela,int nave,int x, int y,int index){
    bool carimbado = false;
    int direcao = index %2;
        switch (nave){
        case 0:
            if (Verificar_Espaço_StarDestroyer(tela,x,y)){
                if(direcao == 0){
                    Carimbo_StarDestroyer(tela,x,y);
                }
                else{
                    Carimbo_StarDestroyer_Negativo(tela,x,y);
                }
                carimbado = true;
            }
            break;
        
        case 1:
            if (Verificar_Espaço_9x13(tela,x,y)){
                if(direcao == 0){
                    Carimbo_Fighter(tela,x,y);
                }
                else{
                    Carimbo_Fighter_Negativo(tela,x,y);
                }
                carimbado = true;
            }
        break;

        case 2:
            if (Verificar_Espaço_AWing(tela,x,y)){
                if(direcao == 0){
                    Carimbo_AWing(tela,x,y);
                }
                else{
                    Carimbo_AWing_Negativo(tela,x,y);
                }
                carimbado = true;
            }
        break;

        case 3:
            if (Verificar_Espaço_9x11(tela,x,y)){
                if(direcao == 0){
                    Carimbo_Interceptor(tela,x,y);
                }
                else{
                    Carimbo_Interceptor_Negativo(tela,x,y);
                }
                carimbado = true;
            }
        break;

        case 4:
            if (Verificar_Espaço_9x11(tela,x,y)){
                if(direcao == 0){
                    Carimbo_YWing(tela,x,y);
                }
                else{
                    Carimbo_YWing_Negativo(tela,x,y);
                }
                carimbado = true;
            }
        break;

        case 5:
            if (Verificar_Espaço_N1(tela,x,y)){
                if(direcao == 0){
                    Carimbo_N1(tela,x,y);
                }
                else{
                    Carimbo_N1_Negativo(tela,x,y);
                }
                carimbado = true;
            }
        break;

        case 6:
            if (Verificar_Espaço_9x13(tela,x,y)){
                if(direcao == 0){
                    Carimbo_XWing(tela,x,y);
                }
                else{
                    Carimbo_XWing_Negativo(tela,x,y);
                }
                carimbado = true;
            }
        break;       
    }
    return carimbado;
}