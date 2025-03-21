#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "validador.h"
#include "file_utils.h"

#define MENSAGEM_INICIAL "-=-=- Programa de Backup -=-=-\n"
#define MENSAGEM_FINAL "-=-=-\n"

FILE *entrada;
FILE *saida;

void imprimir_mensagem_inicial() {
    printf(MENSAGEM_INICIAL);
}

void imprimir_mensagem_final() {
    int len_texto1 = strlen(MENSAGEM_INICIAL);  // Comprimento de "-=-=-="
    int len_texto2 = strlen(MENSAGEM_FINAL);  // Comprimento de "=-=-= Programa de Backup -=-=-"
    
    // Calculando o número de espaços necessários para centralizar
    int espacos_esquerda = (len_texto2 - len_texto1) / 2;
    
    // Imprimindo o texto1 centralizado em relação ao texto2
    printf("%*s%s%*s\n", espacos_esquerda, "", MENSAGEM_FINAL, espacos_esquerda + (len_texto2 - len_texto1) % 2, "");
}

int main(int count, char *argv[]) {
    imprimir_mensagem_inicial();
    if (!isEntradaValida(count, argv)) {
        return 1;
    }
    entrada = carregar_arquivo(argv[1], MODO_LEITURA);
    saida = carregar_arquivo(argv[2], MODO_ESCRITA);
    if (entrada == NULL || saida == NULL) {
        printf("[ERRO] Um dos arquivos não pôde ser aberto\n");
    }

    imprimir_mensagem_final();
    return 0;
}