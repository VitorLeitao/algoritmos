#include <iostream>

#include <bits/stdc++.h>
using namespace std;

class ad_list{
    public:
        vector<vector<pair<int, int>>> linked_lists;
        vector<int> distance;
        int* marks;
        int n;

    ad_list(int n){
        this->linked_lists.resize(n);
        this->distance.resize(n);
        this->marks = new int[n];
        for(int c = 0; c < n; c++){
            this->marks[c] = 0; // inicializa-se todos os indices como nao visitados
        }
        this->n = n;
    }

    void set_edge(int v, int w, int wt){ 
        for(int c = 0; c < linked_lists[v].size(); c++){
            if(linked_lists[v][c].second == w){
                if(wt >= linked_lists[v][c].first){
                    return;
                }
            }
        }
        linked_lists[v].push_back({wt, w});
        linked_lists[w].push_back({wt, v});
    }

    void Dijkstra(int s, int size){
        int v, w;
        for(int c = 0; c < size; c++){
            distance[c] = 26062003;
        } 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> H;
        H.push({0, s});
        distance[s] = 0;
        for(int c = 0; c < size; c++){
            do{
                v = H.top().second;
                if(H.empty()){
                    return;
                }
                H.pop();
            }while(marks[v] != 0);

            marks[v] = 1;
            for(auto w : linked_lists[v]){
                if((marks[w.second] != 1) && (distance[w.second] > distance[v] + w.first)){
                    distance[w.second] = distance[v] + w.first;
                    H.push({distance[w.second], w.second});
                }
            }
        }
    }
};

// descrição do que a questao pede: vamos receber primeiramente o numero X de entradas, que consiste no numero de casos, depois disso, para cada caso, iremos ler  4 entradas, o numero N de cidades(vertices do grafo), M o numero de edges que vamos setar, o ponto de inicio S e o ponto de final T, apos isso, usaremos o dijkastra pra calcular o caminho minimo entre S e T

int main(){ 
    int entradas;
    cin >> entradas;
    for(int c = 1; c <= entradas; c++){
        int num_vertices, num_edges, origem_importante, destino_importante;
        cin >> num_vertices >> num_edges >> origem_importante >> destino_importante;
        ad_list grafo(num_vertices);
        for(int i = 0; i < num_edges; i++){
            int inicio, fim, peso;
            cin >> inicio >> fim >> peso;
            grafo.set_edge(inicio, fim, peso);
        }
        grafo.Dijkstra(origem_importante, num_vertices);
        int distancia_final = grafo.distance[destino_importante];
        if(distancia_final == 26062003){
            cout << "Case #" << c << ": " << "unreachable" << endl;
        }else{
            cout << "Case #" << c << ": " <<distancia_final << endl;
        }
    }
    return 0;
}   