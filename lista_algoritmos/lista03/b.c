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

void insert(bst* arvore, int key, int e){
    arvore->root = insert_help(arvore->root, key, e);
    arvore->qtd++;
}



// travesias em bsts(preordem em ordem e posordem)
void preorder(node* no){ // root - direita - esquerda
    if(no != NULL){
        printf("%d ", no->key);
        preorder(no->pointer_left);
        preorder(no->pointer_right);
    }
}

void inorder(node* no){ // direita - root - esquerda
    if(no != NULL){
        inorder(no->pointer_left);
        printf("%d ", no->key);
        inorder(no->pointer_right);
    }
}

void posorder(node* no){
    if(no != NULL){
        posorder(no->pointer_left);
        posorder(no->pointer_right);
        printf("%d ", no->key);
    }
}


int main(){
    int tamanho;
    scanf("%d", &tamanho);
    bst* arvore = create_bst();
    int num;
    for(int c = 0; c < tamanho; c++){
        scanf("%d", &num);
        insert(arvore, num, 0);
        
    }

    printf("Pre order : ");
    preorder(arvore->root);
    printf("\n");
    
    printf("In order  : ");
    inorder(arvore->root);
    printf("\n");

    printf("Post order: ");
    posorder(arvore->root);
    return 0;
}