#include <iostream>
using namespace std;
class matriz{
    public: 
    int n;
    int num_rows_usados;
    int** M;

    matriz(int n, int rows){
        this->num_rows_usados = rows;
        this->n = n;
        this->M = new int*[n];
        for(int c = 0; c < 10; c++){
            this->M[c] = new int[n];
            for(int i = 0; i < 10; i++){
                this->M[c][i] = 1; // todos vao iniciar como 1 e vou colocar 0 aqueles que a questao der(1 = nao posso visitar)
            }
        }
    }
};
int final = 0;
int array_next_row[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int array_next_colune[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void qns(int row, int colune, matriz m, int cont){
    for(int c = 0; c < 8; c++){// para cada posição, vamos testar as 8 possibilidades de movimento
        int new_row = row + array_next_row[c];
        int new_colune = colune + array_next_colune[c];
        if(new_row >= 0 && new_row < m.num_rows_usados && new_colune >= 0 && new_colune < 10 && m.M[new_row][new_colune] == 0){
            m.M[new_row][new_colune] = 1; // temos que colocar um numero especial pra onde o cavalo ta no momento, uma vez que na recursão nao devemos contar essa posição
            qns(new_row, new_colune, m, cont+1); // andou uma posição
            m.M[new_row][new_colune] = 0; // depois que ele sair da recusao, temos que setar a posição que ele estava como vazia novamente 
        }
    }
    if(cont > final){ // vamos pegar o maior caminho que o cavalo fez de todas as chamadas
        final = cont;
    }
}

int main(){
    int n, start;
    int sum = 0;
    int num_case = 1;
    while(cin >> n){
        matriz m(10, n);
        if(n == 0){
            break;
        }
        for(int c = 0; c < n; c++){ //c = row
            int x1, x2; //pares
            cin >> x1 >> x2;
            if(c == 0){
                start = x1;
            }
            for(int i = 0; i < x2; i++){
                m.M[c][i+x1] = 0;
                sum++; // sum é a quantidade de casas acessiveis
            }
        }
        m.M[0][start] = 1;
        qns(0, start, m, 1);
        if((sum - final) == 1){
            cout << "Case " << num_case << ", " << sum - final << " square can not be reached." << endl;
        }
        else{
            cout << "Case " << num_case << ", " << sum - final << " squares can not be reached." << endl;
        }
        num_case++;
        sum = 0;
        final = 0;
    }
}