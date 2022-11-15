#include <iostream>
using namespace std;

typedef struct node
{
    int key;
    int element;
    int height;
    int index; // o index funciona basicamente como a quantidade de elementos a esquerda do numero
    struct node* pointer_left;
    struct node* pointer_right;
}node;

node* create_node(int key, int element){
    node* n = (node*) malloc(sizeof(node));
    n->key = key;
    n->element = element;
    n->pointer_left = n->pointer_right = NULL;
    n->height = 0;
    n->index = 0;
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

// o motivo de precisarmos de um contador é pq apesar de termos informações sobre a quantidade de elementos a esqueda de cada numero, nao temos informações sobre o numero de elementos que passaram antes de chegar nele(no caso do elemento estar a direita do root) por isso precisamos do contador para armazenar o numero de elementos que foram passados ate chegar no elemento atual
int get_index(node* no, int key, int contador){
    if(no->key > key){
        return get_index(no->pointer_left, key, contador);
    }else if(key == no->key){
        return contador + no->index; // caso tenha achado, somaremos o numero de elementos da esquerda do no atual com todos os outro numeros de elemtnos a esquerda somados ate esse ponto da função
    }else{
        contador = contador + no->index + 1; // caso esteja a direita, temos que somar ao cont todos os elementos a esquerda do elemento anterior a ele, uma vez que no inorder esses elementos vão ser contados antes
        return get_index(no->pointer_right, key, contador);
    }
}

int findhelp(node* no, int key){
    if(no == NULL){
        return 0; // caso nao tenha achado
    }
    if(no->key > key){
        return findhelp(no->pointer_left, key); // caso esteja a esquerda
    }else if(no->key == key){
        return 1;
    }else{
        return findhelp(no->pointer_right, key);
    }
}

int find(bst* arvore, int key){
    return findhelp(arvore->root, key);
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
    r->height = max(h(r->pointer_left), h(r->pointer_right)) + 1;
    r->index = r->index + r->pointer_left->index + 1; // como eu ja tinha alterado o r->pointer_left para ser igual a root, o r vai ganhar index a mais pois a root(agora o r->pointer_left) vai estar a sua esquerda, logo, ele vai ganhar o numero de elementos a esquerda da root + 1(o proprio root)
    return r;
}

node* right_rotation(node* no){
    no->index =  no->index - (no->pointer_left->index + 1); // o no->index vai perder a quantidade de elementos a esqueda correspondente ao index do no->pointerletf + 1, pois ele msm tb entra na conta
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
    }else if(no->key > key){ // elemento inserido vai para a esquerda
        no->index = no->index + 1;
        no->pointer_left = insert_help(no->pointer_left, key, element);
    }else{ // elemento inserido vai para a direita
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

void insert(bst* arvore, int key, int e){
    arvore->root = insert_help(arvore->root, key, e);
    arvore->qtd++;
}


int main(){
    bst* arvore = create_bst();
    int quantidade;
    cin >> quantidade;
    for(int c = 0; c < quantidade; c++){
        int tipo_comando, numero;
        cin >> tipo_comando;
        cin >> numero;
        if(tipo_comando == 1){
            insert(arvore, numero, numero); // numero vai ser usado como elemento e chave ao msm tempo
        }else{
            int achou = find(arvore, numero);
            if(achou == 0){ // caso tenha achado
                cout << "Data tidak ada" << endl;
            }else{
                int index = get_index(arvore->root, numero, 0);
                cout << index+1 << endl;
            }
        }
    }

    return 0;
}



