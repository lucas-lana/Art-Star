#include "arquivos.c"
#include "menus.c"

#define LINHAS 20
#define COLUNAS 80
#define CAMINHO "../../carimbos/"  // Caminho padrão para a pasta de carimbos
#define FEATURES 6

int main(){
    bool reinicio = true;
    long int rep;
    int estrelas;
    int naves = 0;
    int quantidade;
    celula **tela = malloc(LINHAS * sizeof(celula *));
    for (int i = 0; i < LINHAS; i++) {
        tela[i] = malloc(COLUNAS * sizeof(celula));
    }
    int numPastas = get_numDir(CAMINHO);
    if (numPastas <= 0) {
        return 1;
    }
    ConjuntoCarimbos* carimbos = carrega_Carimbos(numPastas, CAMINHO);
    if (carimbos == NULL) {
        return 1;
    }
    
    printf("PROGRAMA GERADOR DE OBRA DE ARTE:\n"); // Título da aplicação

    while (reinicio) {
        Quadro_Branco(tela,LINHAS,COLUNAS);
        
        int forma = Menu_Forma(carimbos,numPastas);
        int seed;
        int quantidadeDesenhos;
        long int conflito_desenhos;

        if (forma >= FEATURES && forma < numPastas + FEATURES){
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

        else if (forma == numPastas + FEATURES){
            while (true){
                Menu_Desenhos(carimbos, numPastas);
                if (Menu_Continuar() == 2){
                    break;
                }
            }
        }

        else if (forma == 1) {
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

        else {
            seed = Menu_Seed();
            quantidade = Menu_Quantidade();
            rep = Carimbar(tela,carimbos,LINHAS,COLUNAS,seed,forma,quantidade,1,0);
        }
            
        //int equacao = Menu_Equacao();
        if (forma != numPastas + FEATURES && forma != 1){
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
        reinicio = Menu_Reinicio();
    }
    return 0;
}