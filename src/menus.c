#include <ctype.h>

#include "menus.h"
#include "pintura.c"
#include "arquivos.c"

#define ALFABETO "/home/Lucas/Documentos/Codes/C/Trabalhos/Art-Star/Fontes/Big-nw"

void Tela_Titulo(char* nomeTitulo,char preenchimento,int trocaCor,char** cores){
    int tamanhoTitulo = strlen(nomeTitulo);
    
    Carimbos_Num* letras = get_Carimbos(ALFABETO);
    if (letras == NULL) {
        printf("Erro ao carregar carimbos do alfabeto.\n");
        return;
    }

    // Aloca array de carimbos individuais, não Carimbos_Num
    Carimbo* titulo = malloc(tamanhoTitulo * sizeof(Carimbo));
    if (titulo == NULL) {
        free(letras);
        return;
    }
    
    // Inicializa cada carimbo do título
    system("clear");
    for (int i = 0; i < tamanhoTitulo; i++){
        bool encontrou = false;
        for (int j = 0; j < letras->quantidade; j++){  // Corrigido: j < quantidade
            if (toupper(nomeTitulo[i]) == toupper(letras->carimbos[j].nome[0])){
                titulo[i] = letras->carimbos[j];  // Copia todo o carimbo
                encontrou = true;
                break;
            }
        }
        // Se não encontrou a letra, usa espaço ou caractere padrão
        if (!encontrou) {
            strcpy(titulo[i].nome, " ");
            titulo[i].ordem[0] = 10;
            titulo[i].ordem[1] = 3;
            // Preenche com espaços
            titulo[i].desenho = malloc(titulo[i].ordem[0] * sizeof(char*));
            for (int linha = 0; linha < titulo[i].ordem[0]; linha++) {
                titulo[i].desenho[linha] = malloc((titulo[i].ordem[1] + 1) * sizeof(char));
                titulo[i].desenho[linha][titulo[i].ordem[1]] = '\0'; // Null-terminate
            }
            for (int linha = 0; linha < titulo[i].ordem[0]; linha++) {
                for (int col = 0; col < titulo[i].ordem[1]; col++) {
                    titulo[i].desenho[linha][col] = ' ';
                }
            }
        }
    }
    
    // Imprimir o título
    int cor = 0;

    for (int linha = 0; linha < 10; linha++){
        for (int letra = 0; letra < tamanhoTitulo; letra++){  // Corrigido: itera por todas as letras
            for (int coluna = 0; coluna < titulo[letra].ordem[1] - 1; coluna++){  // Corrigido: titulo[letra] em vez de titulo->carimbos[letra]
                char caractere = titulo[letra].desenho[linha][coluna];
                
                if (caractere == '$'){
                    caractere = preenchimento;
                }

                if (trocaCor >= 1 && cores != NULL) {

                    char cor_upper[16];
                    strncpy(cor_upper, cores[cor], sizeof(cor_upper) - 1);
                    cor_upper[sizeof(cor_upper) - 1] = '\0';
                    for (int idx = 0; cor_upper[idx]; idx++) {
                        cor_upper[idx] = toupper((unsigned char)cor_upper[idx]);
                    }

                    if (strcmp(cor_upper,"BRANCO") == 0)
                        printf("%c", caractere);
                    else if (strcmp(cor_upper,"VERMELHO") == 0)
                        printf("\033[31m%c\033[0m", caractere);
                    else if (strcmp(cor_upper,"VERDE") == 0)
                        printf("\033[32m%c\033[0m", caractere);
                    else if (strcmp(cor_upper,"AMARELO") == 0)
                        printf("\033[33m%c\033[0m", caractere);
                    else if (strcmp(cor_upper,"AZUL") == 0)
                        printf("\033[34m%c\033[0m", caractere);
                    else if (strcmp(cor_upper,"MAGENTA") == 0)
                        printf("\033[35m%c\033[0m", caractere);
                    else if (strcmp(cor_upper,"CIANO") == 0)
                        printf("\033[36m%c\033[0m", caractere);
                    else if (strcmp(cor_upper,"PRETO") == 0)
                        printf("\033[30m%c\033[0m", caractere);
                    else
                        printf("%c", caractere);  // Cor padrão se não reconhecida
                }
                else
                    printf("%c", caractere);
            }
        }
        printf("\n");
        if (trocaCor > 0) {
            if ((linha % trocaCor) == 0 && linha != 0) {
            cor++;
            if (cor >= trocaCor) {
                cor = 0;
            }
            }
        }
    }
    free(titulo);
    free(letras->carimbos);
    free(letras);
}



