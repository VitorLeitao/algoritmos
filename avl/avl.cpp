#include <iostream>
using namespace std;

typedef struct node
{
    int key;
    int element;
    int height;
    struct node* pointer_left;
    struct node* pointer_right;
}node;

node* create_node(int key, int element){
    node* n = (node*) malloc(sizeof(node));
    n->key = key;
    n->element = element;
    n->pointer_left = n->pointer_right = NULL;
    n->height = 0;
    return n;
}

typedef struct bst
{
    node* root;
    int qtd; // quantidade de nodes
}bst;

bst* create_bst(){
    bst* arvore = (bst*) malloc(sizeof(bst));
    arvore->qtd = 0;
    arvore->root = NULL;
    return arvore;
}


int findhelp(node* no, int key){
    if(no == NULL){
        return NULL;
    }
    if(no->key > key){
        return findhelp(no->pointer_left, key);
    }else if(no->key == key){
        return no->element;
    }else{
        return findhelp(no->pointer_right, key);
    }
}

int find(bst* arvore, int key){
    return findhelp(arvore->root, key);
}

void insert(bst* arvore, int key, int e){
    arvore->root = insert_help(arvore->root, key, e);
    arvore->qtd++;
}

int max(int c, int i){
    int maior;
    if(c > i){
        maior = c;
    }else{
        maior = i;
    }
    return maior;
}

int h(node* no){
    if(no == NULL){
        return -1;
    }
    return no->height;
}

int get_balance(node* no){
    int dif;
    if(no == NULL){
        return 0;
    }
    dif = h(no->pointer_left) - h(no->pointer_right);
    return dif;
}


node* left_rotation(node* no){
    node* r = no->pointer_right;
    node* rl = r->pointer_left;
    r->pointer_left = no;
    no->pointer_right = rl;
    no->height = max(h(no->pointer_left), h(no->pointer_right)) + 1;
    r->height = max(h(no->pointer_left), h(no->pointer_right)) + 1;
    return r;
}

node* right_rotation(node* no){
    node* l = no->pointer_left;
    node* lr = l->pointer_right;
    l->pointer_right = no;
    no->pointer_left =  lr;
    no->height = max(h(no->pointer_left), h(no->pointer_right)) + 1;
    l->height = max(h(l->pointer_right), h(l->pointer_left)) + 1;
    return l;
}
node* insert_help(node* no, int key, int element){
    if(no == NULL){
        return create_node(key, element);
    }else if(no->key > key){
        no->pointer_left = insert_help(no->pointer_left, key, element);
    }else{
        no->pointer_right = insert_help(no->pointer_right, key, element);
    }

    no->height = max(h(no->pointer_left), h(no->pointer_right)) + 1;
    int balance = get_balance(no);
    if((balance < -1) && (key >= no->pointer_right->key)){
        return left_rotation(no);
    }else if((balance > 1) && (key < no->pointer_left->key)){
        return right_rotation(no);
    }else if((balance > 1) && (key >= no->pointer_left->key)){
        no->pointer_left = left_rotation(no->pointer_left);
        return right_rotation(no);
    }else if((balance < - 1) && (key < no->pointer_right->key)){
        no->pointer_right = right_rotation(no->pointer_right);
        return left_rotation(no);
    }
    return no;
}



