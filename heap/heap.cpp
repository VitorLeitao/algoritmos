// full heap - todos os elementos tem 2 filhos(menos as folhas)
// binary tree completa - se nao tiver nenhum valor lixo na array que armazena a heap
// a altura de uma arvore completa é logN
#include <iostream>
#include <math.h>
using namespace std;
typedef struct heap
{
    int tamanho;
    int* array;
}heap;

heap* create_heap(int tamanho){
    heap* h = (heap*)malloc(sizeof(heap));
    h->array = (int*)malloc(sizeof(int) * (tamanho+1));
    h->tamanho = tamanho;
    return h;
}

void heap_bottom_up(int* array, int tamanho, heap* h){ // vai comparar cada elemento com o maior de seus filhos
    for(int c = floor(tamanho/2); c > 1; c--){
        int k = c; // index do pai
        int v = array[k]; // pai
        int heap = 0;
        while((heap == 0) && (2*k <= tamanho)){
            int j = 2*k; // filhos
            if(j < 2){
                if(array[j] < array[j+1]){ // vai ver qual é o maior filho
                    j = j + 1;
                }
            }
            if(v >= array[j]){ // caso ja esteja em ordem
                heap = 1;
            }else{// caso contrario
                array[k] = array[j];
                k = j;
            }
        }
        array[k] = v; // o valor do pai vai ser atribuido ao filho(caso precise trocar)
    } 
    h->array = array;
}


int main(){
    int num_elements;
    while(cin>>num_elements && num_elements!=0){
        heap* h = create_heap(num_elements);
        for(int c = 1; c <= num_elements; c++){
            cin >> h->array[c];
        }
        while(h->tamanho != 1){
            
        }
    }
    return 0;
}