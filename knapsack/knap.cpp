#include <iostream>
using namespace std;


int MFKnapsack(int row, int colune, int* w, int* v, int** f){
    int value;
    if(f[row][colune] < 0){
        if(colune < w[row]){
            value = MFKnapsack(row - 1, colune, w, v, f);
        }else{
            value = max(MFKnapsack(row-1, colune, w, v, f), MFKnapsack(row-1, colune-w[row], w, v, f) + v[row]);
        }
        f[row][colune] = value;
    }
    return f[row][colune];
}


int main(){
    int capacidade, quantidade_itens;//x1 = capacidade // x2 = quantidade de itens
    cin >> capacidade >> quantidade_itens;
    capacidade+=1;
    quantidade_itens+=1;
    int* values = new int[quantidade_itens];
    int* weight = new int[quantidade_itens];
    int x1, x2;
    int** matriz = new int*[quantidade_itens];
    matriz[0] = new int[capacidade];
    for(int c = 1; c < quantidade_itens; c++){
        cin >> x1 >> x2;
        weight[c] = x1;
        values[c] = x2;
        matriz[c] = new int[capacidade];
    }

    //inicializando a matriz
    for(int c = 0; c < quantidade_itens; c++){
        for(int i = 0; i < capacidade; i++){
            if(i == 0 || c == 0){ // caso esteja nas extremidades
                matriz[c][i] = 0;
            }else{
                matriz[c][i] = -1;
            }
        }
    }

    int suane;
    quantidade_itens-=1;
    capacidade-=1;
    suane = MFKnapsack(quantidade_itens, capacidade, weight, values, matriz);
    cout << suane;
    return 0;
}