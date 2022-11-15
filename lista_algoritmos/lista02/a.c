#include <stdio.h>
#include <stdlib.h>


// curr vai ser uma referencia para o no da lista encadeada imediatamente antes do ponto de add


// tipo link
typedef struct link{
    char element;
    struct link* next;
}link;

link* create_link(char it, link* next_value){
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

void inserir(list* lista, char it){
    lista->curr->next = create_link(it, lista->curr->next);
    if(lista->tail == lista->curr){
        lista->tail = lista->curr->next;
    }
    lista->qtd += 1;
}

void move_to_star(list* lista){ 
    lista->curr = lista->head;
}

void move_to_end(list* lista){
    lista->curr = lista->tail;
}

void next(list* lista){
    if(lista->curr != lista->tail){
        lista->curr = lista->curr->next;
    }
}


void printar(list* lista, int tamanho){
    link* curr_temporario = lista->head->next;
    for(int c = 0; c < tamanho; c++){
        printf("%c", curr_temporario->element);
        curr_temporario = curr_temporario->next;
    }
    free(curr_temporario);
}




int main(){
    list* frase = create_list();
    char ch;
    while(scanf("%c", &ch) != EOF){
        
        if(ch == '\n'){
            printar(frase, frase->qtd);
            printf("\n");
            frase->curr = frase->head = frase->tail = NULL;
            frase->qtd = 0;
            frase = create_list();
        }
        else if(ch == '['){
             move_to_star(frase);
        }else if(ch == ']'){
             move_to_end(frase);
        }else{
            inserir(frase, ch);
            next(frase);
        }    
    }
    printar(frase, frase->qtd);
    return 0;
}
