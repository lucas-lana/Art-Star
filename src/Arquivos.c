#include "arquivos.h"

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

    Arquivo* carimbos = (Arquivo*)malloc((count + 1) * sizeof(Arquivo));
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
    // NULL-terminate the array
    carimbos[i].nome = NULL;
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
    //printf("Dimensões do carimbo: %d x %d\n", dim[0], dim[1]);
    return dim;
}

/*
 * get_Carimbos
 * Purpose: Reads all files in the specified directory, splits their contents into lines,
 *          and processes each line as a separate "carimbo" (stamp).
 * Expected Output: Processes each carimbo line from each file; currently does not return or print,
 *                  but can be modified to store or display the results as needed.
 */
Carimbos_Num* get_Carimbos(char* caminho) {
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
    
    //printf("Número total de carimbos: %d\n", num_carimbos);

    if (num_carimbos == 0) {
        return NULL;
    }

    Carimbos_Num* carimbo_array = malloc(sizeof(Carimbos_Num));
    if (!carimbo_array) {
        printf("Erro ao alocar memória para carimbo_array\n");
        return NULL;
    }
    carimbo_array->quantidade = num_carimbos;
    carimbo_array->carimbos = malloc(num_carimbos * sizeof(Carimbo));
    if (!carimbo_array->carimbos) {
        printf("Erro ao alocar memória para carimbos\n");
        free(carimbo_array);
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

        carimbo_array->carimbos[c] = carimbo;
        free(dim); // Libera apenas dim, NÃO libera desenho!
    }

    return carimbo_array;
}

int get_numDir(char* caminhoRaiz){
    DIR* dir = opendir(caminhoRaiz);
    struct dirent* entrada;
    int pastas = 0;

    if (dir == NULL){
        perror("Erro ao abrir o diretório\n");
        return -1;
    }

    while ((entrada = readdir(dir)) != NULL){

        if (strcmp(entrada->d_name, ".") == 0 || strcmp(entrada->d_name,"..") == 0)
            continue;

        char caminho_completo[1024];
        snprintf(caminho_completo, sizeof(caminho_completo), "%s/%s", caminhoRaiz, entrada->d_name);

        struct stat st;
        if (stat(caminho_completo, &st) == 0 && S_ISDIR(st.st_mode))
            pastas++;
    }

    closedir(dir);
    return pastas;
}




ConjuntoCarimbos* carrega_Carimbos(int numPastas, char* caminho){
    /*
    1. Verificar quantidade de pastas dentro de um dado caminho de diretório
    2. Acessar as pastas, salvando o nome da pasta dentro do campo de nome de coleção de carimbos
    3. get_Carimbos para cada pasta dento do dado diretório raiz
    4. Retornar o conjunto de carimbos
    */

    ConjuntoCarimbos* pastas_Carimbos = (ConjuntoCarimbos*)malloc(numPastas * sizeof(ConjuntoCarimbos));
    if (pastas_Carimbos == NULL) {
        perror("Erro ao alocar memória para pastas_Carimbos");
        return NULL;
    }

    DIR* dir = opendir(caminho);
    struct dirent* entrada;
    int index = 0;

    while ((entrada = readdir(dir)) != NULL){

        if (strcmp(entrada->d_name, ".") == 0 || strcmp(entrada->d_name,"..") == 0)
            continue;

        char caminho_completo[1024];
        snprintf(caminho_completo, sizeof(caminho_completo), "%s/%s", caminho, entrada->d_name);

        struct stat st;
        if (stat(caminho_completo, &st) == 0 && S_ISDIR(st.st_mode)){
            strncpy(pastas_Carimbos[index].nomePasta, entrada->d_name, sizeof(pastas_Carimbos[index].nomePasta) - 1);
            pastas_Carimbos[index].nomePasta[sizeof(pastas_Carimbos[index].nomePasta) - 1] = '\0';

        

            Carimbos_Num* aux = get_Carimbos(caminho_completo);
            pastas_Carimbos[index].carimbos = aux->carimbos;
            pastas_Carimbos[index].quantidade = aux->quantidade;
            free(aux);

            /*
            for (int i = 0; i < pastas_Carimbos[index].quantidade; i++) {
                printf("Carimbo encontrado: %s\n", pastas_Carimbos[index].carimbos[i].nome);
            }
            */
        }
    }
    return pastas_Carimbos;
}

/*int main(){

    int numPastas = get_numDir(CAMINHO);
    if (numPastas <= 0) {
        return 1;
    }

    ConjuntoCarimbos* carimbos = carrega_Carimbos(numPastas, CAMINHO);
    if (carimbos == NULL) {
        fprintf(stderr, "Erro ao carregar carimbos\n");
        return 1;
    }

    // Imprime os dados presentes em 'carimbos'
    for (int i = 0; i < numPastas; i++) {
        if (!carimbos[i].carimbos || carimbos[i].quantidade <= 0) {
            continue;
        }

        printf("Pasta: %s\n", carimbos[i].nomePasta);
        printf("Quantidade de carimbos: %d\n", carimbos[i].quantidade);


        for (int j = 0; j < carimbos[i].quantidade; j++) {
            Carimbo* c = &carimbos[i].carimbos[j];
            printf("  Carimbo %d: %s (%dx%d)\n", j + 1, c->nome, c->ordem[0], c->ordem[1]);

            if (c->desenho) {
                for (int r = 0; r < c->ordem[0]; r++) {
                    if (c->desenho[r]) {
                        printf("    %s\n", c->desenho[r]);
                    }
                }
            }
        }
        printf("\n");
    }

    // Libera a memória alocada
    for (int i = 0; i < numPastas; i++) {
        free(carimbos[i].carimbos);
    }
    free(carimbos);

    return 0;
}*/