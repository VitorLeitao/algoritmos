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
    void add(int origem, int weight, int destino){
        grafo[origem].push_back({weight, destino});
        grafo[destino].push_back({weight, origem});
    }

    // Dijkstra
    void Dijkstra(int s, int sizeofgraph){
        int Visited[sizeofgraph];
        int Parent[sizeofgraph];

        for (int i = 0; i < sizeofgraph; i++){
            D[i] = 1e9;
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

    int cases;
    int cities;
    int highways;
    int startingcity;
    int endingcity;
    int time;
    int start;
    int end;
    
    // Number of cases
    cin >> cases;

    for (int i = 0; i < cases; i++){
        cin >> cities >> highways >> startingcity >> endingcity;
        Graph *grafo = new Graph(cities + 1);
        for (int j = 0; j < highways; j++){
            cin >> start >> end >> time;
            grafo->add(start, time, end);
        }
        grafo->Dijkstra(startingcity, cities + 1); 
        
        // Print 
        if (grafo->D[endingcity] == 1e9){
            cout << "unreachable" << endl;
        }
        else{
            cout << "Case #" << i + 1 << ": " << grafo->D[endingcity] << endl;
        }
    }
    return 0;
}