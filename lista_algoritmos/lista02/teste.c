#include <stdio.h>
#include <stdlib.h>


typedef struct link{ // no link em pilhas, o ponteiro aponta pra quem está abaixo da pilha, sendo assim, o ultimo elemento vai apontar pra NULL
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

typedef struct stacks
{
    link* top;
    int size;
}stacks;


stacks* create_stack(){
    stacks* stack = (stacks*) malloc(sizeof(stacks));
    stack->size = 0;
    stack->top = NULL;
    return stack;
}

void push(stacks* s, int it){
    s->top = create_link(it, s->top);
    s->size += 1;
}

int pop(stacks* s){
    if(s->top == NULL){
        
    }else{
        int it = s->top->element;
        link* temp = s->top;
        s->top = s->top->next;
        s->size -= 1;
        free(temp);
        return it;
    }
}

int top_value(stacks* s){
    if(s->size <= 0){
        return -1;
    }else{
        return s->top->element;
    }
}

int lenght(stacks* s){
    return s->size;
}
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

void printar(list* lista, int tamanho){
    link* curr_temporario = lista->head->next;
    for(int c = 0; c < tamanho; c++){
        printf("%d ", curr_temporario->element);
        curr_temporario = curr_temporario->next;
    }
    free(curr_temporario);
}


int main(){
    int entrada_trem;
    while(entrada_trem != 0){
        scanf("%d", &entrada_trem);
        if(entrada_trem == 0){
            break;
        }
        int* array_b = (int*) malloc(entrada_trem * sizeof(int)); // forma como ele quer que os trens cheguem(array B)

        //array A(como eles entram)
        list* array_a = create_list();
        for(int c = 1; c <= entrada_trem; c++){
            inserir(array_a, c);
            next(array_a);
        }
        

        int continuar = 1;
        while(continuar == 1){
            // lendo as arrays
            array_a->curr = array_a->head->next;
            for(int c = 0; c < entrada_trem; c++){
                scanf("%d", &array_b[c]);
                if(array_b[c] == 0){
                    continuar = 0;
                    break;
                }
            }
            if(continuar == 0){
                break;
            }

        // ======================================================================================
        stacks* stack = create_stack();
        int resposta = 1;
        for(int c = 0; c < entrada_trem; c++){
            int achou = 0;
            int continuar = 1; // PROCURAR NA ARRAY A E NA PILHA
            for(int i = 0; i < entrada_trem; i++){ // iremos ver se o elemento está na array A
                if(continuar == 0){
                    break;
                }
                if(array_a->qtd > 0){
                    if(array_b[c] == array_a->curr->element){ 
                        achou = 1;
                        if(array_a->curr != array_a->tail){
                                array_a->curr = array_a->curr->next;
                            }
                        continuar = 0;
                    }
                    else{
                        
                        // iremos ver se o elemento esta no topo da pilha
                        if(array_b[c] == top_value(stack)){
                            achou = 1;
                            int removido = pop(stack);
                            continuar = 0;
                        }
                        else{
                            
                            push(stack, array_a->curr->element); 
                            if(array_a->curr != array_a->tail){
                                array_a->curr = array_a->curr->next;
                            } 
                            
                        }  
                    }
                }else{
                    continuar = 0;
                }
                    
                }
            
            // =========================================================================
            if(achou == 0){
                resposta = 0;
                break;
            }
            
        }

        if(resposta == 1){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
        
    }
    printf("\n");
}   

return 0;
}
