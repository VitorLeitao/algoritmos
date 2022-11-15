#include <iostream>
using namespace std;

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

typedef struct graph{
    int** matrix;
    int num_edge;
    int* mark; // visitado = 1, nao visitado = 0
    int n;
}graph;

graph* create_graph(int n){
    graph* g = new graph;
    g->mark = new int[n];
    g->matrix = new int*[n];
    for(int c = 0; c < n; c++){
        g->matrix[c] = new int[n];
    }
    g->num_edge = 0;
    g->n = n;
    return g;
}

int first(graph* g, int v){ // vai retornar o indice do primerio vertice que V se conecta, vamos varrer todas as colunas que se encontram na linha V
for(int i = 0; i < (g->n - 1); i++){
    if(g->matrix[v][i] != -1){
        return i;
    }
    return g->n; // se V nao se ligar a ngm, retornamos a quantidade de nos do grafo
    }
}

int next(graph* g, int v, int w){ // returna o indice do primeiro vertice que V se liga depois de passar por W, vamos varrer todas as colunas depois de W

for(int i = w + 1; i < (g->n - 1); i++){
    if(g->matrix[v][i] != -1){
        return i;
    }
    return g->n;
}
}

void set_edge(graph* g, int i, int j, int wt){ // vamos criar uma aresta entre i e j de peso wt
    if(wt == -1){
        return;
    }   
    if(g->matrix[i][j] == -1){
        g->num_edge++;
    }
    g->matrix[i][j] = wt;
}

void del_edge(graph* g, int i, int j){ // vai deletar a aresta entre i e j
    if(g->matrix[i][j] != -1){
        g->num_edge--;
    }
    g->matrix[i][j] = -1;
}

void bfs(graph* g, int start){
    queue* q = create_queue();
    enqueue(q, start);
    g->mark[start] = 1;
    while(q->size > 0){
        int v = dequeue(q);
        //pre_visit
        int w = first(g, v);
        while(w < g->n){
            if(g->mark[w] == 0){
                g->mark[w] == 1;
                enqueue(q, w); 
            }
            w = next(g, v, w);
        }
        //pos_visito
    }


}
void graph_traverse(graph* g){
    for(int i = 0; i <(g->n - 1); i++){
        g->mark[i] = 0;
    }

    for(int i = 0; i < (g->n - 1); i++){
        if(g->mark[i] == 0){
            bfs(g, i);
        }
    }
}

int main(){

    return 0;
}