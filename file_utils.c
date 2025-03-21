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

FILE* carregar_arquivo(char nome[], char modo[]) {
    FILE *arquivo = fopen(nome, modo);
    if (arquivo == NULL) {
        printf("[FILE] Houve um erro ao abrir o arquivo '%s'\n", nome);
        return CODIGO_DE_ERRO;
    }
    printf("[FILE] Arquivo '%s' carregado com sucesso\n", nome);
    return arquivo;
}

void escrever_saida(FILE* saida, int *pendrive[], int tamanho, int arquivos[], int t_arquivos, int contador) {
    fprintf(saida, "[%d] Armazenamento total: %d GB\n", contador, tamanho);

    // Checa se há arquivos não alocados
    // Se houver, exibe uma mensagem de erro
    for (int i = 0; i < t_arquivos; i++) {
        if (arquivos[i] != 0) {
            fprintf(saida, "[%d] Não foi possível gravar todos os arquivos nos pen drives\n\n", contador);
            return;
        }
    }

    for (int i = 0; i < NUMERO_PENDRIVES; i++) {
        char letra = 'A' + i;
        fprintf(saida, "[%d @ %c] Pen drive %c - %d GB\n", contador, letra, letra, tamanho / 2);
        for (int j = 0; j < t_arquivos; j++) {
            // if (pendrive[i][j] != 0) {
                fprintf(saida, "[%d @ %c] %d GB\n", contador, letra, pendrive[i][j]);
            // }
        }
        fprintf(saida, "\n");
    }
}