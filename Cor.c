#include <stdio.h>
#include <stdlib.h>

void pincel_Cor(char **tela,int linhas, int colunas) {
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

            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}