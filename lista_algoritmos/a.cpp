#include <iostream>
#include <math.h>
using namespace std;

int main(){
    double altura, largura, lado;
    cin >> altura;
    cin >> largura;
    cin >> lado;

    double numero_altura, numero_largura, total;
    numero_altura = ceill(altura / lado);
    numero_largura = ceill(largura / lado);
    total = numero_altura * numero_largura;

    printf("%.0f", total);
}