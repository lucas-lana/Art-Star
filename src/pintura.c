#include <string.h>
#include "pintura.h"

/*
 * Quadro_Branco
 *
 * Inicializa a tela com um quadro branco, onde as bordas são representadas por '-' e '|', e o interior é preenchido com espaços em branco.
 *
 * Parâmetros:
 * - celula **tela: A tela a ser inicializada.
 * - int linhas: O número de linhas da tela.
 * - int colunas: O número de colunas da tela.
*/
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


/*
 * Get_Coordenada
 *
 * Gera uma coordenada (x ou y) baseada em uma semente, um índice e uma equação específica.
 * 
 * Parâmetros:
 * - int linhas: O número total de linhas na tela.
 * - int colunas: O número total de colunas na tela.
 * - int seed: A semente para a geração de números aleatórios.
 * - int i: O índice atual, usado para variar a geração.
 * - int old_coordenada: A coordenada anterior gerada, usada para influenciar a nova coordenada.
 * - bool tipo: Indica se a coordenada a ser gerada é X (false) ou Y (true).
 * - int equacao: O número da equação a ser usada para a geração (1 a 4).
 * 
 * Output:
 * - int: A coordenada gerada, garantida para estar dentro dos limites especificados.
*/
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


/*
 * Carimbar
 *
 * Aplica carimbos na tela com base em vários parâmetros, incluindo o tipo de carimbo, a quantidade de carimbos a serem aplicados, e a lógica de posicionamento.
 *
 * Parâmetros:
 * - celula** tela: A tela onde os carimbos serão aplicados.
 * - ConjuntoCarimbos* carimbosPasta: Um array de conjuntos de carimbos disponíveis.
 * - int numPastas: O número de pastas de carimbos disponíveis.
 * - int linhas: O número total de linhas na tela.
 * - int colunas: O número total de colunas na tela.
 * - int seed: A semente para a geração de números aleatórios.
 * - int carimbo: O tipo de carimbo a ser aplicado (1 para Estrela, 2 para Soma, 3 para X, 4 para Aleatório, 5 para Naves).
 * - int carimbadas: O número total de carimbos a serem aplicados.
 * - int equacao: O número da equação a ser usada para a geração de coordenadas (1 a 4).
 * - int index: O índice inicial para a geração de coordenadas.
 * 
 * Output:
 * - long int: O número total de tentativas feitas para aplicar os carimbos, subtraído do número de carimbos efetivamente aplicados.
*/
long int Carimbar(celula** tela,ConjuntoCarimbos*DirCarimbos,int linhas, int colunas, int seed,int carimbo,int carimbadas,int equacao,int index){
    long int guarda = 0;
    int loop = 0;
    int limear = pow(2,((sizeof(int)*4)));
    int x,y,old_x,old_y;
    int reset = 0;

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
                case 2:
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

                case 3:
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

                case 4:
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
            
                case 5:
                    int carimbo_random = rand() % 3;
                    bool carimbado_Aleatorio = Carimbo_Aleatorio(tela,linhas,colunas,x,y,carimbo_random);
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

                default:
                    bool carimbado_desenho = Carimbar_Desenho(tela,DirCarimbos[carimbo - FEATURES].carimbos,linhas, colunas,(seed + index) % (DirCarimbos[carimbo - FEATURES].quantidade),x,y,(index%2));
                    if (carimbado_desenho){
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

/*
 * Imprimir_Quadro
 *
 * Imprime a tela no console, com a opção de usar cores para diferentes símbolos.
 *
 * Parâmetros:
 * - celula **tela: A tela a ser impressa.
 * - int linhas: O número de linhas da tela.
 * - int colunas: O número de colunas da tela.
 * - bool colorido: Indica se a impressão deve ser colorida (true) ou em preto e branco (false).
*/
void Imprimir_Quadro(celula **tela, int linhas, int colunas,bool colorido){
    system("clear");
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


/*
 * imprime_char_colorido
 *
 * Imprime um caractere com uma cor específica baseada no símbolo fornecido.
 *
 * Parâmetros:
 * - char c: O caractere a ser impresso.
*/
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

/*
 * imprime_elemento
 *
 * Imprime um carimbo (desenho) no console, com a opção de usar cores para diferentes símbolos.
 *
 * Parâmetros:
 * - char** carimbo: O carimbo (desenho) a ser impresso.
 * - int linhas: O número de linhas do carimbo.
 * - int colunas: O número de colunas do carimbo.
 * - bool colorido: Indica se a impressão deve ser colorida (true) ou em preto e branco (false).
*/
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

/*
 * limite_desenho
 *
 * Calcula o limite máximo recomendado de desenhos que podem ser aplicados na tela com base no maior carimbo disponível em uma pasta específica.
 * 
 * Parâmetros:
 * - ConjuntoCarimbos* Pastas: Um array de conjuntos de carimbos disponíveis.
 * - int numPastas: O número de pastas de carimbos disponíveis.
 * - char* nomePasta: O nome da pasta específica para a qual o limite deve ser calculado.
 * - int linhas: O número total de linhas na tela.
 * - int colunas: O número total de colunas na tela.
 * 
 * Output:
 * - int: O limite máximo recomendado de desenhos que podem ser aplicados na tela.
*/
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

void Imprime_Desenho(Carimbo* desenho){

    if (desenho == NULL) {
        printf("Desenho invalido\n");
        return;
    }

    celula **tela = (celula**)malloc((desenho->ordem[0]+2)*sizeof(celula*));
    for (int i = 0; i < desenho->ordem[0]+2; i++){
        tela[i] = (celula*)malloc((desenho->ordem[1]+2)*sizeof(celula));
    }

    Quadro_Branco(tela,desenho->ordem[0]+2,desenho->ordem[1]+2);
    for (int i = 0; i < desenho->ordem[0]; i++){
        for (int j = 0; j < desenho->ordem[1]; j++){
            if (desenho->desenho[i][j] != ' '){
                tela[i+1][j+1].simbolo = desenho->desenho[i][j];
            }
        }
    }
    Imprimir_Quadro(tela,desenho->ordem[0]+2,desenho->ordem[1]+2,false);
    for (int i = 0; i < desenho->ordem[0]+2; i++){
        free(tela[i]);
    }
    free(tela);
}