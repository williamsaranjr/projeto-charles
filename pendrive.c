/**
 * Júlia Vitória Bomfim do Nascimento - 10425604
 * William Saran dos Santos Junior - 10420128
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "file_utils.h"

#define MINIMO 0
#define MAXIMO_ARQUIVOS 50

#define NUMERO_PENDRIVES 2

int n_testes, tamanho_pendrives, t_arquivos;
int contador = 1; // Contador de casos de teste

int calcular(int pendrive[], int n) {
    int soma = 0;

    for (int i = 0; i < n; i++) {
        soma += pendrive[i];
    }

    return soma;
}

void imprimir(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void limpar(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }
}

int backtracking(int *pendrives[], int n, int m,
    int tamanho_pendrive, int *arquivos, int n_arquivos, int _i,
    FILE* arquivo, int contador) {
    if (_i == n_arquivos) { // Se todos os arquivos foram alocados
        for (int i = 0; i < NUMERO_PENDRIVES; i++) {
            int nPendrive = i == 0 ? n : m;
            char pendrive = 'A' + i;
            fprintf(arquivo, "[%d] Pendrive %c - %d GB\n", contador, pendrive, tamanho_pendrive / 2);
            for (int j = 0; j < nPendrive; j++) {
                fprintf(arquivo, "[%d] %d GB\n", contador, pendrives[i][j]);
            }
            fprintf(arquivo, "\n");
        }
        return 0; // Foi encontrada uma solução
    }
    for (int i = 0; i < NUMERO_PENDRIVES; i++) {
        for (int j = _i; j < t_arquivos; j++) {
            int index = i == 0 ? n : m;
            if (calcular(pendrives[i], index) + arquivos[_i] <= tamanho_pendrive / 2) {
                pendrives[i][index] = arquivos[_i];
                if (backtracking(pendrives, n + (i == 0), m + (i == 1), tamanho_pendrive, arquivos, n_arquivos, _i + 1, arquivo, contador) == 0) {
                    return 0;
                }
                pendrives[i][index] = 0;
            }
        }
    }
    return 1;
}

void executar(FILE *entrada, FILE *saida) {
    /**
     * Lê a linha do número de casos e tenta converter para um inteiro
     * Se falhar, entra no if e exibe uma mensagem de erro
     * Se funcionar, o valor do inteiro é salvo na variável n_testes
     */
    if (fscanf(entrada, "%d", &n_testes) != 1) {
        printf("[EXEC] Houve um erro ao extrair o número de casos de teste\n");
        return;
    } else if (n_testes <= MINIMO) {
        printf("[EXEC] O número de testes deve ser maior que 0\n");
        return;
    }
    printf("[EXEC] Número de casos de teste: %d\n\n", n_testes);

    // Itera sobre todos os casos de teste
    while (n_testes--) {
        /**
         * Lê a linha do tamanho do pen drive e o número de arquivos e os converte para inteiros
         */
        if (fscanf(entrada, "%d %d", &tamanho_pendrives, &t_arquivos) != 2) {
            printf("[EXEC @ %d] Houve um erro ao extrair o tamanho dos pen drives e/ou o número de arquivos\n", contador);
            return;
        // Validações da entrada
        } else if (tamanho_pendrives <= MINIMO) {
            printf("[EXEC @ %d] O tamanho dos pen drives deve ser maior que 0\n", contador);
            return;
        } else if (t_arquivos <= MINIMO || t_arquivos > MAXIMO_ARQUIVOS) {
            printf("[EXEC @ %d] O número de arquivos deve estar entre 1 e 50\n", contador);
            return;
        } // Fim das validações

        printf("[EXEC @ %d] Tamanho total dos pen drives: %d GB\n", contador, tamanho_pendrives);
        printf("[EXEC @ %d] Número de arquivos: %d\n", contador, t_arquivos);
        
        int arquivos[t_arquivos];
        limpar(arquivos, t_arquivos);

        for (int i = 0; i < t_arquivos; i++) {
            int var;
            if (fscanf(entrada, "%d", &var) != 1) {
                printf("[EXEC @ %d/%d] Houve um erro ao converter o tamanho do arquivo\n", contador, i + 1);
                return;
            } else if (var <= MINIMO) {
                printf("[EXEC @ %d/%d] O tamanho do arquivo deve ser maior do que 0\n", contador, i + 1);
                return;
            }
            arquivos[i] = var;
        }
        // Inicialização dos pendrives
        int pendriveA[t_arquivos];
        int pendriveB[t_arquivos];
        limpar(pendriveA, t_arquivos);
        limpar(pendriveB, t_arquivos);
        int *pendrives[] = {
            pendriveA, pendriveB
        }; // Inicializando todos os pendrives com 0
        fprintf(saida, "[%d] Armazenamento total: %d GB\n", contador, tamanho_pendrives);
        int pen = 0;
        int pen1 = 0;

        if (backtracking(pendrives, pen, pen1, tamanho_pendrives, arquivos, t_arquivos, 0, saida, contador) == 1) {
            printf("[EXEC @ %d] Não foi possível alocar todos os arquivos\n", contador);
            fprintf(saida, "[%d] Não foi possível alocar todos os arquivos\n", contador);
        } else {
            printf("[EXEC @ %d] Todos os arquivos foram alocados com sucesso\n", contador);
        }

        printf("\n");
        contador++;
    }
    printf("[EXEC] O arquivo de saída foi salvo com sucesso\n");
}