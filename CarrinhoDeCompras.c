#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <stdlib.h> // Biblioteca padrão para funções utilitárias
#include <string.h> // Biblioteca para manipulação de strings

int main() {
    float carrinho[10][3], valorTotal = 0, precos[] = {5.5f, 7.2f, 4.0f, 3.8f, 2.5f};
    int codigos[] = {101, 102, 103, 104, 105}, indiceProduto = 0, indiceCarrinho = 0;
    char nomes[][20] = {"Arroz", "Feijao", "Macarrao", "Farinha", "Acucar"}, resposta = 's';

    printf("\n==========| PRODUTOS DISPONIVEIS |===========\n");

    for (int i = 0; i < 5; i++) {
        printf("CODIGO %d => %s => R$ %.2f por unidade", codigos[i], nomes[i], precos[i]);
        printf("\n=============================================\n");
    }

    while (indiceCarrinho < 10) {
        printf("\nDeseja adicionar itens ao carrinho? (s/n)\n");
        scanf(" %c", &resposta);

        if (resposta == 'n' || resposta == 'N') {
            break;
        }

        printf("Digite o codigo do produto:\n");

        scanf("%f", &carrinho[indiceCarrinho][0]);

        if ((int) carrinho[indiceCarrinho][0] < 101 || (int) carrinho[indiceCarrinho][0] > 105) {
            printf("\nCodigo invalido. Tente novamente.\n");
            continue;
        }

        printf("Digite a quantidade do produto:\n");

        scanf("%f", &carrinho[indiceCarrinho][1]);

        for (int j = 0; j < 5; j++) {
            if ((int) carrinho[indiceCarrinho][0] == codigos[j]) {
                indiceProduto = j;
                break;
            }
        }

        carrinho[indiceCarrinho][2] = carrinho[indiceCarrinho][1] * precos[indiceProduto];
        printf("\nProduto adicionado: %s (x%d) - Subtotal: R$ %.2f\n", nomes[indiceProduto],
               (int) carrinho[indiceCarrinho][1], carrinho[indiceCarrinho][2]);
        indiceCarrinho++;
    }

    // Exibe o cabeçalho da nota fiscal
    printf("\n=============| NOTA FISCAL |============\n");
    printf("Produtos\tQtd\tPreço\tSubtotal\n\n");

    for (int i = 0; i < indiceCarrinho; i++) {
        for (int j = 0; j < 5; j++) {
            if ((int) carrinho[i][0] == codigos[j]) {
                indiceProduto = j;
                break;
            }
        }

        printf("%-10s\t%.0f\t%.2f\t%.2f\n", nomes[indiceProduto], carrinho[i][1],
               precos[indiceProduto], carrinho[i][2]);

        valorTotal += carrinho[i][2];
    }
    printf("\nTOTAL GERAL: R$ %.2f\n", valorTotal);

    return 0;
}
