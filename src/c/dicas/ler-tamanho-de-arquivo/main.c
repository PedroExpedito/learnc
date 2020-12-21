// Na libC não tem função para isso mais com duas funções
// podemos ler
#include <stdio.h>

int main(int argc,char **argv) {

    FILE *arquivo; // ponteiro para o arquivo
    unsigned long long int tamanho; // tamanho em bytes do arquivo

    arquivo = fopen(nomeArquivo, "r");

    // verifica se o arquivo foi aberto com sucesso
    if (arquivo != NULL) {
        // movimenta a posição corrente de leitura no arquivo
        // para o seu fim
        fseek(arquivo, 0, SEEK_END);

        // pega a posição corrente de leitura no arquivo
        tamanho = ftell(arquivo);

        // imprime o tamanho do arquivo
        printf("O arquivo %s possui %ld bytes", nomeArquivo, tamanho);

    } else {
        printf("Arquivo inexistente");
    }

    return 0;

}
