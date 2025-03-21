#include <stdio.h>
#include <stdbool.h>

#define NUMERO_ARGUMENTOS 3

bool isEntradaValida(int count, char *argv[]) {
    if (count != NUMERO_ARGUMENTOS) {
        printf("[ERRO] Utilizar comando:\n\t./backup <ARQUIVO DE ENTRADA> <ARQUIVO DE SAÍDA>\n");
        return false;
    }
    return true;
}