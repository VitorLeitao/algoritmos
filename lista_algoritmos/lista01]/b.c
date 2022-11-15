#include <stdio.h>
#include <stdlib.h>

int partion(int* array, int inicio, int fim){
    int pivo = array[inicio];
    int i = inicio;
    int j = fim + 1;
    do{
        do{
            i++;
        }while((array[i] <= pivo) && (i < fim));

        do{
            j--;
            
        }while(array[j] > pivo); // nao é >= pois se ele se igualar a index 0, J vai começar a ter valores negativos
        int aux1 = array[i];
        array[i] = array[j];
        array[j] = aux1;
        

    }while(j > i);

    int aux2 = array[i];
    array[i] = array[j];
    array[j] = aux2;


    int aux3 = array[j];
    array[j] = array[inicio];
    array[inicio] = aux3;
    return j;
}

void quick_sort(int* array, int inicio, int fim){
    if(fim > inicio){
        int s = partion(array, inicio, fim);
        quick_sort(array, inicio, s-1);
        quick_sort(array, s+1, fim);
    }
}

int main(){
    // lendo as entradas
    long long int n, k;
    long long int total=0;

    scanf("%lld", &n);

    int *array_1 = (int*)malloc(n * sizeof(int));
    for(int c = 0; c < n; c++){
        long long int analisado=0;
        scanf("%lld", &analisado);
        array_1[c] = analisado;
        total += analisado;
        
    }


    // ordenando a array de preços
    quick_sort(array_1, 0, n-1);
    scanf("%lld", &k);
    long long int num;
    for(int c = 0; c < k; c++){
        scanf("%lld", &num);
        int indice = n - num;
        printf("%lld\n", total - array_1[indice]); 
    }

    return 0;
}

