#include <bits/stdc++.h>
using namespace std;

class ad_list{
    public:
        vector<int>* linked_lists;
        stack<int> stacks;
        int* marks;
        int n;
        bool cycle;

    ad_list(int n){
        n++;
        this->cycle = false;
        this->linked_lists = new vector<int>[n];
        this->marks = new int[n];
        for(int c = 0; c < n; c++){
            marks[c] = 0;
        }
        this->n = n;
    }

    int first(int v){
        if(linked_lists[v].size() > 0){
            return linked_lists[v][0];
        }
        return n;
    }

    int next(int v, int w){
        if(linked_lists[v].size() <= 1){
            return n;
        }
        for(int c = 0; c < linked_lists[v].size(); c++){
            if(linked_lists[v][c] == w){
                if(linked_lists[v].size() > (c+1)){
                    return linked_lists[v][c+1];
                }else{
                   return n; 
                }
            }
        }
        return n;
    }

    void set_edge(int v, int w){
        linked_lists[v].push_back(w);
    }

    void toposort(int v, int fe){
        marks[v] = 1;
        int w = first(v);
        if(w == fe){
            cycle = true;
            return;
        }
        while(w < n){

            if(marks[w] == 0){
                toposort(w, fe);
            }
            w = next(v, w);
        }

        stacks.push(v);
    }
    void graph_traverse(){
        for(int c = (n - 1); c >= 1; c--){
            if(cycle == true){
                break;
            }
            if(marks[c] == 0){
                int fe = c;
                toposort(c, fe);
            }
        }
    }

    void print(){
        for(int c = 0; c < (n-1); c++){
            cout << stacks.top() << " ";
            stacks.pop();
        }
    }
    void sortLists()
        {
            for (int c = 1; c < n; c++)
            {
                sort(linked_lists[c].begin(),linked_lists[c].end(),greater<int>());
            }
        }

};

int main(){
    int a, b;
    int num1, num2;
    cin >> a;
    cin >> b;
    ad_list graph(a);
    for(int c = 0; c < b; c++){
        cin >> num1 >> num2;
        graph.set_edge(num1, num2);
    }
    graph.sortLists();
    graph.graph_traverse();
    if(graph.cycle == true){
        cout << "Sandro fails.";
    }else{
        graph.print();
    }
    return 0;
}