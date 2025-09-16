#include <string.h>
#include "carimbos.c"

void Quadro_Branco(celula **tela, int linhas, int colunas){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (i == 0 || i == linhas - 1){
                tela[i][j].simbolo = '-';
                tela[i][j].preenchido = true;
            }
            else if ((j == 0 || j == colunas - 1) && i != 0 && i != linhas - 1){
                tela[i][j].simbolo = '|';
                tela[i][j].preenchido = true;
            }
            else{
                tela[i][j].simbolo = ' ';
                tela[i][j].preenchido = false;
            }
        }
    }
}

int Get_Coordenada(int linhas, int colunas,int seed,int i,int old_coordenada,bool tipo,int equacao){ // Necessário melhorar a formula de geração de coordenadas
    int coordenada;
    
    if (!tipo){ // Coordenada X
        if (i == 0)
            coordenada = seed % linhas;
        else 

            switch (equacao) {
            case 1:
                 // Fórmula muito boa, funciona sempre, media repetições, bem aleatório
                coordenada = ((old_coordenada*i*((old_coordenada+seed)%i)) + seed + i)%linhas;
                break;

            case 2:
                // Fórmula muito boa, funciona sempre, media repetições, bem aleatório
                coordenada = ((old_coordenada*i*(old_coordenada%i)) + seed + i)%linhas;
                break;

            case 3:
                // Fórmula muito boa, funciona sempre, media repetições, bem aleatório
                coordenada = ((old_coordenada*i*(i%linhas)) + seed + i)%linhas;
                break;

            case 4:
                // Formula boa, funciona sempre, poucas repetições, mas pouco aleatório
                coordenada = ((old_coordenada*i*linhas) + seed + i)%linhas;
                break;
            
            default:
                break;
            }
    }

    else{ // Coordenada Y
        if (i == 0)
            coordenada = seed % colunas;
        else

            switch (equacao) {
            case 1:
                // Fórmula muito boa, funciona sempre, media repetições, bem aleatório
                coordenada = ((old_coordenada*i*((old_coordenada+seed)%i)) + seed + i)%colunas;
                break;
            
            case 2:
                // Fórmula muito boa, funciona sempre, media repetições, bem aleatório
                coordenada = ((old_coordenada*i*(old_coordenada%i)) + seed + i)%colunas;
                break;

            case 3:
                // Fórmula muito boa, funciona sempre, media repetições, bem aleatório
                coordenada = ((old_coordenada*i*(i%colunas)) + seed + i)%colunas;
                break;

            case 4:
                // Formula boa, funciona sempre, poucas repetições, mas pouco aleatório
                coordenada = ((old_coordenada*i*colunas) + seed + i)%colunas;
                break;
            
            default:
                break;
            }
    }
    if (coordenada < 0){
        coordenada = coordenada * -1;
    }
    else if (coordenada == 0){
        coordenada = 1;
    }
    return coordenada;
}

