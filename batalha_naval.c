#include <stdio.h>
#include <string.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Adiciona alguns navios manualmente (valor 3)
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[6][5] = 3;
}

// Função para imprimir o tabuleiro com legenda
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("=== TABULEIRO ===\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("=================\n\n");
}

// Cria uma matriz de habilidade em forma de cone (aponta para baixo)
void criarCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= TAM_HABILIDADE / 2 - i && j <= TAM_HABILIDADE / 2 + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria uma matriz de habilidade em forma de cruz
void criarCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Cria uma matriz de habilidade em forma de octaedro (losango)
void criarOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Sobrepõe uma matriz de habilidade ao tabuleiro, com ponto de origem (x, y)
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO],
                       int habilidade[TAM_HABILIDADE][TAM_HABILIDADE],
                       int origemX, int origemY) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int x = origemX + i - TAM_HABILIDADE / 2;
                int y = origemY + j - TAM_HABILIDADE / 2;

                if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO && tabuleiro[x][y] == 0) {
                    tabuleiro[x][y] = 5; // Marca área afetada
                }
            }
        }
    }
}

// Função para imprimir uma matriz de habilidade (debug)
void exibirMatrizHabilidade(int matriz[TAM_HABILIDADE][TAM_HABILIDADE], const char* nome) {
    printf("=== MATRIZ: %s ===\n", nome);
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("====================\n\n");
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);

    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Exibir matrizes de habilidades (opcional)
    exibirMatrizHabilidade(cone, "Cone");
    exibirMatrizHabilidade(cruz, "Cruz");
    exibirMatrizHabilidade(octaedro, "Octaedro");

    // Aplicar habilidades em posições diferentes
    aplicarHabilidade(tabuleiro, cone, 2, 2);      // Cone em (2,2)
    aplicarHabilidade(tabuleiro, cruz, 5, 5);      // Cruz em (5,5)
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);  // Octaedro em (7,7)

    // Exibir resultado final
    exibirTabuleiro(tabuleiro);

    return 0;
}

