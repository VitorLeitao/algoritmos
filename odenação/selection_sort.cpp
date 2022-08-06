#include <iostream>
using namespace std;

int selection_sort(int vetor, int len){
    printf("%d", vetor[0]);
}
int main(){
    int vet[4] = {45, 2, 43, 4234};
    int tam = sizeof(*vet);
    int minimo_index = 0;
    selection_sort(vet, tam);

    return 0;
}