#include "naves.c"

/*  
Testar adicionar mais uma troca de equação

Testar modificar a forma de alteração de equação

*/



void Quadro_Branco( celula **tela, int linhas, int colunas){
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

int Get_Coordenada(int seed,int i,int old_coordenada,bool tipo,int equacao){ // Necessário melhorar a formula de geração de coordenadas
    int coordenada;
    
    if (!tipo){ // Coordenada X
        if (i == 0)
            coordenada = seed % LINHAS;
        else 

            switch (equacao) {
            case 1:
                 // Fórmula muito boa, funciona sempre, media repetições, bem aleatório
                coordenada = ((old_coordenada*i*((old_coordenada+seed)%i)) + seed + i)%LINHAS;
                break;

            case 2:
                // Fórmula muito boa, funciona sempre, media repetições, bem aleatório
                coordenada = ((old_coordenada*i*(old_coordenada%i)) + seed + i)%LINHAS;
                break;

            case 3:
                // Fórmula muito boa, funciona sempre, media repetições, bem aleatório
                coordenada = ((old_coordenada*i*(i%LINHAS)) + seed + i)%LINHAS;
                break;

            case 4:
                // Formula boa, funciona sempre, poucas repetições, mas pouco aleatório
                coordenada = ((old_coordenada*i*LINHAS) + seed + i)%LINHAS;
                break;
            
            default:
                break;
            }
    }

    else{ // Coordenada Y
        if (i == 0)
            coordenada = seed % COLUNAS;
        else

            switch (equacao) {
            case 1:
                // Fórmula muito boa, funciona sempre, media repetições, bem aleatório
                coordenada = ((old_coordenada*i*((old_coordenada+seed)%i)) + seed + i)%COLUNAS;
                break;
            
            case 2:
                // Fórmula muito boa, funciona sempre, media repetições, bem aleatório
                coordenada = ((old_coordenada*i*(old_coordenada%i)) + seed + i)%COLUNAS;
                break;

            case 3:
                // Fórmula muito boa, funciona sempre, media repetições, bem aleatório
                coordenada = ((old_coordenada*i*(i%COLUNAS)) + seed + i)%COLUNAS;
                break;

            case 4:
                // Formula boa, funciona sempre, poucas repetições, mas pouco aleatório
                coordenada = ((old_coordenada*i*COLUNAS) + seed + i)%COLUNAS;
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

long int Carimbar(celula** tela,int linhas, int colunas, int seed,int carimbo,int carimbadas,int equacao,int index){
    long int guarda = 0;
    int loop = 0;
    int limear = pow(2,((sizeof(int)*6)));
    int x,y,old_x,old_y;
    int nave;

    while (loop < carimbadas){

        if (index >= limear){
            guarda += index;
            index = 1;
            loop = 0;
            Quadro_Branco(tela,linhas,colunas);
            equacao = 4;
        }
        
        if (!((old_x == 0 || old_y == 0) || (old_x == LINHAS || old_y == COLUNAS))){


            x = Get_Coordenada(seed,index,old_x,false,equacao);
            y = Get_Coordenada(seed,index,old_y,true,equacao);

            switch (carimbo){
                case 1:
                    if (tela[x][y].preenchido == false){
                        Carimbo_Estrela(tela,x,y);
                        old_x = x;
                        old_y = y;
                        index++;
                        loop++;
                        
                    } else{
                        x = Get_Coordenada(seed,index,old_x,false,equacao);
                        y = Get_Coordenada(seed,index,old_y,true,equacao);
                        old_x = x;
                        old_y = y;
                        
                        index++;
                    }
                break;

                case 2:
                    if (Verificar_Espaço(tela,linhas,colunas,x,y)){
                        Carimbo_Soma(tela,x,y);
                        old_x = x;
                        old_y = y;
                        index++;
                        loop++;
                        
                    } else{
                        x = Get_Coordenada(seed,index,old_x,false,equacao);
                        y = Get_Coordenada(seed,index,old_y,true,equacao);
                        old_x = x;
                        old_y = y;
                        
                        index++;
                    }
                break;

                case 3:
                    if (Verificar_Espaço(tela,linhas,colunas,x,y)){
                        Carimbo_X(tela,x,y);
                        old_x = x;
                        old_y = y;
                        index++;
                        loop++;
                        
                    } else{
                        x = Get_Coordenada(seed,index,old_x,false,equacao);
                        y = Get_Coordenada(seed,index,old_y,true,equacao);
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
                        x = Get_Coordenada(seed,index,old_x,false,equacao);
                        y = Get_Coordenada(seed,index,old_y,true,equacao);
                        old_x = x;
                        old_y = y;
                        
                        index++;
                    }
                break;

                case 5:
                    nave = (seed + index) % 6;
                    bool carimbado_Nave = Carimbar_Nave(tela,nave,x,y,index);
                    if (carimbado_Nave){
                        old_x = x;
                        old_y = y;
                        index++;
                        loop++;
                        
                    } else{
                        x = Get_Coordenada(seed,index,old_x,false,equacao);
                        y = Get_Coordenada(seed,index,old_y,true,equacao);
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
            x = Get_Coordenada(seed,index,old_x,false,equacao);
            y = Get_Coordenada(seed,index,old_y,true,equacao);
            old_x = x;
            old_y = y;
        }
    }
    return (guarda + index) - carimbadas;
}


void Imprimir_Quadro(celula **tela, int linhas, int colunas){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (tela[i][j].simbolo == ' ')
                printf(" ");
            else if (tela[i][j].simbolo == '|')
                printf("|");
            else if (tela[i][j].simbolo == '-')
                printf("-");
            else 
                printf("*");
        };
        printf("\n");
    }
}

void Imprimir_Quadro_Cor(char **tela,int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {

            if (tela[i][j] == '*') {
                //Definir cor branca
                printf("*");
            }

            else if (tela[i][j] == '#') {
                //Definir cor vermelho
                printf("\033[31m*\033[0m");
            }

            else if (tela[i][j] == '$') {
                //Definir cor verde
                printf("\033[32m*\033[0m");
            }

            else if (tela[i][j] == '%') {
                //Definir cor azul
                printf("\033[34m*\033[0m");   
            }

            else if (tela[i][j] == '&') {
                //Definir cor amarela
                printf("\033[33m*\033[0m");
            }

            else if (tela[i][j] == '^') {
                //Definir cor magenta
                printf("\033[35m*\033[0m");   
            }

            else if (tela[i][j] == '@') {
                //Definir cor ciano
                printf("\033[36m*\033[0m");
            }

            else if (tela[i][j] == '~') {
                //Definir cor preta
                printf("\033[30m*\033[0m");   
            }

            else if (tela[i][j] == '|') {
                printf("|");   
            }
            
            else if (tela[i][j] == '-') {
                printf("-");   
            }

            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}