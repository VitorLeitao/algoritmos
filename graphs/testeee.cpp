#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:

    // Create vector
    vector<vector<pair<int, int>>> grafo;
    vector<int> D;

    // Create Graph
    Graph(int sizeofgraph){
        grafo.resize(sizeofgraph);
        D.resize(sizeofgraph);
    }

    // Add in Graph
    void add(int origem, int destino, int weight){
        grafo[origem].push_back({weight, destino});
        grafo[destino].push_back({weight, origem});
    }

    // Dijkstra
    void Dijkstra(int s, int sizeofgraph){
        int Visited[sizeofgraph];
        int Parent[sizeofgraph];

        for (int i = 0; i < sizeofgraph; i++){
            D[i] = 260603;
            Parent[i] = -1;
            Visited[i] = 0; // 0 = unvisited 
        }

        // Create Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Heap;
        Heap.push({0, s});

        D[s] = 0;
        int n;
        int w;
        for (int i = 0; i < sizeofgraph ; i++){
            do
            {
                n = Heap.top().second;
                if (Heap.empty()){
                    return;
                }
                Heap.pop();
            } while (Visited[n] != 0);

            Visited[n] = 1;

            for (auto w : grafo[n]){
                if ((Visited[w.second] != 1) && (D[w.second] > D[n] + w.first)){
                    D[w.second] = D[n] + w.first;
                    Heap.push({D[w.second], w.second});
                }
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph grafo(6);
    grafo.add(1, 2, 10);
    grafo.add(1, 4, 3);
    grafo.add(1, 3, 20);
    grafo.add(2, 3, 5);
    grafo.add(3, 5, 11);
    grafo.add(4, 2, 2);
    grafo.add(4, 5, 15);
    grafo.Dijkstra(1, 6);
    for(int c = 1; c < 6; c++){
        cout << grafo.D[c] << endl;
    }
    return 0;
}