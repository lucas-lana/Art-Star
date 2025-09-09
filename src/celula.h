#ifndef CELULA_H
#define CELULA_H

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define LINHAS 20
#define COLUNAS 80

typedef struct celula{
    char simbolo;
    bool preenchido;
}celula;

#endif // CELULA_H