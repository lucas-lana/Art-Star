#include "Inspec.c"
#include "menus.h"

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

int Menu_Quantidade_Estrelas(){
    int escolha;
    while (1){
        printf("=================================\n");
        printf("Digite a quantidade de estrelas 1 à 42 (menor ou igual a zero será aleatorio): ");
        scanf("%d",&escolha);
        if (escolha <= 0){
            escolha = rand() % 42;
            break;
        }
        else if (escolha >= 42){
            escolha = 42;
            break;
        }
        else if (escolha > 0 && escolha < 42){
            break;
        }
        else {
            printf("Opcao invalida\n");
        }
    }
    return escolha;
}

int Menu_Quantidade_Naves(){
    int escolha;
    while (1){
        printf("=================================\n");
        printf("Digite a quantidade de naves 1 à 7 (menor ou igual a zero será aleatorio): ");
        scanf("%d",&escolha);
        if (escolha <= 0){
            escolha = rand() % 7;
            break;
        }
        else if (escolha >= 7){
            escolha = 7;
            break;
        }
        else if (escolha > 0 && escolha < 7){
            break;
        }
        else {
            printf("Opcao invalida\n");
        }
    }
    return escolha;
}

void Imprime_Desenho(int escolha){
    switch (escolha){
        case 1:
            printf("Estrela:\n");

            celula **tela_estrela = (celula**)malloc(3*sizeof(celula*));
            for (int i = 0; i < 3; i++){
                tela_estrela[i] = (celula*)malloc(3*sizeof(celula));
            }

            Quadro_Branco(tela_estrela,3,3);
            Carimbo_Estrela_Inspec(tela_estrela,1,1);
            Imprimir_Quadro(tela_estrela,3,3);
            
            for (int i = 0; i < 3; i++){
                free(tela_estrela[i]);
            }
            free(tela_estrela);

            break;
        case 2:
            printf("X:\n");
            
            celula **tela_x = (celula**)malloc(5*sizeof(celula*));
            for (int i = 0; i < 5; i++){
                tela_x[i] = (celula*)malloc(5*sizeof(celula));
            }

            Quadro_Branco(tela_x,5,5);
            Carimbo_X_Inspec(tela_x,1,1);
            Imprimir_Quadro(tela_x,5,5);

            for (int i = 0; i < 5; i++){
                free(tela_x[i]);
            }
            free(tela_x);

            break;
        case 3:
            printf("Soma:\n");
            
            celula **tela_soma = (celula**)malloc(5*sizeof(celula*));
            for (int i = 0; i < 5; i++){
                tela_soma[i] = (celula*)malloc(5*sizeof(celula));
            }

            Quadro_Branco(tela_soma,5,5);
            Carimbo_Soma_Inspec(tela_soma,1,1);
            Imprimir_Quadro(tela_soma,5,5);

            for (int i = 0; i < 5; i++){
                free(tela_soma[i]);
            }
            free(tela_soma);

            break;
        case 4:
            printf("Star Destroyer:\n");
            celula **tela_star_destroyer = (celula**)malloc(8*sizeof(celula*));
            for (int i = 0; i < 8; i++){
                tela_star_destroyer[i] = (celula*)malloc(12*sizeof(celula));
            }

            Quadro_Branco(tela_star_destroyer,8,12);
            Carimbo_StarDestroyer_Inspec(tela_star_destroyer,1,1);
            Imprimir_Quadro(tela_star_destroyer,8,12);

            for (int i = 0; i < 7; i++){
                free(tela_star_destroyer[i]);
            }
            free(tela_star_destroyer);

            break;
        case 5:
            printf("Fighter:\n");
            celula **tela_fighter = (celula**)malloc(11*sizeof(celula*));
            for (int i = 0; i < 11; i++){
                tela_fighter[i] = (celula*)malloc(15*sizeof(celula));
            }
            Quadro_Branco(tela_fighter,11,15);
            Carimbo_Fighter_Inspec(tela_fighter,1,1);
            Imprimir_Quadro(tela_fighter,11,15);
            
            for (int i = 0; i < 11; i++){
                free(tela_fighter[i]);
            }
            free(tela_fighter);

            break;
        case 6:
            printf("Interceptor:\n");
            celula **tela_interceptor = (celula**)malloc(11*sizeof(celula*));
            for (int i = 0; i < 11; i++){
                tela_interceptor[i] = (celula*)malloc(13*sizeof(celula));
            }
            Quadro_Branco(tela_interceptor,11,13);
            Carimbo_Interceptor_Inspec(tela_interceptor,1,1);
            Imprimir_Quadro(tela_interceptor,11,13);

            for (int i = 0; i < 11; i++){
                free(tela_interceptor[i]);
            }
            free(tela_interceptor);

            break;
        case 7:
            printf("Y-Wing:\n");
            celula** tela_ywing = (celula**)malloc(11*sizeof(celula*));
            for (int i = 0; i < 11; i++){
                tela_ywing[i] = (celula*)malloc(13*sizeof(celula));
            }
            Quadro_Branco(tela_ywing,11,13);
            Carimbo_YWing_Inspec(tela_ywing,1,1);
            Imprimir_Quadro(tela_ywing,11,13);

            for (int i = 0; i < 11; i++){
                free(tela_ywing[i]);
            }
            free(tela_ywing);

            break;
        case 8:
            printf("A-Wing:\n");
            celula** tela_awing = (celula**)malloc(10*sizeof(celula*));
            for (int i = 0; i < 10; i++){
                tela_awing[i] = (celula*)malloc(13*sizeof(celula));
            }
            Quadro_Branco(tela_awing,10,13);
            Carimbo_AWing_Inspec(tela_awing,1,1);
            Imprimir_Quadro(tela_awing,10,13);

            for (int i = 0; i < 10; i++){
                free(tela_awing[i]);
            }
            free(tela_awing);

            break;
        case 9:
            printf("N1:\n");
            celula** tela_n1 = (celula**)malloc(8*sizeof(celula*));
            for (int i = 0; i < 8; i++){
                tela_n1[i] = (celula*)malloc(11*sizeof(celula));
            }
            Quadro_Branco(tela_n1,8,11);
            Carimbo_N1_Inspec(tela_n1,1,1);
            Imprimir_Quadro(tela_n1,8,11);

            for (int i = 0; i < 8; i++){
                free(tela_n1[i]);
            }
            free(tela_n1);

            break;
        case 10:
            printf("X-Wing:\n");
            celula** tela_xwing = (celula**)malloc(11*sizeof(celula*));
            for (int i = 0; i < 11; i++){
                tela_xwing[i] = (celula*)malloc(15*sizeof(celula));
            }
            Quadro_Branco(tela_xwing,11,15);
            Carimbo_XWing_Inspec(tela_xwing,1,1);
            Imprimir_Quadro(tela_xwing,11,15);

            for (int i = 0; i < 11; i++){
                free(tela_xwing[i]);
            }
            free(tela_xwing);
            break;
    }
}

