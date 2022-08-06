#include <stdio.h>
#include <stdlib.h>
// add valor no tail e tira do top

typedef struct link{ // os links mais proximos do top apontam pros mais proximos do tail e o tail aponta pra NULL
    int element;
    struct link* next;
}link;

link* create_link(int it, link* next_value){
    link* n = (link*) malloc(sizeof(link));
    n->element = it;
    n->next = next_value;
    return n;
}

typedef struct queue{ 
    link* top;
    link* tail;
    int size;
}queue;

queue* create_queue(){ // faremos uso do nó header(tem valor null e aponta para o primeiro elemento)
    queue* q = (queue*) malloc(sizeof(queue));
    q->top = q->tail = create_link(NULL, NULL);
    q->size = 0;
    return q;
}

void enqueue(queue* q, int it){
    q->tail->next = create_link(it, NULL); // estamos inserindo um novo elemento no tail
    q->tail = q->tail->next;
    q->size += 1;
}

int dequeue(queue* q){
    if(q->size == 0){
        printf("error\n");
    }else{
        int it = q->top->next->element;
        link* temp = q->top->next;
        q->top->next = q->top->next->next;
        if(q->top->next == NULL){ // caso a fila fique vazia apos a remoção
            q->tail = q->top;
        }

        free(temp);
        q->size -= 1;
        return it;
    }
}

void clear(queue* q){
    q->size = 0;
    q->top = NULL;
    q->tail = NULL;
}

int front_value(queue* q){
    return q->top->next->element;
}

int length(queue* q){
    return q->size;
}



int main(){

    return 0;
}
