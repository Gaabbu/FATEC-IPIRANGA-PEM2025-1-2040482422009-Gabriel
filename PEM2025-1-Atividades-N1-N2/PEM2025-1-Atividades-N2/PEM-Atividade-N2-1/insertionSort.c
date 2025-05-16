/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Algorítmo de Insertion Sort      *
* Data - 15/05/2025                                      * 
* Autor: Gabriel Sonada                                  *
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// Função que implementa o algoritmo de ordenação Insertion Sort
void insertionSort(int vetor[], int n) {
    int i, chave, j;
    
    for (i = 1; i < n; i++) {
        chave = vetor[i];       // Elemento atual a ser inserido na parte ordenada
        j = i - 1;

        // Move os elementos maiores que a chave uma posição à frente
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }

        // Insere a chave na posição correta
        vetor[j + 1] = chave;
    }
}

int main() {
    int n, i;
    int *vetor;
    
    // Solicita ao usuário o número de elementos
    printf("Digite o número de elementos que você deseja ordenar: ");
    scanf("%d", &n);
    
    // Aloca memória dinamicamente para o vetor
    vetor = (int*) malloc(n * sizeof(int));
    
    // Verifica se a alocação de memória falhou
    if (vetor == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    // Lê os elementos fornecidos pelo usuário
    printf("Digite os %d números inteiros:\n", n);
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    
    // Ordena o vetor usando Insertion Sort
    insertionSort(vetor, n);
    
    // Exibe o vetor ordenado
    printf("Vetor ordenado em ordem crescente: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(vetor);
    
    return 0;
}
