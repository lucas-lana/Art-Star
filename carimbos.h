#ifndef CARIMBO_H
#define CARIMBO_H

typedef struct {
    char** desenho;
    int ordem[2];
    char nome[64];
} Carimbo;

typedef struct {
    char nomePasta[128];
    int quantidade;
    Carimbo* carimbos;
} ConjuntoCarimbos;

typedef struct {
    int quantidade;
    Carimbo* carimbos;
} Carimbos_Num;
#endif