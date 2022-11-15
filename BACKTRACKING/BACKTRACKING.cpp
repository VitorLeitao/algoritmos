// iremos resolver o problema das N-queens usando BACKTRACKING, que eh posicionar N rainhas em um tabuleiro NxN sem que nenhuma esteja over atack
// precisamos inicialmente colocar a primeira rainha na row 1, e as outras nas rows sequentes 

#include <iostream>
using namespace std;
class matriz{
    public: 
    int n;
    int** M;

    matriz(int n){
        this->n = n;
        this->M = new int*[n];
        for(int c = 0; c < n; c++){
            this->M[c] = new int[n];
            for(int i = 0; i < n; i++){
                this->M[c][i] = 0;
            }
        }
    }
};

bool valid(matriz m, int row, int colune){
    int c, j;
    /* Check this row on left side */
    for(c = 0; c < colune; c++){
        if(m.M[row][c]){ // se tiver algo na row é pra retornar false
            return false;
        }
    }
    /* Check upper diagonal on left side */
    for(c = row, j = colune; c >=0 && j >= 0; c--, j--){
        if(m.M[c][j]){
            return false;
        }
    }
    /* Check lower diagonal on left side */
     for(c = row, j = colune; c >=0 && j >= 0; c++, j--){
        if(m.M[c][j]){
            return false;
        }
    }
    return true;
}
bool qns(int row, matriz m){
    if(row == m.n){
        return true;
    }
    for(int c = 0; c < (m.n - 1); c++){ 
        if(valid(m, row, c) == 1){ // para cada coluna no bagui, veremos se é possivel colocar a caceta da rainha la  
            m.M[row][c] = 1; // se for possivel, colocaremos la :)
            if(qns(row + 1, m)){
                return true;
            }else{
                m.M[row][c] = 0; // caso nao seja possivel posicionar a caceta da rainha nas proximas posiçõs, voltaremos para ca, logo, precisamos colocar a posição sendo 0
            }
        } 
    }
    return false;
}

int main(){
    matriz m(5);
    if(qns(0, m)){
        cout << "passou";
    }else{
        cout << "naopassou";
    }
    return 0;
}