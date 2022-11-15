// full heap - todos os elementos tem 2 filhos(menos as folhas)
// binary tree completa - se nao tiver nenhum valor lixo na array que armazena a heap
// a altura de uma arvore completa é logN
#include <iostream>
#include <math.h>
using namespace std;


// usando heap minima para a questão especifica
int* heap_bottom_up(int* array, int index_final){ // vai comparar cada elemento com o maior de seus filhos
    for(int c = floor(index_final/2); c >= 1; c--){
        int k = c; // index do pai
        int v = array[k]; // pai
        int heap = 0;
        while((heap == 0) && (2*k <= index_final)){
            int j = 2*k; // filhos
            if(j < index_final){
                if(array[j] > array[j+1]){ // vai ver qual é o menor filho
                    j = j + 1;
                }
            }
            if(v <= array[j]){ // caso ja esteja em ordem
                heap = 1;
            }else{// caso contrario
                array[k] = array[j];
                k = j;
            }
        }
        array[k] = v; // o valor do pai vai ser atribuido ao filho(caso precise trocar)
    } 
    return array;
}


int main(){
    int num_elements;
    while(cin>>num_elements && num_elements!=0){
        int* array = new int[num_elements + 1];
        for(int c = 1; c <= num_elements; c++){
            cin >> array[c];
        }
        int index_final = num_elements;
        heap_bottom_up(array, num_elements);
        int valor_total = 0;

        while(index_final != 1){
            int num_1 = array[1];
            valor_total += num_1;
            index_final--;
            int* array_2 = new int[index_final + 1];
            int aux = 1;
            for(int i = 2; i <= (index_final + 1); i++){
                array_2[aux] = array[i];
                aux++;
            }
            array_2 = heap_bottom_up(array_2, index_final);
            int num_2 = array_2[1];
            valor_total += num_2;
            int sum = num_1 + num_2;
            array_2[1] = sum;
            array_2 = heap_bottom_up(array_2, index_final);
            array = array_2;
        }
        cout << valor_total << endl;
    }
    return 0;
}