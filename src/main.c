#include "menus.c"

#define LINHAS 20 // Definição da altura da tela
#define COLUNAS 80 // Definição da largura da tela
#define CAMINHO "../../carimbos/"  // Caminho padrão para a pasta de carimbos
#define FEATURES 6 // Número de opções fixas no menu antes das pastas de carimbos personalizadas

int main(){
    long int rep; // número de posições já preenchidas
    int estrelas; 
    int naves = 0;
    int quantidade; // Quantidade de desenhos a serem feitos na tela
    
    // Alocação dinâmica da tela
    celula **tela = malloc(LINHAS * sizeof(celula *));
    for (int i = 0; i < LINHAS; i++) {
        tela[i] = malloc(COLUNAS * sizeof(celula));
    }

    // Carregamento a quantidade de pastas de carimbos/desenhos
    int numPastas = get_numDir(CAMINHO);
    if (numPastas <= 0) {
        return 1;
    }

    // Carregamento dos carimbos/desenhos
    ConjuntoCarimbos* carimbos = carrega_Carimbos(numPastas, CAMINHO);
    if (carimbos == NULL) {
        return 1;
    }

    while (true) { // Loop principal do programa, sempre retorna ao menu após concluir uma ação
        Quadro_Branco(tela,LINHAS,COLUNAS); // Inicializa a tela em branco
        
        int forma = Menu_Forma(carimbos,numPastas); // Exibe o menu de seleção de forma/desenho, dentro do menu chama Tela_Titulo()
        int seed;
        int quantidadeDesenhos;
        long int conflito_desenhos;

        if (forma >= FEATURES && forma < numPastas + FEATURES){ // Seleção de uma pasta de carimbos personalizada
            seed = Menu_Seed();
            quantidadeDesenhos = Menu_Quantidade_Desenhos(carimbos[forma - FEATURES].nomePasta,limite_desenho(carimbos,numPastas,carimbos[forma - FEATURES].nomePasta,LINHAS,COLUNAS));
            conflito_desenhos = Carimbar(tela,carimbos,LINHAS,COLUNAS,seed,forma,quantidadeDesenhos,1,0);
            if (strcmp(carimbos[forma - FEATURES].nomePasta, "Naves") == 0){
                estrelas = Menu_Quantidade_Estrelas(LINHAS,COLUNAS);
                int conflito_estrelas = Carimbar(tela,carimbos,LINHAS,COLUNAS,seed,2,estrelas,1,0);
                rep = conflito_desenhos + conflito_estrelas;
            }
            else {
                rep  = conflito_desenhos;
            }
        }

        else if (forma == numPastas + FEATURES){ // Inspeção de desenhos
            Menu_Desenhos(carimbos, numPastas);
        }

        else if (forma == 1) { // Carregar uma obra de arte salva um de arquivo .txt
            int rep,seed,formas,naves;
            int *p = Menu_Carregar(tela,LINHAS,COLUNAS);
            seed = p[0];
            rep = p[1];
            formas = p[2];
            naves = p[3];
            Imprimir_Quadro(tela,LINHAS,COLUNAS,false);
            printf("Seed: %d\n",seed);
            if (naves>0){
                printf("Quantidade de naves: %d\n",naves);
                printf("Quantidade de estrelas: %d\n",formas);
            }
            else {
                printf("Quantidade de figuras: %d\n",formas);
            }
            printf("Posições já preenchidas: %d\n",rep);
        }

        else { // Geração de formas básicas (estrelas, somas, X ou aleatórias)
            seed = Menu_Seed();
            quantidade = Menu_Quantidade_Desenhos("figuras", 100);
            rep = Carimbar(tela,carimbos,LINHAS,COLUNAS,seed,forma,quantidade,1,0);
        }
            
        if (forma != numPastas + FEATURES && forma != 1){ // Se não for inspeção de desenhos ou carregamento de arquivo
            Imprimir_Quadro(tela,LINHAS,COLUNAS,false);
            printf("Seed: %d\n",seed);
            if (forma == 5){
                printf("Quantidade de naves: %d\n",naves);
                printf("Quantidade de estrelas: %d\n",estrelas);
                quantidade = estrelas;
            }
            else{
                printf("Quantidade de figuras: %d\n",quantidade);
            }
            printf("Posições já preenchidas: %ld\n",rep);

            Menu_Arquivo(tela,LINHAS,COLUNAS, seed, rep, quantidade, naves);
        }
    }
    return 0;
}