int Menu_Seed(){
    Tela_Titulo("Art - Star +",'@',5,(char*[]){"Vermelho","Magenta","Azul"});// Título da aplicação
    int escolha;
    srand(time(NULL));
    while (1){
        printf("=================================\n");
        printf("Digite uma seed para a arte (digite -1 para ser aleátório)\n");
        printf("Seed: ");
        scanf("%d",&escolha);

        if (escolha == -1){
            escolha = rand();
            break;
        }
        else if (escolha >= 0){
            break;   
        }
        else {
            printf("Opcao invalida\n");
        }
    }
    return escolha;
}


int Menu_Quantidade(){
    int escolha;
    while (1){
        printf("=================================\n");
        printf("Digite a quantidade de figuras 1 à 100 (menor ou igual a zero será aleatorio): ");
        scanf("%d",&escolha);
        if (escolha <= 0){
            escolha = rand() % 100;
            break;
        }
        else if (escolha >= 100){
            escolha = 100;
            break;
        }
        else if (escolha > 0 && escolha < 100){
            break;
        }
        else {
            printf("Opcao invalida\n");
        }
    }
    return escolha;
}

int Menu_Quantidade_Estrelas(int linhas, int colunas){
    int limite = (linhas * colunas) / ((linhas * colunas)/100);
    int escolha;
    while (1){
        printf("=================================\n");
        printf("Digite a quantidade de estrelas 0 à %d (menor que zero, ou maior que %d será aleatorio): ", limite, limite);
        scanf("%d",&escolha);
        if (escolha < 0 || escolha > limite){
            escolha = rand() % limite;
            break;
        }
        else if (escolha >= 0 && escolha <= limite){
            break;
        }
        else {
            printf("Opcao invalida\n");
        }
    }
    return escolha;
}

int Menu_Quantidade_Desenhos(char* desenho,int limite){
    int escolha;
    while (1){
        printf("=================================\n");
        printf("Digite a quantidade de %s 0 à %d (menor que zero, ou maior que %d será aleatorio): ",desenho,limite,limite);
        scanf("%d",&escolha);
        if (escolha < 0 || escolha > limite){
            escolha = rand() % limite;
            break;
        }
        else if (escolha >= 0 && escolha <= limite){
            break;
        }
        else {
            printf("Opcao invalida\n");
        }
    }
    return escolha;
}

void Menu_Desenhos(ConjuntoCarimbos* carimbos, int numPastas){
    int escolha_Pasta, escolha_Desenho;

    if (carimbos == NULL) {
        printf("Nenhum carimbo carregado.\n");
        return;
    }
    
    while (1){
        Tela_Titulo("Art - Star +",'@',5,(char*[]){"Vermelho","Magenta","Azul"});// Título da aplicação
        printf("=================================\n");
        printf("Escolha a pasta do desenho:\n");
        for (int i = 0; i < numPastas; i++) {
            if (carimbos[i].quantidade <= 0) {
                continue;
            }
            printf("%d - %s\n", i + 1, carimbos[i].nomePasta);
        }
        printf("%d - Sair\n", numPastas + 1);
        printf("Escolha: ");
        scanf("%d",&escolha_Pasta);
        if (escolha_Pasta >= 1 && escolha_Pasta <= numPastas){
            
            while (1) {
                if (carimbos[escolha_Pasta - 1].quantidade <= 0) {
                    printf("Nenhum carimbo disponível nesta pasta.\n");
                    break;
                }
                printf("=================================\n");
                printf("Escolha o desenho (numero):\n");
                for (int j = 0; j < carimbos[escolha_Pasta - 1].quantidade; j++) {
                    printf("%d - %s\n", j + 1, carimbos[escolha_Pasta - 1].carimbos[j].nome);
                }
                printf("%d - Voltar\n", carimbos[escolha_Pasta - 1].quantidade + 1);
                printf("Escolha: ");
                scanf("%d",&escolha_Desenho);

                if (escolha_Desenho < 1 || escolha_Desenho > carimbos[escolha_Pasta - 1].quantidade + 1) {
                    printf("Opcao invalida\n");
                    continue;
                }
                else if (escolha_Desenho == carimbos[escolha_Pasta - 1].quantidade + 1) {
                    break;
                }

                Imprime_Desenho(&carimbos[escolha_Pasta - 1].carimbos[escolha_Desenho - 1]);

            }
        }
        else if (escolha_Pasta == numPastas + 1){
            break;
        }
        else {
            printf("Opcao invalida\n");
        }
    }
}

