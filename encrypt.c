/*
CIFRA DE VIGENERE FEITA POR F. M.G.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// armazena a chave, o texto claro e o texto cifrado.
typedef struct sDados
{
    char chave[200];
    char texto_claro[200];
    char texto_cifrado[200];
} Dados;

// solicita ao usuário que insira a chave e remove espaços em branco da chave.
int pega_chave(Dados *dados)
{
    strcpy(dados->chave, "");
    int c, i = 0;
    printf("Chave:\n");
    setbuf(stdin, NULL);
    scanf("%[^\n]", dados->chave);
    for (i = 0; i < strlen(dados->chave); i++)
    {
        if (dados->chave[i] == ' ')
        {
            for (c = i; c < strlen(dados->chave); c++)
            {
                dados->chave[c] = dados->chave[c + 1];
            }
        }
        else
        {
            dados->chave[i] = dados->chave[i];
        }
    }
}

// solicita ao usuário que insira o texto claro.
int pega_texto(Dados *dados)
{
    printf("Texto Claro:\n");
    setbuf(stdin, NULL);
    scanf("%[^\n]", dados->texto_claro);
}

// cifra o texto claro usando a chave fornecida. Ele repete a chave até que seu tamanho seja igual ao do texto claro e, em seguida, realiza a cifragem caractere por caractere, levando em consideração o valor ASCII dos caracteres.
void cifrar(Dados *dados) {
    int i, car, c = 0, t = strlen(dados->chave);
    for (i = 0; i < strlen(dados->texto_claro); i++) {
        if (dados->texto_claro[i] == ' ') {
            dados->texto_cifrado[i] = ' ';
            continue;
        }
        
        car = ((dados->texto_claro[i] - 32) + (dados->chave[c] - 48)) % 95 + 32;
        dados->texto_cifrado[i] = car;
        c = (c + 1) % t;
    }
}

// exibe a chave, o texto claro e o texto cifrado.
void imprime(Dados *dados)
{
    printf("Chave: %s\n", dados->chave);
    printf("Texto Claro: %s\n", dados->texto_claro);
    printf("Texto Cifrado: %s\n", dados->texto_cifrado);
}

// apresenta um menu interativo que permite ao usuário escolher entre várias opções, incluindo inserir a chave, inserir o texto claro, cifrar o texto, cifrar o texto com autochave e imprimir os resultados.
int menu(Dados *dados)
{

    pega_chave(dados);
    pega_texto(dados);
    cifrar(dados);
    imprime(dados);
}

// aloca memória para a struct Dados, chama a função menu e, em seguida, libera a memória alocada.
int main()
{
    Dados *dados = (Dados *)malloc(sizeof(Dados));
    menu(dados);
    free(dados);
}