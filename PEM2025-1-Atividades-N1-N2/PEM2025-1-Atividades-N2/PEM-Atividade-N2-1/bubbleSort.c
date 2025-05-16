/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Algorítmo de Bubble Sort         *
* Data - 15/05/2025                                      * 
* Autor: Gabriel Sonada                                  *
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// Função que implementa o algoritmo de ordenação Bubble Sort
void bubbleSort(int *vetor, int n) {
    int temp;

    // Loop externo controla o número de passagens pelo vetor
    for (int i = 0; i < n - 1; i++) {
        int trocou = 0;  // Flag para verificar se houve troca nesta passagem

        // Loop interno realiza as comparações e trocas entre elementos adjacentes
        for (int j = 0; j < n - i - 1; j++) {
            // Se o elemento atual é maior que o próximo, faz a troca
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                trocou = 1; // Marca que houve troca
            }
        }

        // Se nenhuma troca foi feita nesta passagem, o vetor já está ordenado
        if (!trocou)
            break; // Encerra o loop antecipadamente para otimização
    }
}

int main() {
    int n;
    int *vetor;

    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    // Aloca memória dinamicamente
    vetor = (int *)malloc(n * sizeof(int));

    // Verifica se a alocação de memória falhou
    if (vetor == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    // Entrada dos elementos
    printf("Digite %d números inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Ordena o vetor
    bubbleSort(vetor, n);

    // Exibe o vetor ordenado
    printf("Vetor ordenado em ordem crescente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(vetor);

    return 0;
}
