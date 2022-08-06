#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int max_size;
    int list_size;
    int c;
    int* list_array;
}list;


list* create_list(int size) {
    list* l = (list*) malloc(sizeof(list));
    l->max_size = size;
    l->list_size = l->c = 0;
    l->list_array = (int*) malloc(size * sizeof(int));
    return l;
}

void inserir(list* lista, int it){
    if((lista->list_size >= lista->max_size)){
       printf("error\n");
    }else{
        int i = lista->list_size;
        while(i > lista->c){
            lista->list_array[i] = lista->list_array[i-1];
            i--; 
        }
        lista->list_array[lista->c] = it;
        lista->list_size += 1;
    }
}

int remover(list* lista){
    if((lista->c < 0) || (lista->c >= lista->list_size)){
        return 0;
    }else{
        int removido = lista->list_array[lista->c];
        int i = lista->c;
        while(i < (lista->list_size - 1)){
            lista->list_array[i] = lista->list_array[i+1];
            i++;
        }
        lista->list_size -= 1;
        return removido;
    }
}


void mover_comeco(list* lista){
    lista->c = 0;
}

void mover_fim(list* lista){
    lista->c = lista->list_size;
}

void cursor_proximo(list* lista){
    if(lista->c < lista->list_size){
        lista->c += 1;
    }
}
    
void cursor_anterior(list* lista){
    if(lista->c != 0){
        lista->c-- ;
    }
}

void contador(list* lista, int numero){
    int cont = 0;
    for(int c=0; c < lista->list_size; c++){
        if(lista->list_array[c] == numero){
            cont++;
        }
    }
    printf("%d\n", cont);
}

void print(list* lista, int tamanho){
    for(int c=0; c < tamanho; c++){
        printf("%d\n", lista->list_array[c]);
    }
}


int main(){
    list* listinha = create_list(10);
    inserir(listinha, 2);
    inserir(listinha, 5);
    inserir(listinha, 2);
    inserir(listinha, 1);
    contador(listinha, 2);
    cursor_proximo(listinha);
    remover(listinha);
    contador(listinha, 2);
    remover(listinha);
    contador(listinha, 5);
    cursor_proximo(listinha);
    cursor_proximo(listinha);
    remover(listinha);
    contador(listinha, 1);
    printf("ola");
    
    return 0;
}






