#include <stdio.h>
#include <stdlib.h>

// curr vai ser uma referencia para o no da lista encadeada imediatamente antes do ponto de add


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

void move_to_star(list* lista){ 
    lista->curr = lista->head;
}
void prev(list* lista){
    if(lista->curr == lista->head){
        return;
    }
    link* temporario = lista->head;
    while(temporario->next != lista->curr){
        temporario = temporario->next;
    }
    lista->curr = temporario;
    free(temporario);
}

void next(list* lista){
    if(lista->curr != lista->tail){
        lista->curr = lista->curr->next;
    }
}

int remover(list* lista){
    if(lista->curr->next == NULL){
    return -1;
 }
    int it = lista->curr->next->element;
    if(lista->tail == lista->curr->next){
        lista->tail = lista->curr;
    }
    link* temporario = lista->curr->next;
    lista->curr->next = lista->curr->next->next;
    lista->qtd -= 1;
    free(temporario);
    return it;
}

void contador(list* lista, int tamanho, int escolhido){
    link* curr_temporario = lista->head->next;
    int contador = 0;
    for(int c = 0; c < tamanho; c++){
        if(curr_temporario->element == escolhido){
            contador++;
        }
        curr_temporario = curr_temporario->next;
    }

    printf("numero de elementos x: %d\n", contador);
    free(curr_temporario);
}

void printar(list* lista, int tamanho){
    link* curr_temporario = lista->head->next;
    for(int c = 0; c < tamanho; c++){
        printf("%d ", curr_temporario->element);
        curr_temporario = curr_temporario->next;
    }
    free(curr_temporario);
}


int main(){
    list* listinha = create_list();
    inserir(listinha, 2);
    inserir(listinha, 5);
    inserir(listinha, 2);
    inserir(listinha, 1);
    //printar(listinha, listinha->qtd);
    //printf("\n");
    contador(listinha, listinha->qtd ,2);
    next(listinha);
    remover(listinha);
    contador(listinha, listinha->qtd , 2);
    //printar(listinha, listinha->qtd);
    //printf("\n");
    remover(listinha);
    //printar(listinha, listinha->qtd);
   // printf("\n");
    contador(listinha, listinha->qtd , 5);
    next(listinha);
    next(listinha);
    remover(listinha);
    contador(listinha, listinha->qtd , 1);
    //printar(listinha, listinha->qtd);
    //printf("\n");
    
    return 0;
}