int Menu_Continuar(){
    int escolha;
    while (1){
        printf("=================================\n");
        printf("Deseja inspecionar outra forma?\n1 - Sim\n2 - Nao\n");
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

void Menu_Desenhos(){
    int escolha;
    while (1){
        printf("=================================\n");
        printf("Escolha o desenho a ser inspecionado:\n");
        printf("1 - Estrela\n2 - X\n3 - Soma\n4 - Star Destroyer\n5 - Fighter\n");
        printf("6 - Interceptor\n7 - Y-Wing\n8 - A-Wing\n9 - N1\n10 - X-Wing\n");
        printf("11 - Sair\n");
        printf("Escolha: ");
        scanf("%d",&escolha);
        if (escolha >= 1 && escolha <= 10){
            Imprime_Desenho(escolha);
            break;
        }
        else if (escolha == 11){
            break;
        }
        else {
            printf("Opcao invalida\n");
        }
    }
}

int Menu_Forma(){
    int escolha;
    while (1){
        printf("=================================\n");
        printf("Escolha o tipo de figura basica a ser usada para criar a obra:\n");
        printf("1 - Asterisco simples (Estrela).\n2 - Simbolo de soma com asteriscos (Soma).\n");
        printf("3 - Letra X com asteriscos (X).\n4 - Formas aleátorias.\n5 - Obra de arte Galática\n");
        printf("6 - Inspecionar figuras\n");
        printf("7 - Sair\n");
        printf("Escolha: ");
        scanf("%d",&escolha);
        if (escolha >= 1 && escolha <= 6){
            break;
        }
        else if (escolha == 7){
            exit(0);
        }
        else {
            printf("Opcao invalida\n");
        }
    }
    return escolha;
}

int Menu_Equacao(){
    int escolha;
    while (1){
        printf("=================================\n");
        printf("Escolha a equação para obter as coordenadas:\n");
        printf("1 - (Xi-1 * i * ((Xi-1 + seed) mod i) + seed + i) mod N_MAX\n");
        printf("2 - (Xi-1 * i * (Xi-1 mod i) + seed + i) mod N_MAX\n");
        printf("3 - (Xi-1 * i * (i mod N_max) + seed + i) mod N_MAX\n");
        printf("4 - ((Xi-1 * i * N_MAX) + seed + i) mod N_MAX\n");
        printf("Escolha: ");
        scanf("%d",&escolha);
        if (escolha >= 1 && escolha <= 4){
            break;
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

