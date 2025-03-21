#define MODO_LEITURA "r"
#define MODO_ESCRITA "w"

FILE* carregar_arquivo(char nome[], char modo[]);
bool escrever_saida(FILE* saida, int n, int tamanho_pendrive, int t_arquivos);