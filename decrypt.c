#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Armazena a chave, o texto claro e o texto cifrado
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
    printf("Texto:\n");
    setbuf(stdin, NULL);
    scanf("%[^\n]", dados->texto_cifrado);
}

void decifrar(Dados *dados) {
    int i, car, c = 0, t = strlen(dados->chave);
    for (i = 0; i < strlen(dados->texto_cifrado); i++) {
        if (dados->texto_cifrado[i] == ' ') {
            dados->texto_claro[i] = ' ';
            continue;
        }

        car = ((dados->texto_cifrado[i] - ' ') - (dados->chave[c] - '0') + 95) % 95 + ' ';
        dados->texto_claro[i] = car;
        c = (c + 1) % t;
    }
    dados->texto_claro[i] = '\0';  // Adicionar o caractere nulo ao final da string
}


void imprime(Dados *dados)
{
    printf("Chave: %s\n", dados->chave);
    printf("Texto Cifrado: %s\n", dados->texto_cifrado);
    printf("Texto Decifrado: %s\n", dados->texto_claro);
}

int menu(Dados *dados)
{
    pega_chave(dados);
    pega_texto(dados);
    decifrar(dados);
    imprime(dados);
}

int main()
{
    Dados *dados = (Dados *)malloc(sizeof(Dados));
    menu(dados);
    free(dados);
}
