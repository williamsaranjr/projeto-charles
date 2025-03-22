/**
 * Júlia Vitória Bomfim do Nascimento - 10425604
 * William Saran dos Santos Junior - 10420128
 */


#include <stdio.h>
#include <stdbool.h>

#define NUMERO_ARGUMENTOS 3

// Valida se o número de argumentos é válido
bool isEntradaValida(int count, char *argv[]) {
    if (count != NUMERO_ARGUMENTOS) {
        printf("[VLDR] Utilizar comando:\n\tbackup <ARQUIVO DE ENTRADA> <ARQUIVO DE SAÍDA>\n");
        return false;
    }
    return true;
}