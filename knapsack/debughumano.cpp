#include <iostream>
using namespace std;

void marcar(int **F, int i, int j){// quantidade capacidade

    for(int a = 0; a<i; a++) {
        for(int b = 0; b<j; b++){
            if(a==0 || b==0) F[a][b] = 0; //PARTES EXTERNAS DA MATRIZ
            else F[a][b] = -1; //PARTES INTERNAS DA MATRIZ
        }
    }
}

int knp(int qtd, int w, int* peso, int* valor, int** F){
    int v;
    if(F[qtd][w] < 0){
        if(w<peso[qtd]) v = knp(qtd-1, w, peso, valor, F);
        else{
            v = max(knp(qtd-1, w, peso, valor, F), valor[qtd] + knp(qtd-1, w - peso[qtd], peso, valor, F));
        }
        F[qtd][w] = v;
    }
    return F[qtd][w];
}

int main(){
    int cap, qtd, r;

    cin >> cap;
    cin >> qtd;

    qtd++;
    cap++;

    int** F;
    int* valor, *peso;
    valor = new int[qtd];
    peso = new int[qtd];
    F = new int*[qtd];
    F[0] = new int[cap];

    for(int i=1;i<qtd;i++){
        F[i] = new int[cap];
        cin >> peso[i];
        cin >> valor[i];
    }
    marcar(F, qtd, cap);
    r = knp(qtd-1, cap-1, peso, valor, F);
    cout << r << endl;

}