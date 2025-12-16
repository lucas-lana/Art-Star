#include "carimbos.h"
#include <dirent.h>
#include <sys/stat.h>

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
