#include <iostream>
using namespace std;
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


int main(){

    return 0;
}