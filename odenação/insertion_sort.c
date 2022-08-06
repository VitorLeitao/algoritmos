#include <stdio.h>
#include <stdlib.h>


void insertion_sorte(int vetor[]){
    int tam = sizeof(*vetor);
    for(int c=1; c < tam; c+=1){
        int chave = vetor[c];
        int i = c - 1;
        while(i >= 0 && vetor[i] > chave){
            vetor[i+1] = vetor[i];
            i-=1;
        }
        vetor[i+1] = chave;
    }

}
int main(){
    int vet[5] = {8, 6, 7, 5, 10};
    insertion_sorte(vet);
    for(int c=0; c < 5; c+=1){
        printf("%d\n", vet[c]);
    }
    return 0;
}