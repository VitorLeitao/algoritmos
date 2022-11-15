#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int vitor = 10;
int suane = 10;
// 0 é equivaolente a nao conseguiu fugir, 1 é equivalente a conseguiu
bool labirinto(vector<vector<char>> &vec_char, int x, int y, int p , vector<vector<bool>> &visitado){
    if(vec_char[x][y] == '#' || x>=vitor || x < 0 || y >= suane || y < 0 || p < 0){
        return false; // se cair em qualquer uma dessas condições, nao podemos continuar
    }
    if(vec_char[x][y] == 'x'){
        return true;
    }
    if(!visitado[x][y]){
        visitado[x][y] = true;
    
        // vai fazer uma chamada recursiva para cada posição possivel
        if(labirinto(vec_char, x+1, y, (vec_char[x][y] == 's')?p-1:p , visitado)){
            return true;
        }
        if(labirinto(vec_char, x, y+1, (vec_char[x][y] == 's')?p-1:p , visitado)){
            return true;
        }
        if(labirinto(vec_char, x, y-1,(vec_char[x][y] == 's')?p-1:p , visitado)){
            return true;
        }
        if(labirinto(vec_char, x, y, (vec_char[x][y] == 's')?p-1:p , visitado)){
            return true;
        }

        // temos que setar como sendo uma parede 
        vec_char[x][y] = '#';
        visitado[x][y] = false;
    }
    return true;
}

int main(){
    int a, primeiro_x, primeiro_y;
    cin >> vitor >> suane >> a;
    vector<vector<char> > vec_char(vitor, vector<char>(suane, 32));
    vector<vector<bool> > visitado(vitor, vector<bool>(suane, 0));
    for(int c = 0; c < vitor; c++){
        for(int i = 0; i < suane; i++){
            cin >> vec_char[c][i];
            if(vec_char[c][i] == '@'){
                primeiro_x = c;
                primeiro_y = i;
            }
        }
    }
    string resposta;
    int aux = a / 2;
    if(labirinto(vec_char, primeiro_x, primeiro_y, aux, visitado)){
        resposta = "SUCCESS";
    }else{
        resposta = "IMPOSSIBLE";
    }
    cout << resposta << endl;
    
    return 0;
}