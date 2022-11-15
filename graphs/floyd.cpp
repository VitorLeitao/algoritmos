#include <bits/stdc++.h>


using namespace std;
// ele encontra os menores caminhos entre todos os pares de nos em um grafo G, e funciona com peso negativo, mas nao deve ser ultilizado em grafos com ciclos negativos
// eficiencia temporal menos doq dijkastra

// inciamos a matriz com o cursto direto
class ad_list{
    public:
        stack<int> stacks;
        int* marks;
        int n;
        int** matriz;
        int num_edges;
        int** custo; // matriz custo

    ad_list(int n){ 
        this->num_edges = 0;
        this->matriz = new int*[n];
        for(int c = 0; c < n; c++){
            matriz[c] = new int[n];
            for(int i = 0; i < n; i++){
                matriz[c][i] = -1;
            }
        }
        this->marks = new int[n];
        for(int c = 0; c < n; c++){
            marks[c] = 0;
        }
        this->n = n;
    }

    int first(int v){
        for(int c = 0; c <= (n-1); c++){
            if(matriz[v][c] != -1){
                return c;
            }
        }
        return n;
    }

    int next(int v, int w){
        for(int c = w + 1; c <= (n - 1); c++){
            if(matriz[v][c] != -1){
                return c;
            }
        }
        return n;
    }

    void set_edge(int v, int w, int wt){
        if(wt <= 0){
            return;
        }
        if(matriz[v][w] == -1){
            num_edges++;
        }
        matriz[v][w] = wt;
    }

    void toposort(int v){
        marks[v] = 1;
        int w = first(v);
        while(w < n){

            if(marks[w] == 0){
                toposort(w);
            }
            w = next(v, w);
        }

        stacks.push(v);
    }
    void graph_traverse(){
        for(int c = 0; c < n; c++){ //estamos falando que o primeiro vertice sera 1, que nao havera vertice 0
            if(marks[c] == 0){
                toposort(c);
            }
        }
    }

    void dijk(int s){

    }

};