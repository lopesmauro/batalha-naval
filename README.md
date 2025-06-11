# 🌊 Batalha Naval - Habilidades Táticas em C

Este programa implementa uma versão estendida do clássico jogo de Batalha Naval, introduzindo o conceito de **habilidades táticas** em formato de matrizes. Os jogadores podem visualizar o tabuleiro de jogo e a aplicação de diferentes tipos de habilidades, que afetam áreas específicas do oceano.

---

## 🚀 Funcionalidades

-   **Tabuleiro de Batalha Naval:** Inicialização de um tabuleiro $10 \times 10$ com áreas de "água" e "navios" pré-definidas.
-   **Habilidades Táticas:** Geração de três tipos distintos de habilidades em matrizes $5 \times 5$:
    -   **Cone:** Uma área de efeito em formato de cone.
    -   **Cruz:** Uma área de efeito em formato de cruz.
    -   **Octaedro (Losango):** Uma área de efeito em formato de losango.
-   **Aplicação de Habilidades:** Simulação da aplicação das habilidades no tabuleiro principal, marcando as áreas afetadas.
-   **Visualização Clara:** Exibição do tabuleiro de jogo antes e depois da aplicação das habilidades, permitindo entender o impacto de cada uma.
-   **Modularidade:** Código organizado em funções para inicialização, criação e aplicação de habilidades, e exibição.

---

## 🧠 Conceitos Abordados

-   **Estruturas de Dados:** Utilização de matrizes (arrays bidimensionais) para representar o tabuleiro de jogo e as habilidades.
-   **Manipulação de Matrizes:** Funções para preencher e modificar elementos de matrizes.
-   **Controle de Fluxo:** Uso de laços `for` para iterar sobre as matrizes e condicionais `if-else` para definir a lógica das formas das habilidades e suas aplicações.
-   **Funções:** Organização do código em funções para melhor legibilidade e reusabilidade.
-   **Lógica Geométrica:** Implementação de lógica para criar formas geométricas específicas dentro das matrizes de habilidade.

---

## 🛠️ Como compilar e rodar

1. Clone este repositório:
  ```bash
  git clone https://github.com/lopesmauro/batalha-naval.git
  cd batalha-naval
  ```

2.  **Compile o programa:**

    ```bash
    gcc batalha_naval.c -o batalha_naval
    ```

3.  **Execute o programa:**

    ```bash
    ./batalha_naval
    ```

---

## ✅ Requisitos Atendidos

-   **Tabuleiro Representado:** O jogo utiliza uma matriz para simular o tabuleiro.
-   **Habilidades Distintas:** Criação de diferentes padrões de habilidades (cone, cruz, octaedro).
-   **Aplicação de Habilidades:** As habilidades são sobrepostas ao tabuleiro em coordenadas específicas.
-   **Visualização do Resultado:** O tabuleiro final, com as áreas afetadas pelas habilidades, é exibido.
-   **Código Estruturado:** O programa é modular e legível, com funções bem definidas.

---

## 🧑‍💻 Autor

Nome: Mauro Felipe Souza Lopes

Curso: Engenharia de Software - Estácio

Desafio: Super Trunfo - Nível Avançado
