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
    int soma;

    for (int i = 0; i < n; i++) {
        soma += pendrive[i];
    }

    return soma;
}

void backtracking(int *pendrives[], int tamanho, int arquivos[], int t_arquivos, int _j, int offset) {
    // Condição de parada quando todos os arquivos foram alocados
    if (_j == t_arquivos) {
        return;
    }

    // Loop sobre os pendrives
    for (int i = 0; i < NUMERO_PENDRIVES; i++) {
        // Loop sobre os arquivos, começando do índice 'offset'
        for (int j = offset; j < t_arquivos; j++) {
            // Se a soma dos arquivos no pendrive e o arquivo atual for menor ou igual ao tamanho do pendrive
            if (calcular(pendrives[i], offset) + arquivos[j] <= tamanho) {
                
                // Aloca o arquivo atual no pendrive
                pendrives[i][offset] = arquivos[j];

                // Chamada recursiva com o próximo índice de arquivo
                backtracking(pendrives, tamanho, arquivos, t_arquivos, j + 1, offset + 1);
                
                // Caso a recursão não seja bem-sucedida, desfaça a alteração (backtracking)
                pendrives[i][offset] = 0;  // Opcional: Limpa o arquivo alocado se não for uma solução válida
            }
        } 
    }
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

        printf("[EXEC @ %d] Tamanho dos pen drives: %d GB\n", contador, tamanho_pendrives);
        printf("[EXEC @ %d] Número de arquivos: %d\n", contador, t_arquivos);
        
        int arquivos[t_arquivos];

        for (int i = 0; i < t_arquivos; i++) {
            if (fscanf(entrada, "%d", &arquivos[i]) != 1) {
                printf("[EXEC @ %d/%d] Houve um erro ao converter o tamanho do arquivo\n", contador, i + 1);
                return;
            } else if (arquivos[i] <= MINIMO) {
                printf("[EXEC @ %d/%d] O tamanho do arquivo deve ser maior do que 0\n", contador, i + 1);
                return;
            }
        }
        // Inicialização dos pendrives
        int pendriveA[tamanho_pendrives];
        int pendriveB[tamanho_pendrives];
        int *pendrives[] = {
            pendriveA, pendriveB
        };

        backtracking(pendrives, tamanho_pendrives, arquivos, t_arquivos, 0, 0);

        printf("\n");
        contador++;
    }

    if (!escrever_saida(saida, n_testes, tamanho_pendrives, t_arquivos)) {
        printf("[EXEC] Houve um erro ao salvar o arquivo de saída\n");
        return;
    }
    printf("[EXEC] O arquivo de saída foi salvo com sucesso\n");
}
