#include <stdio.h>
#include <stdlib.h>

// tipo link
typedef struct link{
    int element;
    struct link* next;
}link;

link* create_link(int it, link* next_value){
    link* n = (link*) malloc(sizeof(link));
    n->element = it;
    n->next = next_value;
    return n;
}
link* create_head( link* next_value){
    link* n = (link*) malloc(sizeof(link));
    n->next = next_value;
    return n;
}

// tipo lista
typedef struct list{
    link* head;
    link* tail;
    link* curr;
    int qtd; // tamanho da lista
}list;

list* create_list(){
    list* lista = (list*) malloc(sizeof(list));
    lista->curr = lista->tail = lista->head = create_head(NULL);
    lista->qtd = 0;
    return lista;
}

void inserir(list* lista, int it){
    lista->curr->next = create_link(it, lista->curr->next);
    if(lista->tail == lista->curr){
        lista->tail = lista->curr->next;
    }
    lista->qtd += 1;
}

void next(list* lista){
    if(lista->curr != lista->tail){
        lista->curr = lista->curr->next;
    }
}

int hash_function(int it, int m){ // obs-> aplica-se a função hash nas chaves tb
    int resultado = it % m;
    if(resultado < 0){
        resultado += m;
    }
    return resultado;
}

// tipo dicionario
typedef struct dictionary
{
   int size; // size of the hash table
   int cnt; // number of elements in the dictionary
   list** hash; // hash table as an array of lists
   int (*function)(int, int);
}dictionary;

dictionary* create_dict(int size, int* pointer_function){
    dictionary* d = (dictionary*) malloc(sizeof(dictionary));
    d->size = size;
    d->function = pointer_function;
    d->hash = (list*) malloc(sizeof(list)* size);
    for(int i = 0; i < size; i++){
        d->hash[i] = create_list();       //->>> ERRO
    }
    d->function = pointer_function;
    return d;
}

void insert(dictionary *d, int key, int it){
    int posicao = hash_function(key, d->size);
    list* lista = d->hash[posicao];
    int entrada =
}


int main(){

    return 0;
}

