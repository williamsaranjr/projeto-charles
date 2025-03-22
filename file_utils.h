/**
 * Júlia Vitória Bomfim do Nascimento - 10425604
 * William Saran dos Santos Junior - 10420128
 */

#define MODO_LEITURA "r"
#define MODO_ESCRITA "w"

#define MAXIMO_ARQUIVOS 50

#define NUMERO_PENDRIVES 2

FILE* carregar_arquivo(char nome[], char modo[]);
void escrever_saida(FILE* saida, int pendrive[NUMERO_PENDRIVES][MAXIMO_ARQUIVOS], int tamanho, int arquivos[], int t_arquivos, int contador);