long int Carimbar(celula** tela,ConjuntoCarimbos* carimbosPasta,int numPastas,int linhas, int colunas, int seed,int carimbo,int carimbadas,int equacao,int index){
    long int guarda = 0;
    int loop = 0;
    int limear = pow(2,((sizeof(int)*4)));
    int x,y,old_x,old_y;
    int reset = 0;

    int jndex = 0;
    while(1){
        if (strcmp(carimbosPasta[jndex].nomePasta, "Naves") == 0){
            break;
        }
        jndex++;
        if (jndex > numPastas){
            return -1;
        }
    }

    while (loop < carimbadas){

        if (index >= limear && reset < 2){ 
            
            guarda += index;
            index = 1;

            if (reset == 0){
                equacao = 4;
                reset++;
            }
            
            else {
                equacao = 2;
                reset++;
            }
        }
        else if (reset >= 2){
            return (guarda + index) - carimbadas;
        }

        if (!((old_x == 0 || old_y == 0) || (old_x == linhas || old_y == colunas))){


            x = Get_Coordenada(linhas,colunas,seed,index,old_x,false,equacao);
            y = Get_Coordenada(linhas,colunas,seed,index,old_y,true,equacao);

            switch (carimbo){
                case 1:
                    if (tela[x][y].preenchido == false){
                        Carimbo_Estrela(tela,x,y);
                        old_x = x;
                        old_y = y;
                        index++;
                        loop++;
                        
                    } else{
                        x = Get_Coordenada(linhas,colunas,seed,index,old_x,false,equacao);
                        y = Get_Coordenada(linhas,colunas,seed,index,old_y,true,equacao);
                        old_x = x;
                        old_y = y;
                        
                        index++;
                    }
                break;

                case 2:
                    if (Verificar_3x3(tela,x,y,linhas,colunas)){
                        Carimbo_Soma(tela,x,y);
                        old_x = x;
                        old_y = y;
                        index++;
                        loop++;
                        
                    } else{
                        x = Get_Coordenada(linhas,colunas,seed,index,old_x,false,equacao);
                        y = Get_Coordenada(linhas,colunas,seed,index,old_y,true,equacao);
                        old_x = x;
                        old_y = y;
                        
                        index++;
                        
                    }
                break;

                case 3:
                    if (Verificar_3x3(tela,x,y,linhas,colunas)){
                        Carimbo_X(tela,x,y);
                        old_x = x;
                        old_y = y;
                        index++;
                        loop++;
                        
                    } else{
                        x = Get_Coordenada(linhas,colunas,seed,index,old_x,false,equacao);
                        y = Get_Coordenada(linhas,colunas,seed,index,old_y,true,equacao);
                        old_x = x;
                        old_y = y;
                        
                        index++;
                    }
                break;
            
                case 4:
                    int carimbo = rand() % 3;
                    bool carimbado_Aleatorio = Carimbo_Aleatorio(tela,linhas,colunas,x,y,carimbo);
                    if (carimbado_Aleatorio){
                        old_x = x;
                        old_y = y;
                        index++;
                        loop++;
                        
                    } else{
                        x = Get_Coordenada(linhas,colunas,seed,index,old_x,false,equacao);
                        y = Get_Coordenada(linhas,colunas,seed,index,old_y,true,equacao);
                        old_x = x;
                        old_y = y;
                        
                        index++;
                    }
                break;

                case 5:
                    bool carimbado_Nave = Carimbar_Desenho(tela,carimbosPasta[jndex].carimbos,linhas, colunas,((seed + index) % 6),x,y,(index%2));
                    if (carimbado_Nave){
                        old_x = x;
                        old_y = y;
                        index++;
                        loop++;
                        
                    } else{
                        x = Get_Coordenada(linhas,colunas,seed,index,old_x,false,equacao);
                        y = Get_Coordenada(linhas,colunas,seed,index,old_y,true,equacao);
                        old_x = x;
                        old_y = y;
                        
                        index++;
                    }
                break;
                default:
                break;
            }
        }

        else {
            x = Get_Coordenada(linhas,colunas,seed,index,old_x,false,equacao);
            y = Get_Coordenada(linhas,colunas,seed,index,old_y,true,equacao);
            old_x = x;
            old_y = y;
        }
    }
    return (guarda + index) - carimbadas;
}


void Imprimir_Quadro(celula **tela, int linhas, int colunas,bool colorido){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (colorido) {
                imprime_char_colorido(tela[i][j].simbolo);
            } else {
                printf("%c", tela[i][j].simbolo);
            }
        }
        printf("\n");
    }
}

void imprime_char_colorido(char c) {

    if (c == '*') {
        //Definir cor branca
        printf("*");
    }

    else if (c == '#') {
        //Definir cor vermelho
        printf("\033[31m*\033[0m");
    }

    else if (c == '$') {
        //Definir cor verde
        printf("\033[32m*\033[0m");
    }

    else if (c == '%') {
        //Definir cor azul
        printf("\033[34m*\033[0m");   
    }

    else if (c == '&') {
        //Definir cor amarela
        printf("\033[33m*\033[0m");
    }

    else if (c == '^') {
        //Definir cor magenta
        printf("\033[35m*\033[0m");   
    }

    else if (c == '@') {
        //Definir cor ciano
        printf("\033[36m*\033[0m");
    }

    else if (c == '~') {
        //Definir cor preta
        printf("\033[30m*\033[0m");   
    }

    else if (c == '|') {
        printf("|");   
    }

    else if (c == '-') {
        printf("-");   
    }

    else {
        printf(" ");
    }
}

void imprime_elemento(char** carimbo,int linhas,int colunas,bool colorido) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            if (colorido) {
                imprime_char_colorido(carimbo[i][j]);
            } else {
                printf("%c", carimbo[i][j]);
            }
        }
        printf("\n");
    }
}

int limite_desenho(ConjuntoCarimbos* Pastas,int numPastas,char* nomePasta,int linhas,int colunas){
    int ordem_max = 0;
    ConjuntoCarimbos* desenhos;
    for (int i = 0; i < numPastas; i++) {
        if (strcmp(Pastas[i].nomePasta, nomePasta) == 0) {
            desenhos = &Pastas[i];
            break;
        }
    }

    for (int i = 0; i < desenhos->quantidade; i++){
        int ordem_atual = desenhos->carimbos[i].ordem[0] * desenhos->carimbos[i].ordem[1];
        if (ordem_atual >= ordem_max)
            ordem_max = ordem_atual;
    }
    return (linhas * colunas / ordem_max)/2;
}