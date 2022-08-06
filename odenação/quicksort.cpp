#include <iostream>

using namespace std;

void swap(int* a, int* b){
    int aux = *b;
    *b = *a;
    *a = aux;
}

int partion(int* array, int inicio, int fim){
    int pivo = array[inicio];
    int i = inicio;
    int j = fim + 1;
    do{
        do{
            i++;
        }while((array[i] < pivo) && (i < fim));

        do{
            j--;
            
        }while(array[j] > pivo); // nao é >= pois se ele se igualar a index 0, J vai começar a ter valores negativos
        swap(&array[i], &array[j]);

    }while(j > i);

    swap(&array[i], &array[j]);
    swap(&array[j], &array[inicio]);
    return j;
}

void quick_sort(int* array, int inicio, int fim){
    if(fim > inicio){
        int s = partion(array, inicio, fim);
        quick_sort(array, inicio, s-1);
        quick_sort(array, s+1, fim);
    }
}

int main()
{
    int vetor[9] = {32, 77, 77, 77, 20, 25, 70, 90, 67};
    quick_sort(vetor, 0, 8);
    for(int c = 0; c <= 8; c++){
        cout << vetor[c] << endl;
    }

    }