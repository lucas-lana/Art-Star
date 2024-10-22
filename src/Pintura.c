#include "naves.c"

void Quadro_Branco( celula tela[LINHAS][COLUNAS]){
    for (int i = 0; i < LINHAS; i++){
        for (int j = 0; j < COLUNAS; j++){
            if (i == 0 || i == LINHAS - 1){
                tela[i][j].simbolo = '-';
                tela[i][j].preenchido = true;
            }
            else if ((j == 0 || j == COLUNAS - 1) && i != 0 && i != LINHAS - 1){
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

void Quadro_Branco_Individual( celula **tela, int linhas, int colunas){
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
                    
            //coordenada = ((old_coordenada*i) + seed + i)%20; // Formula quase boa, funciona sempre, mas muitas repetições, bem aleatório

            /*Formula menos ruim(Execente em termos de poucas vezes repetidas, até n)
            N dependendo da forma, se for uma forma maior, n = 15, se for uma forma menor, n = 50*/
            //coordenada = (old_coordenada + seed + i)%20;

            //coordenada = ((old_coordenada*i)+seed)%20;// Fórmula mais ou menos
            
            //coordenada = (old_coordenada + seed)%20;// Fórmula ruim
            //coordenada = (old_coordenada+(seed/20))%20;// Fórmula horrível
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
            
            //coordenada = ((old_coordenada*i) + seed + i)%80; // Formula quase boa, funciona sempre, mas muitas repetições, bem aleatório

            /*Formula menos ruim(Execente em termos de poucas vezes repetidas, até n)
            N dependendo da forma, se for uma forma maior, n = 15, se for uma forma menor, n = 50*/
            //coordenada = (old_coordenada + seed + i)%80;

            //coordenada = ((old_coordenada*i)+seed)%80;// Fórmula mais ou menos
            
            //coordenada = (old_coordenada + seed)%80;// Fórmula ruim
            //coordenada = (old_coordenada+(seed/80))%80; // Fórmula horrível
    }
    if (coordenada < 0){
        coordenada = coordenada * -1;
    }
    else if (coordenada == 0){
        coordenada = 1;
    }
    return coordenada;
}

long int Carimbar(celula tela [LINHAS][COLUNAS],int seed,int carimbo,int carimbadas,int equacao,int index){
    long int guarda = 0;
    int loop = 0;
    int limear = pow(2,((sizeof(int)*6)));
    int x,y,old_x,old_y;

    while (loop < carimbadas){

        if (index >= limear){
            guarda += index;
            index = 1;
            loop = 0;
            Quadro_Branco(tela);
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
                    if (Verificar_Espaço(tela,x,y)){
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
                    if (Verificar_Espaço(tela,x,y)){
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
                    bool carimbado_Aleatorio = Carimbo_Aleatorio(tela,x,y,carimbo);
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
                    int nave = (seed + index) % 7;
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

void Imprimir_Quadro(celula tela [LINHAS][COLUNAS]){
    for (int i = 0; i < LINHAS; i++){
        for (int j = 0; j < COLUNAS; j++){
            printf("%c",tela[i][j].simbolo);
        }
        printf("\n");
    }
}

void Imprimir_Quadro_Individual(celula **tela, int linhas, int colunas){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("%c",tela[i][j].simbolo);
        }
        printf("\n");
    }
}