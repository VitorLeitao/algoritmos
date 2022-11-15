#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    int element;
    struct node* pointer_left;
    struct node* pointer_right;
}node;


node* create_node(int key, int element){
    node* n = (node*) malloc(sizeof(node));
    n->key = key;
    n->element = element;
    n->pointer_left = n->pointer_right = NULL;
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

node* insert_help(node* no, int key, int e){
    if(no == NULL){
        return create_node(key, e);
    }
    if(no->key > key){
        no->pointer_left = insert_help(no->pointer_left, key, e);
    }else{
        no->pointer_right = insert_help(no->pointer_right, key, e);
    }
    return no;
}

int remover(bst* arvore, int key){
    int temp = findhelp(arvore->root, key);
    if(temp != NULL){
        arvore->root = remover_help(arvore->root, key);
        arvore->qtd--;
    }
    return temp;
}

node* get_min(node* no){
    if(no->pointer_left == NULL){
        return no;
    }
    return get_min(no->pointer_left);
}

node* delete_min(node* no){
    if(no->pointer_left == NULL){
        return no->pointer_right;
    }
    no->pointer_left = delete_min(no->pointer_left);
    return no;
}

node* remover_help(node* no, int key){
    if(no == NULL){
        return NULL;
    }    
    if(no->key > key){
        no->pointer_left = remover_help(no->pointer_left, key);
    }else if(no->key < key){
        no->pointer_right = remover_help(no->pointer_right, key);
    }
    else{
        if(no->pointer_left == NULL){
            node* temp = no;
            free(temp);
            return no->pointer_right;
        }else if(no->pointer_right == NULL){
            node* temp = no;
            free(temp);
            return no->pointer_left;
        }else{
            node* temp = get_min(no->pointer_right);
            no->element = temp->element;
            no->key = temp->key;
            no->pointer_right = delete_min(no->pointer_right);
        }
    }
    return no;
}


// travesias em bsts(preordem em ordem e posordem)
void preorder(node* no){ // root - direita - esquerda
    if(no != NULL){
        printf("%d", no->key);
        preorder(no->pointer_left);
        preorder(no->pointer_right);
    }
}

void inorder(node* no){ // direita - root - esquerda
    if(no != NULL){
        inorder(no->pointer_left);
        printf("%d", no->key);
        inorder(no->pointer_right);
    }
}

void posorder(node* no){
    if(no != NULL){
        posorder(no->pointer_left);
        posorder(no->pointer_right);
        printf("%d", no->key);
    }
}