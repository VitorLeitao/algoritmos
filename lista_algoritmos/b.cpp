#include <iostream>
using namespace std;

int main(){
    int var; 
    cin >> var;
    if(var == 2){
        cout << "NO";
    }
    else if(var % 2 == 0){
        cout << "YES";
    }else{
        cout << "NO";
    }
}