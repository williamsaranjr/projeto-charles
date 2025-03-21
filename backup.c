/**
 * Júlia Vitória Bomfim do Nascimento - 10425604
 * William Saran dos Santos Junior - 10420128
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "validador.h"
#include "file_utils.h"
#include "pendrive.h"

#define MENSAGEM_INICIAL "-=-=- Programa de Backup -=-=-\n"
#define MENSAGEM_FINAL "-=-=- Fim -=-=-\n"

FILE *entrada;
FILE *saida;

void imprimir_mensagem_inicial() {
    printf(MENSAGEM_INICIAL);
}

void finalizar() {
    // Fechar os arquivos
    fclose(entrada);
    fclose(saida);

    // Formatar a mensagem final
    int len_texto1 = strlen(MENSAGEM_INICIAL);
    int len_texto2 = strlen(MENSAGEM_FINAL);
    int espacos_esquerda = (len_texto2 - len_texto1) / 2;
    
    printf("%*s%s%*s\n", espacos_esquerda, "", MENSAGEM_FINAL, espacos_esquerda + (len_texto2 - len_texto1) % 2, "");
}

int main(int count, char *argv[]) {
    imprimir_mensagem_inicial();
    if (!isEntradaValida(count, argv)) {
        return 1;
    }
    char *nomeEntrada = argv[1];
    char *nomeSaida = argv[2];

    entrada = carregar_arquivo(nomeEntrada, MODO_LEITURA);
    saida = carregar_arquivo(nomeSaida, MODO_ESCRITA);
    if (!(entrada && saida)) {
        printf("[MAIN] Um dos arquivos não pôde ser aberto\n");
        return 1;
    }
    printf("[MAIN] Os arquivos '%s' e '%s' foram carregados com sucesso\n\n", nomeEntrada, nomeSaida);

    executar(entrada, saida);

    finalizar();
    return 0;
}