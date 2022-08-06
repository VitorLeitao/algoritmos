#include <stdio.h>
#include <stdlib.h>
// para cada posição X, descobrimos o valor minimo entre X->final e, se o valor minimo for menor que o valor na posição X, efetuamos a troca entre os dois.
void selection_sort(int vetor[]){
    int tam = sizeof(*vetor);
    for(int c=0; c < (tam-1); c+=1){
        int index_minimo = c;

        for(int i = (c + 1); i < tam; i +=1){ // i = c+1 pq temos que começar da posição X, senao sempre daria o menor valor vetor[c]
            if(vetor[i] < vetor[index_minimo]){
                index_minimo = i;
            }
        }

        if(vetor[index_minimo] < vetor[c]){
            int aux = vetor[index_minimo];
            vetor[index_minimo] = vetor[c];
            vetor[c] = aux;
        }
    }

    //return vetor;
}
int main(){
    int vet[4] = {45, 2, 43, 4234};
    selection_sort(vet);
    for(int c=0; c < 4; c+=1){
        printf("%d\n", vet[c]);
    }

    return 0;
}