#include "Arquivos.c"
#include "menus.c"

#define LINHAS 20
#define COLUNAS 80
#define CAMINHO "../../carimbos/"  // Caminho padrão para a pasta de carimbos

int main(){
    bool reinicio = true;
    bool escolha;
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
    
    printf("PROGRAMA GERADOR DE OBRA DE ARTE:\n");

    while (reinicio) {
        Quadro_Branco(tela,LINHAS,COLUNAS);
        escolha = Menu_Arquivo_Carregar();
        //escolha = true;
        if (escolha) {
            int forma = Menu_Forma();
            int seed;
            if (forma == 5){
                seed = Menu_Seed();
                estrelas = Menu_Quantidade_Estrelas();
                naves = Menu_Quantidade_Naves();
                long int conflito_naves = Carimbar(tela,carimbos,numPastas,LINHAS,COLUNAS,seed,5,naves,1,0);
                long int conflito_estrelas = Carimbar(tela,carimbos,numPastas,LINHAS,COLUNAS,seed,1,estrelas,1,0);
                rep = conflito_estrelas + conflito_naves;
            }

            else if (forma == 6){
                while (true){
                    Menu_Desenhos(carimbos, numPastas);
                    if (Menu_Continuar() == 2){
                        break;
                    }
                }
            }

            else {
                seed = Menu_Seed();
                quantidade = Menu_Quantidade();
                rep = Carimbar(tela,carimbos,numPastas,LINHAS,COLUNAS,seed,forma,quantidade,1,0);
            }
            
            //int equacao = Menu_Equacao();
            if (forma != 6){
                Imprimir_Quadro(tela,LINHAS,COLUNAS);
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
        else {
            int rep,seed,formas,naves;
            int *p = Menu_Carregar(tela,LINHAS,COLUNAS);
            seed = p[0];
            rep = p[1];
            formas = p[2];
            naves = p[3];
            Imprimir_Quadro(tela,LINHAS,COLUNAS);
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
        reinicio = Menu_Reinicio();
    }
    return 0;
}