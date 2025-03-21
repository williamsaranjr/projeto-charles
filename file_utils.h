#define MODO_LEITURA "r"
#define MODO_ESCRITA "w"

FILE* carregar_arquivo(char nome[], char modo[]);
void escrever_saida(FILE* saida, int *pendrive[], int tamanho, int arquivos[], int t_arquivos, int contador);