int Menu_Forma(ConjuntoCarimbos* pastas, int numPastas){
    Tela_Titulo("Art - Star +",'@',5,(char*[]){"Vermelho","Magenta","Azul"});// Título da aplicação
    int escolha;
    while (1){
        printf("=================================\n");
        printf("1 - Carregar um desenho\n");
        printf("2 - Gerar quadro estrelado.\n3 - Gerar arte de somas.\n");
        printf("4 - Gerar quadro X.\n5 - Geração aleátorias.\n");
        
        for (int i = 0; i < numPastas; i++) {
            if (pastas[i].quantidade <= 0) {
                continue;
            }
            printf("%d - Gerar %s\n", i + FEATURES, pastas[i].nomePasta);
        }

        printf("%d - Inspecionar figuras\n",numPastas + FEATURES);
        printf("%d - Sair\n", numPastas + 7);
        printf("Escolha: ");
        scanf("%d",&escolha);
        if (escolha >= 1 && escolha <= numPastas + FEATURES){
            break;
        }
        else if (escolha == numPastas + 7){
            system("clear");
            exit(0);
        }
        else {
            printf("Opcao invalida\n");
        }
    }
    return escolha;
}

void Menu_Salvar(celula** tela,int linhas,int colunas,int seed,int hits, int formas, int naves){
    FILE *arquivo;
    char nome[64];
    printf("=================================\n");
    printf("Digite o nome do arquivo para salvar: ");
    scanf("%s",nome);
    strncat(nome, ".txt", sizeof(nome) - strlen(nome) - 1);
    arquivo = fopen(nome,"w");
    fprintf(arquivo,"Seed: %d\n",seed);
    fprintf(arquivo,"Comflitos: %d\n",hits);
    if (naves>0){
        fprintf(arquivo,"Quantidade de naves: %d\n",naves);
        fprintf(arquivo,"Quantidade de estrelas: %d\n\n",formas);
    }
    else{
        fprintf(arquivo,"Quantidade de figuras: %d\n\n",formas);
    }

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            fprintf(arquivo,"%c",tela[i][j].simbolo);
        }
        fprintf(arquivo,"\n");
    }
    fclose(arquivo);
}

int* Menu_Carregar(celula** tela,int linhas,int colunas){ 
    FILE *arquivo;
    char nome[64];
    int *p = malloc(4 * sizeof(int));
    if (p == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    printf("=================================\n");
    printf("Digite o nome do arquivo para carregar: ");
    scanf("%s", nome);

    arquivo = fopen(nome, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        free(p);
        exit(EXIT_FAILURE);
    }

    // Lendo Seed e Conflitos
    fscanf(arquivo, "Seed: %d\n", &p[0]);
    fscanf(arquivo, "Comflitos: %d\n", &p[1]);

    // Verifica se é naves ou figuras
    char dados_linha[32];
    char linha[128];
    
    fgets(dados_linha, sizeof(dados_linha), arquivo);

    if (sscanf(dados_linha, "Quantidade de naves: %d", &p[3]) == 1) {
        fscanf(arquivo, "Quantidade de estrelas: %d\n", &p[2]);
    } else {
        sscanf(dados_linha, "Quantidade de figuras: %d\n", &p[2]);
        p[3] = 0; // Define p[3] como 0 se não houver naves
        fgets(linha, sizeof(linha), arquivo);  // Lê a linha de separação
    }


    // Lendo a grade de símbolos
    for (int i = 0; i < linhas; i++) {
        fgets(linha, sizeof(linha), arquivo);  // Lê a linha da tela
        for (int j = 0; j < colunas; j++) {
            tela[i][j].simbolo = linha[j];
        }
    }

    fclose(arquivo);
    return p;
}


void Menu_Arquivo(celula** tela,int linhas,int colunas,int seed,int hits, int formas, int naves){
    int escolha;
    while (1){
        printf("=================================\n");
        sleep(2);
        printf("Deseja salvar a arte?\n1 - Salvar\n2 - Nao Salvar\n");
        printf("Escolha: ");
        scanf("%d",&escolha);
        if (escolha == 1){
            Menu_Salvar(tela,linhas,colunas,seed,hits,formas,naves);
            break;
        }
        else if (escolha == 2){
            break;
        }
        else {
            printf("Opcao invalida\n");
        }
    }
}

bool Menu_Arquivo_Carregar(){
    int escolha;
    bool retorno;
    while (1){
        printf("=================================\n");
        printf("Deseja carregar uma arte?\n1 - Sim\n2 - Nao\n");
        printf("Escolha: ");
        scanf("%d",&escolha);
        if (escolha == 1){
            retorno = false;
            break;
        }
        else if (escolha == 2){
            retorno = true;
            break;
        }
        else {
            printf("Opcao invalida\n");
        }
    }
    return retorno;
}