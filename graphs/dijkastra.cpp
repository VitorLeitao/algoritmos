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
        linked_lists[v].push_back({wt, w});

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
            for(auto w : linked_lists[v]){// tirar != 1 e botar == 0
                if((marks[w.second] != 1) && (distance[w.second] > distance[v] + w.first)){
                    distance[w.second] = distance[v] + w.first;
                    H.push({distance[w.second], w.second});
                }
            }
        }
    }
};



int main(){

    ad_list grafo(6);
    grafo.set_edge(1, 2, 10);
    grafo.set_edge(1, 4, 3);
    grafo.set_edge(1, 3, 20);
    grafo.set_edge(2, 3, 5);
    grafo.set_edge(3, 5, 11);
    grafo.set_edge(4, 2, 2);
    grafo.set_edge(4, 5, 15);
    grafo.Dijkstra(1, 6);
    for(int c = 1; c < 6; c++){
        cout << grafo.distance[c] << endl;
    }
    return 0;
}   