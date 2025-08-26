#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "arquivos.h"

#include "carimbos.h"

char* ler_carimbo(char* caminho) {
    FILE* leitor = fopen(caminho, "r");
    if (leitor == NULL) {
        printf("Não foi possível abrir o arquivo: %s\n", caminho);
        return NULL;
    }

    // Get file size
    fseek(leitor, 0, SEEK_END);
    long file_size = ftell(leitor);
    fseek(leitor, 0, SEEK_SET);

    if (file_size <= 0) {
        fclose(leitor);
        return strdup(""); // Return empty string for empty file
    }

    // Allocate buffer (+1 for null terminator)
    char* texto = malloc(file_size + 1);
    if (texto == NULL) {
        fclose(leitor);
        printf("Erro ao alocar memória\n");
        return NULL;
    }

    // Read entire file
    size_t bytes_read = fread(texto, 1, file_size, leitor);
    texto[bytes_read] = '\0'; // Null-terminate
    fclose(leitor);
    
    return texto;
}

Arquivo* acessar_Diretorio(char* caminho) {
    int count = 0;
    DIR *dir;
    struct dirent* entrada;
    
    dir = opendir(caminho);

    if (dir == NULL) {
        perror("Erro ao abrir o diretório");
        return NULL;
    }

    printf("Conteúdo do diretório '%s':\n", caminho);
    while ((entrada = readdir(dir)) != NULL) {
        // entry->d_name é o nome do arquivo/diretório
        if (entrada->d_name[0] != '.') {
            count++;
        }
    }
    closedir(dir);

    Arquivo* carimbos = (Arquivo*)malloc((count) * sizeof(Arquivo));
    if (carimbos == NULL) {
        perror("Erro ao alocar memória para carimbos");
        return NULL;
    }
    
    int i = 0;
    dir = opendir(caminho);
    while ((entrada = readdir(dir)) != NULL) {
        if (entrada->d_name[0] != '.') {
            char caminho_completo[1024];
            snprintf(caminho_completo, sizeof(caminho_completo), "%s/%s", caminho, entrada->d_name);
            (carimbos)[i].nome = strdup(entrada->d_name);
            
            char* temp_texto = ler_carimbo(caminho_completo);
            strcpy((carimbos)[i].texto, temp_texto);
            free(temp_texto);
            i++;
        }
    }
    closedir(dir);
    return carimbos;
}

int* get_dim_Carimbo(char* carimbo_texto){
    int* dim = (int*)malloc(2 * sizeof(int));
    if (dim == NULL) {
        printf("Erro ao alocar memória para dimensões\n");
        return NULL;
    }
    dim[0] = 1; // Contador de linhas
    dim[1] = 0; // Contador de colunas

    for (int i = 0; carimbo_texto[i] != '\0'; i++) {
        if (carimbo_texto[i] == '\n') {
            dim[0]++;
            if (dim[1] == 0) {
                dim[1] = i;
            }
        }
    }
    printf("Dimensões do carimbo: %d x %d\n", dim[0], dim[1]);
    return dim;
}

/*
 * get_Carimbos
 * Purpose: Reads all files in the specified directory, splits their contents into lines,
 *          and processes each line as a separate "carimbo" (stamp).
 * Expected Output: Processes each carimbo line from each file; currently does not return or print,
 *                  but can be modified to store or display the results as needed.
 */
Carimbo* get_Carimbos(char* caminho) {
    Arquivo* carimbos = acessar_Diretorio(caminho);
    if (!carimbos) {
        printf("Nenhum carimbo encontrado no caminho: %s\n", caminho);
        return NULL;
    }

    // Count carimbos correctly
    int num_carimbos = 0;
    while (carimbos[num_carimbos].nome != NULL) {
        num_carimbos++;
    }
    num_carimbos--;

    // Only decrement if there's a sentinel at the end
    // If acessar_Diretorio returns array ending with NULL, don't decrement
    // num_carimbos--; // REMOVE THIS LINE
    
    printf("Número total de carimbos: %d\n", num_carimbos);

    if (num_carimbos == 0) {
        return NULL;
    }

    Carimbo* carimbo_array = malloc(num_carimbos * sizeof(Carimbo));
    if (!carimbo_array) {
        printf("Erro ao alocar memória para carimbo_array\n");
        return NULL;
    }

    for (int c = 0; c < num_carimbos; c++) {
        int* dim = get_dim_Carimbo(carimbos[c].texto);
        if (!dim) {
            printf("Erro ao obter dimensões para %s\n", carimbos[c].nome);
            continue;
        }
        
        Carimbo carimbo;
        carimbo.ordem[0] = dim[0]; // linhas
        carimbo.ordem[1] = dim[1]; // colunas
        strncpy(carimbo.nome, carimbos[c].nome, sizeof(carimbo.nome) - 1);
        carimbo.nome[sizeof(carimbo.nome) - 1] = '\0';

        // Aloca matriz de desenho
        carimbo.desenho = malloc(dim[0] * sizeof(char*));
        if (!carimbo.desenho) {
            printf("Erro ao alocar desenho para %s\n", carimbo.nome);
            free(dim);
            continue;
        }

        // Inicializa a matriz com espaços
        for (int i = 0; i < dim[0]; i++) {
            carimbo.desenho[i] = malloc((dim[1] + 1) * sizeof(char)); // +1 para '\0'
            if (!carimbo.desenho[i]) {
                printf("Erro ao alocar linha %d para %s\n", i, carimbo.nome);
                // Free already allocated rows
                for (int j = 0; j < i; j++) {
                    free(carimbo.desenho[j]);
                }
                free(carimbo.desenho);
                free(dim);
                continue;
            }
            // Preenche com espaços inicialmente
            memset(carimbo.desenho[i], ' ', dim[1]);
            carimbo.desenho[i][dim[1]] = '\0'; // Null-terminate
        }

        // Preenche desenho com conteúdo do arquivo
        int linha = 0, coluna = 0;
        for (int j = 0; carimbos[c].texto[j] != '\0'; j++) {
            if (linha >= dim[0]) {
                break; // Não exceder número de linhas
            }

            if (carimbos[c].texto[j] == '\n') {
                linha++;
                coluna = 0;
            } else if (coluna < dim[1]) {
                carimbo.desenho[linha][coluna] = carimbos[c].texto[j];
                coluna++;
            }
            // Se coluna >= dim[1], ignora caracteres extras na linha
        }

        carimbo_array[c] = carimbo;
        free(dim); // Libera apenas dim, NÃO libera desenho!
    }

    return carimbo_array;
}

int main(){
    char caminho[128] = "/home/Lucas/Documentos/Codes/C/Trabalhos/Art-Star/carimbos";
    printf(caminho);
    Carimbo* carimbos = get_Carimbos(caminho);
    for (int i = 0; i < 7; i++) {
        printf("Carimbo %d: %s\n", i + 1, carimbos[i].nome);
        printf("Dimensões: %d x %d\n", carimbos[i].ordem[0], carimbos[i].ordem[1]);
        for (int j = 0; j < carimbos[i].ordem[0]; j++) {
            for (int k = 0; k < carimbos[i].ordem[1]; k++) {
                printf("%c", carimbos[i].desenho[j][k]);
            }
            printf("\n");
        }
    }
    free(carimbos);
}