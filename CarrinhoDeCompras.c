#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <stdlib.h> // Biblioteca padrão para funções utilitárias
#include <string.h> // Biblioteca para manipulação de strings

int main() {
    // Definição dos produtos disponíveis
    int codigos[] = {101, 102, 103, 104, 105};
    char *nomes[] = {"Arroz", "Feijão", "Macarrão", "Farinha", "Açúcar"};
    float precos[] = {5.50, 7.30, 4.00, 3.80, 2.50};

    float carrinho[10][3]; // [10 linhas][3 colunas]: código, quantidade, subtotal
    int n = 5; // número de produtos

    // Exibe os produtos disponíveis
    printf("\n==========| PRODUTOS DISPONÍVEIS |===========\n");
    for(int i = 0; i < n; i++) {
        printf("CÓDIGO %d => %s => R$ %.2f por unidade", codigos[i], nomes[i], precos[i]);
        printf("\n=============================================\n");
    }

    int contador = 0; // contador de itens no carrinho
    int totalItens = 0; // total de itens adicionados
    char resposta; // variável para resposta do usuário ao adicionar itens

    // laço para adicionar produtos ao carrinho
    while(contador < 10 && totalItens < 10) {
        printf("\nDeseja adicionar itens ao carrinho? (s/n)\n");
        scanf(" %c", &resposta);

        if(resposta == 'n' || resposta == 'N') {
            break;
        }

        // Solicita o código do produto e a quantidade
        int quantidade, codigoDigitado;
        printf("\nDigite o código do produto e a quantidade a ser adicionada ao carrinho (Máximo 10 itens):\n");
        scanf("%d %d", &codigoDigitado, &quantidade);

        // Verifica se o código é válido
        if(codigoDigitado < 101 || codigoDigitado > 105) {
            printf("\nCódigo inválido. Tente novamente.\n");
            continue;
        }

        // Verifica se ultrapassa o limite de 10 itens
        else if(contador + quantidade > 10) {
            printf("\nQuantidade excede o limite de 10 itens no carrinho!\n");
        continue;
        }

        // calcula o índice do produto correspondente ao código digitado
        int indice = -1;
        for(int i = 0; i < n; i++) {
            if (codigos[i] == codigoDigitado) {
                indice = i;
                break;
            }
        }

        // Verifica se o produto foi encontrado
        if(indice == -1) {
            printf("\nProduto não encontrado.\n");
            continue;
        }

        // Adiciona o produto ao carrinho
        float subtotal = precos[indice] * quantidade;
        carrinho[contador][0] = codigoDigitado;
        carrinho[contador][1] = quantidade;
        carrinho[contador][2] = subtotal;
        contador++;
        totalItens += quantidade;

        printf("\nProduto adicionado: %s (x%d) — Subtotal: R$ %.2f\n", nomes[indice], quantidade, subtotal);

        if(totalItens == 10 ) {
            break;
        }
    }
    // Exibe o cabeçalho da nota fiscal
    printf("\n=============| NOTA FISCAL |============\n");
    printf("Produtos\tQtd\tPreço\tSubtotal\n\n");

    // Exibe os itens no carrinho
    float total = 0;
    for(int i = 0; i < contador; i++) {
        int codigo = carrinho[i][0];
        int indice = -1;

        // Procura no índice para obter o nome e o preço
        for(int j = 0; j < n; j++) {
            if (codigo == codigos[j]) {
                indice = j;
                break;
            }
        }
        // Exibe os detalhes do produto no carrinho
        printf("%-10s\t%.0f\t%.2f\t%.2f\n",
               nomes[indice],
               carrinho[i][1],
               precos[indice],
               carrinho[i][2]);

        total += carrinho[i][2];
    }

    printf("\nTOTAL GERAL: R$ %.2f\n", total);
    printf("========================================\n");

    return 0;
}