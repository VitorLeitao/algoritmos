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
            i = i + 1;
        }while((array[i] <= pivo) && (i <= fim));

        do{
            j = j - 1;
            
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
int BS(int* array, int inicio, int fim, int escolhido){
    if (fim >= inicio){
        int meio = (inicio + fim) / 2;
        if(array[meio] == escolhido){
            return meio;
        }else if(array[meio] > escolhido){
            BS(array, inicio, meio-1, escolhido);
        }else{
            BS(array, meio+1, fim, escolhido);
        }
    }else{
        return -1;
    }
}
int main(){
    int n;
    float k;
    cin >> n;
    cin >> k;
    int *array = new int[n];

    for(int c = 0; c < n; c++){
        cin >> array[c];
    }
    quick_sort(array, 0, n-1);
    int cont = 0;
    for(int c=0; c<n; c++){
        int posicao = BS(array, 0, n-1, array[c]+k);
        if(posicao != -1){
            cont++;
        }
    }
    cout << cont;
    return 0;

}