#include <stdio.h> 

int main() {
    float carrinho[10][3], valorTotal = 0, precos[] = {5.5f, 7.2f, 4.0f, 3.8f, 2.5f};
    int codigos[] = {101, 102, 103, 104, 105}, indiceProduto = 0, indiceCarrinho = 0;
    char nomes[][20] = {"Arroz", "Feijão", "Macarrão", "Farinha", "Açúcar"}, resposta;

    printf("\n==========| PRODUTOS DISPONÍVEIS |===========\n");

    for (int i = 0; i < 5; i++) {
        printf("CÓDIGO %d => %s => R$ %.2f por unidade", codigos[i], nomes[i], precos[i]);
        printf("\n=============================================\n");
    }

    while (indiceCarrinho < 10) {
        printf("\nDeseja adicionar itens ao carrinho? (s/n)\n");
        scanf(" %c", &resposta);

        if (resposta == 'n' || resposta == 'N') {
            if (indiceCarrinho == 0) {
                printf("\nCarrinho vazio. Nenhum item foi adicionado.\n");
                return 0;
            }
            break;
        }

        printf("\nDigite o código e a quantidade produto (Máximo 10 itens):\n");

        scanf("%f %f", &carrinho[indiceCarrinho][0], &carrinho[indiceCarrinho][1]);

        if (carrinho[indiceCarrinho][1] <= 0) {
            printf("\nQuantidade inválida. Digite um valor maior que zero.\n");
            continue;
        }
        
        if ((int) carrinho[indiceCarrinho][0] < 101 || (int) carrinho[indiceCarrinho][0] > 105) {
            printf("\nCódigo inválido. Tente novamente.\n");
            continue;
        }

        for (int j = 0; j < 5; j++) {
            if ((int) carrinho[indiceCarrinho][0] == codigos[j]) {
                indiceProduto = j;
                break;
            }
        }

        carrinho[indiceCarrinho][2] = carrinho[indiceCarrinho][1] * precos[indiceProduto];
        indiceCarrinho++;
    }

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
    printf("\nTOTAL: R$ %.2f\n", valorTotal);
    printf("========================================\n");

    return 0;
}
