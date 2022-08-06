#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int* array, int inicio, int fim){
    int tamanho = fim - inicio + 1;
    int array_temp[tamanho];
    int meio = floor((inicio + fim)/2);
    int j = 0;
    // copiando array pra uma temporaria
    for(int c=inicio; c <= fim; c++){
        array_temp[j] = array[c];
        j++;
    }
    printf("\n\n");
    for(int c=inicio; c<fim; c++){
        printf("%d ", array_temp[c]);
    }

    // variaveis que armazenam as posições que delimitam as arrays da direita e esquerda
    int i1 = inicio;
    int i2 = meio + 1;

    // comparação no estilo pilhas de baralho
    for(int c=inicio; c<fim; c++){
        if(i1 == (meio + 1)){ // quando ja varremos todos os elementos da esquerda
            array[c] = array_temp[i2];
            i2++;
        }else if(i2 > fim){ // quando ja varremos todos os elementos da direita
            array[c] = array_temp[i1];
            i1++;
        }else if(array_temp[i1] >= array_temp[i2]){ // caso o elemento da array da esquerda seja maior que o da direita
            array[c] = array_temp[i2];
            i2++;
        }else{
            array[c] = array_temp[i1];
            i1++;
        }
    }

}

void merg_sort(int* array, int inicio, int fim){
    if(fim > inicio){
        int meio = floor((inicio + fim) / 2);
        merg_sort(array, inicio, meio);
        merg_sort(array, (meio+1), fim);
        merge(array, inicio, fim);

    }
}
int main(){
    int vetor[6] = {3, 4, 1, 3, 2, 10};
    merg_sort(vetor, 0, 5);
    for(int c=0; c<6; c++){
        printf("%d\n", vetor[c]);
    }
    return 0;
}