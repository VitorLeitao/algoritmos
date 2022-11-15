#include <stdio.h>
#include <stdlib.h>

int hash_function(int it, int m){ // obs-> aplica-se a função hash nas chaves tb
    int resultado = it % m;
    if(resultado < 0){
        resultado += m;     
    }
    return resultado;
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int* permutation(int *arr, int start, int end)
{
    if(start==end)
    {
        return arr;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        swap((arr+i), (arr+start));
        permutation(arr, start+1, end);
        swap((arr+i), (arr+start));
    }
}

typedef struct dictionary{
    int size; // size of the hash table
    int cnt; // numbers of elements in the dict
    int* array_principal; // array das entradas
    int* permutacao; // array com as posições aleatorias
    int (*function)(int, int);
}dictionary;

dictionary* create_dict(int size, int* pointer_function){
   dictionary* d = (dictionary*)malloc(sizeof(dictionary));
   d->size = d->cnt = 0;
   d->array_principal = (int*)malloc(sizeof(int) * size);
   d->permutacao = (int*)malloc(sizeof(int) * size);
   for(int c = 0; c < size; c++){
    d->permutacao[c] = c+1;
   }
   d->permutacao = permutation(d->permutacao, 0, size-1);
   d->function = pointer_function;
   return d;
}

int find(dictionary* d, int element){
    int achou = 0;
    for(int c = 0; c < d->size; c++){
        if(d->array_principal[c] == element){
            achou = 1;
            break;
        }
    }
    if(achou == 0){
        return 0;
    }else{
        return 1;
    }
}

void insert(dictionary* d, int key, int e){
    //if(d->size > )
}


int main(){

    return 0;
}