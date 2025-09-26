#include "menus.h"
#include "pintura.c"

int Menu_Seed(){
    int escolha;
    srand(time(NULL));
    while (1){
        printf("=================================\n");
        printf("Deseja escolher a seed para a arte?\n1 - Sim\n2 - Nao\n");
        printf("Escolha: ");
        scanf("%d",&escolha);
        if (escolha == 1){
            printf("Digite a seed desejada: ");
            scanf("%d",&escolha);
            break;
        }
        else if (escolha == 2){
            escolha = rand();
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

int Menu_Continuar(){
    int escolha;
    while (1){
        printf("=================================\n");
        printf("Deseja inspecionar outro desenho?\n1 - Sim\n2 - Nao\n");
        printf("Escolha: ");
        scanf("%d",&escolha);
        if (escolha == 1){
            break;
        }
        else if (escolha == 2){
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
            exit(0);
        }
        else {
            printf("Opcao invalida\n");
        }
    }
    return escolha;
}

bool Menu_Reinicio(){
    int escolha;
    bool retorno;
    while (1){
        printf("=================================\n");
        printf("Deseja reiniciar o programa?\n1 - Sim\n2 - Nao\n");
        printf("Escolha: ");
        scanf("%d",&escolha);
        if (escolha == 1){
            retorno = true;
            break;
        }
        else if (escolha == 2){
            retorno = false;
            exit(0);
            break;
        }
        else {
            printf("Opcao invalida\n");
        }
    }
    return retorno;
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