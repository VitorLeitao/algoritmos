// é um set de nodes conectados uns com os outros
// cada grafo tem V vertices e E arestas, G(V, E)
// usamos (v1, v2, v3) para set ordenado, e {v1, v2, v3} para nao ordenado
// temos arestas ordenadas(assim como arvores) e arestas não ordenadas
// metodos pra percorrer grafos:
// BFS: começamos em um node, exploramos todos seus vizinhos, vizinhos dos vizinhos, e por ai vai(usamos uma fila para percorrer dessa forma)
// DFS: exploramos um node, depois seu pruimeiro vizinho ate o final, depois seu segundo vizinho ate o final, e por ai vai....(usamos uma stack)

#include <iostream>
using namespace std;
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
        for(int i = 0; i < n; i++){
            g->matrix[c][i] = -1;
        }
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

// PERCORRENDO GRAFOS
//(1) DFS


void dfs(graph* g, int v){
    //pre_visit
    g->mark[v] = 1;
    int w = first(g, v);
    while(w < g->n){
        if(g->mark[w] == 0){
            dfs(g, w);
        }
        w = next(g, v, w);
    }
    //pos_visit
}
void graph_traverse(graph* g){
    for(int i = 0; i <(g->n - 1); i++){
        g->mark[i] = 0;
    }

    for(int i = 0; i < (g->n - 1); i++){
        if(g->mark[i] == 0){
            dfs(g, i);
        }
    }
}

// TOPOSORT

void toposotr(graph* g, int v, stacks* s){
    g->mark[v] = 1;
    int w = first(g, v);
    while(w < g->n){
        if(g->mark[w] == 0){
            toposotr(g, w, s);
        }
        w = next(g, v, w);
    }
    push(s, v);
}


int main(){

    return 0;
}