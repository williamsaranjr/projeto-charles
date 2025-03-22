/**
 * Júlia Vitória Bomfim do Nascimento - 10425604
 * William Saran dos Santos Junior - 10420128
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MODO_LEITURA "r"
#define MODO_ESCRITA "w"

#define CODIGO_DE_ERRO NULL
#define CODIGO_DE_ERRO_BOOL false

#define NUMERO_PENDRIVES 2

#define MAXIMO_ARQUIVOS 50

#define NUMERO_PENDRIVES 2

// Carrega um arquivo no modo especificado e retorna um ponteiro para o arquivo
FILE* carregar_arquivo(char nome[], char modo[]) {
    FILE *arquivo = fopen(nome, modo);
    if (arquivo == NULL) { // Se houve algum erro ao abrir o arquivo, exibe uma mensagem de erro
        printf("[FILE] Houve um erro ao abrir o arquivo '%s'\n", nome);
        return CODIGO_DE_ERRO;
    }

    // O arquivo foi salvo com sucesso
    printf("[FILE] Arquivo '%s' carregado com sucesso\n", nome);
    return arquivo;
}