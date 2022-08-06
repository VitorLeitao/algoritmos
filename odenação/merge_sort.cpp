#include <iostream>
#include <math.h>
using namespace std;

void merge(int* array, int inicio, int fim, int tamanho){
    int meio = floor((inicio + fim) / 2);

    // criando a array temp, e colocando apenas os valores que vao ser usados, mas mantendo o tamanho N
    int* array_temp = new int[tamanho];
    for(int c = inicio; c <= fim; c++){
        array_temp[c] = array[c]; 
    }   
    
    // variaveis que armazenam as posições que delimitam as arrays da direita e esquerda
    int i1 = inicio;
    int i2 = meio + 1;

    // comparação no estilo pilhas de baralho
    for(int c=inicio; c <= fim; c++){
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
    delete[] array_temp;
    
}

void merg_sort(int* array, int inicio, int fim, int tamanho){
    if(fim > inicio){
        int meio = floor((inicio + fim) / 2);
        merg_sort(array, inicio, meio, tamanho);
        merg_sort(array, (meio+1), fim, tamanho);
        merge(array, inicio, fim, tamanho);

    }
}
int main(){
    int vetor[5] = {4, 1, 7, 2, 10};
    merg_sort(vetor, 0, 4, 5);
    for(int c=0; c<5; c++){
        cout << vetor[c] << endl;
    }
    return 0;
}