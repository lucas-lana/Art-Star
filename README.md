# Art-Star

Art-Star é um programa em C originalmente criado como trabalho prático de Projeto e Análise de Algoritmos com o objetivo de gerar "artes" no terminal usando caracteres (por padrão `*`). A partir de uma seed pseudorrandômica, é possível gerar múltiplas artes que serão reprodutíveis para a mesma seed. O projeto evoluiu para suportar carimbos personalizados, melhores menus, cores e estrutura modular, servindo como base para uma futura "engine" de jogos simples em terminal.

---

Índice
- Visão geral
- Funcionalidades
- Estrutura do repositório
- Pré-requisitos
- Compilar e executar
- Uso / Fluxos principais
- Formato de carimbos e fontes
- Como adicionar novos carimbos/desenhos

---

Visão geral
---------
Art-Star permite:
- Gerar artes repetíveis a partir de uma seed.
- Usar carimbos (desenhos) pré-existentes organizados em pastas.
- Carregar e salvar obras em arquivo texto.
- Gerar formas básicas (estrelas, X, somas, etc.) e compor telas com múltiplas figuras.
- Personalizar preenchimento de caracteres e cores no terminal.
- Suporte a criação de carimbos personalizados (pastas em `carimbos/`).

Funcionalidades principais
-------------------------
- Geração pseudorrandômica de artes por seed.
- Leitura dinâmica de diretórios de carimbos.
- Menus interativos para escolher formas, quantidade, seed e operações (carregar/salvar).
- Impressão da tela no terminal com possibilidade de cores ANSI.
- Módulos separados: carregamento de arquivos, carimbos, pintura (quadro), menus.

Estrutura do repositório
------------------------
- carimbos/                — Pastas com desenhos/carimbos (ex.: `Naves/`).
- Fontes/Big-nw/           — Fontes/carimbos do alfabeto (arquivos por caractere).
- src/
  - main.c
  - menus.c, menus.h
  - carimbos.c, carimbos.h
  - pintura.c, pintura.h
  - arquivos.c, arquivos.h
  - celula.h
- README.md                — (este arquivo)

Pré-requisitos
--------------
- Linux (desenvolvido/testado neste SO)
- GCC (recomenda-se suporte a C11)

Compilar
--------
Exemplo simples (na raiz do projeto):
```bash
cd /home/Lucas/Documentos/Codes/C/Trabalhos/Art-Star
gcc -std=c11 -Wall -Wextra -g src/*.c -o src/output/main
```
Se houver arquivos de teste:
```bash
gcc -std=c11 -Wall -Wextra -g src/test_runner.c src/*.c -o src/output/test_runner
```
(Se `main.c` incluir diretamente `menus.c` com `#include "menus.c"`, pode ser necessário ajustar para evitar dupla definição ao compilar todos os `.c` — ver seção Dicas.)

Executar
--------
Rodar o binário:
```bash
./src/output/main
```
Executar test runner (se disponível):
```bash
./src/output/test_runner
```

Uso / Fluxos principais
-----------------------
O menu principal orienta o usuário a:
- Carregar uma obra salva.
- Selecionar forma / pasta de carimbos.
- Escolher seed e quantidade de desenhos.
- Imprimir/Salvar a obra.
- Inspecionar carimbos disponíveis.

Entradas típicas:
- Números para escolher opções do menu.
- Nomes de arquivos para salvar/carregar.
- Seed (inteiro) para reprodução da arte.

Formato de carimbos e fontes
---------------------------
- `Fontes/Big-nw/` contém arquivos por caractere (ex.: `A.txt`) usados para montar títulos e letras grandes.
- `carimbos/` contém subpastas (ex.: `Naves/`) com arquivos `.txt` representando desenhos/carimbos.
- Cada arquivo de carimbo é um texto com linhas correspondentes ao desenho. É comum usar um caractere especial (`$`) como placeholder de preenchimento — o programa substitui `$` pelo caractere de preenchimento escolhido no menu.

Formato de arquivo de salvamento (resumo)
-----------------------------------------
O programa salva obras em `.txt` contendo metadados (seed, contadores e possivelmente quantidades) e a matriz da tela (LINHAS x COLUNAS). Ao carregar, o programa retorna dados como seed, posições preenchidas, quantidades de figuras e naves. Recomenda-se inspecionar `src/arquivos.c` para detalhes exatos do formato de leitura e escrita.

Como adicionar novos carimbos
-----------------------------
1. Criar uma pasta dentro de `carimbos/` (ex.: `meus_carimbos/`).
2. Adicionar arquivos `.txt` com o desenho — cada linha representa uma linha do desenho.
3. Evitar caracteres de controle; usar `$` para posições que devem ser preenchidas dinamicamente se desejado.
4. Reiniciar o programa; o diretório é lido dinamicamente na inicialização.
