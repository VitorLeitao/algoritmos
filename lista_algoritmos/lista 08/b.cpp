#include <iostream>
#include <cmath>
using namespace std;

int h[100010];
int dp[100010];
int main(){
    int num, inicial;
    cin >> num >> inicial;
    for(int c = 1; c <= num; c++){
        cin >> h[c];
    }
    int aux;
    for(int c = 2; c <= num; c++){
        int valor_minimo = 1<<30;
        for(int i = 1; i<=inicial&&c - i>=1; i++){
            aux = h[c] - h[c-i];
            if(aux < 0){
                aux = aux * -1;
            }
            valor_minimo = min(valor_minimo, dp[c-i] - aux );
        }
        dp[c] = valor_minimo;
    }
    cout << dp[num];
    return 0;
}