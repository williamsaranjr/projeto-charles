/**
 * Júlia Vitória Bomfim do Nascimento - 10425604
 * William Saran dos Santos Junior - 10420128
 */


#include <stdio.h>
#include <stdlib.h>

#define MODO_LEITURA "r"
#define MODO_ESCRITA "w"

#define CODIGO_DE_ERRO NULL

FILE* carregar_arquivo(char nome[], char modo[]) {
    FILE *arquivo = fopen(nome, modo);
    if (arquivo == NULL) {
        printf("[FILE] Houve um erro ao abrir o arquivo '%s'\n", nome);
        return CODIGO_DE_ERRO;
    }
    printf("[FILE] Arquivo '%s' carregado com sucesso\n", nome);
    return arquivo;
}