#include "carimbos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#define CAMINHO "/home/Lucas/Documentos/Codes/C/Trabalhos/Art-Star/carimbos"

typedef struct {
    char texto[254];
    char *nome;
}Arquivo;

int get_numDir(char* caminhoRaiz);
int* get_dim_Carimbo(char* texto);
char* ler_carimbo(char* caminho);
Arquivo* acessar_Diretorio(char* caminho);
Carimbos_Num* get_Carimbos(char* caminho);
ConjuntoCarimbos* carrega_Carimbos(int numPastas, char* caminho);
