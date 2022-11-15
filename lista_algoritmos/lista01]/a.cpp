#include <iostream>
#define endl '\n'
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

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    // lendo as entradas
    long long int n, k;
    long long int total=0;

    //cin >> n;
    scanf("%lld", &n);
    int *array_1 = new int[n];

    for(int c = 0; c < n; c++){
        long long int analisado;
        //cin >> analisado;
        scanf("%lld", &analisado);
        array_1[c] = analisado;
        total += analisado;
    }

    // ordenando a array de preços
    quick_sort(array_1, 0, n-1);

    //cin >> k;
    scanf("%lld", &k);
    long long int num;
    for(int c = 0; c < k; c++){
        //cin >> num;
        scanf("%lld", &num);
        long long int indice = n - num;
        //cout << total - array_1[indice] << endl;
        printf("%lld\n", total - array_1[indice]); 
    }

    return 0;
}

