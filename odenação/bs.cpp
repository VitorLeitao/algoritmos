#include <iostream>

using namespace std;

int BS(int* array, int inicio, int fim, int escolhido){
    if (fim >= inicio){
        int meio = (inicio + fim) / 2;
        if(array[meio] == escolhido){
            return meio;
        }else if(array[meio] > escolhido){
            BS(array, inicio, meio-1, escolhido);
        }else{
            BS(array, meio+1, fim, escolhido);
        }
    }else{
        return -1;
    }
}

int main()
{
    int vetor[5] = {5,6,7,8,9};
    int K = 7;
    int resposta = BS(vetor, 0, 4, K);
    cout << resposta;
    return 0;
}