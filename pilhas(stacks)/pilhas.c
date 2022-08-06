#include <stdio.h>
#include <stdlib.h>

// stacks as linked lists

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
        printf("error");
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
    return s->top->element;
}

int lenght(stacks* s){
    return s->size;
}



int main(){

    return 0;
}
