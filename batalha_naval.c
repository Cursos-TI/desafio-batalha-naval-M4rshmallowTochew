#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para imprimir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Declaração do tabuleiro 10x10 inicializado com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios
    int linha_navio_vertical = 1;
    int coluna_navio_vertical = 2;

    int linha_navio_horizontal = 5;
    int coluna_navio_horizontal = 4;

    // Validação: garantir que os navios estão dentro dos limites do tabuleiro
    if (linha_navio_vertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: navio vertical ultrapassa o limite do tabuleiro.\n");
        return 1;
    }

    if (coluna_navio_horizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: navio horizontal ultrapassa o limite do tabuleiro.\n");
        return 1;
    }

    // Verificação de sobreposição simples
    int sobreposicao = 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] == 3 ||
            tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] == 3) {
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao) {
        printf("Erro: os navios estão se sobrepondo.\n");
        return 1;
    }

    // Posiciona o navio vertical no tabuleiro (valor 3)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = 3;
    }

    // Posiciona o navio horizontal no tabuleiro (valor 3)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] = 3;
    }

    // Exibe o tabuleiro com os navios posicionados
    printf("Tabuleiro:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
