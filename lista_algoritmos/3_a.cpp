#include<iostream>
#include<string.h> 
using namespace std;

typedef struct dictionary{
    int size; // size of the hash table
    int cnt; // numbers of elements in the dict
    string* array_principal; // array das entradas
}dictionary;

dictionary* create_dict(){
   dictionary* d = (dictionary*)malloc(sizeof(dictionary));
   d->size = 101;
   d->cnt = 0;
   d->array_principal = (string*)malloc(sizeof(string) * 101);
   for(int c = 0; c < 101; c++){
    d->array_principal[c] = ".";
   }
   return d;
}
int re_hash(int index_anterior, int c){
    int final = index_anterior + (c*c) + (c*23);
    final = final%101;
    return final;
}
int hash_function(string ch, int tamanho){
    int value = 0;
    int sum = 0;
    for(int c = 0; c < tamanho; c++){
        value = ch[c] * (c + 1);
        sum += value;
    }
    sum = 19 * sum;
    sum = sum % 101;
    return sum;
}

int find(dictionary* d, string ch){ // 1 - achou
    int key = hash_function(ch, ch.length());
    int pos = key;
    if(d->array_principal[pos] == "."){
        return 0;
    }
    else if(d->array_principal[pos] == ch){ // caso esteja na primeira possivel posição
        return 1;
    }else{
        for(int c = 1; c < 20; c++){
            pos = re_hash(pos, c);
            if(d->array_principal[pos] == ch){
                return 1;
            }
        }
    }
    return 0;
}

void insert(dictionary* d, string element){
    int tamanho = element.length();
    if(tamanho > 0){
        int resposta = 0;
        if((d->size > d->cnt) && (find(d, element) == 0)){
            int posicao, nova_posicao;
            posicao = hash_function(element, tamanho);
            if(d->array_principal[posicao] != "."){ // nao esta vazia
                int i = 1;
                nova_posicao = posicao;
                do{
                    if(i >= 20){
                        return;
                    }
                    nova_posicao = posicao + (i*i) + (23 * i);
                    nova_posicao = nova_posicao%101;
                    i++;
                    
                        
                }while(d->array_principal[nova_posicao] != ".");
                posicao = nova_posicao;
            }
            d->array_principal[posicao] = element;
            d->cnt++;  
        }
    }
    
}
void remover(dictionary* d, string element){
    for(int c = 0; c < d->size; c++){
        if(d->array_principal[c] == "."){
            continue;
        }else{
            if(( d->array_principal[c] == element) == 1){
                d->array_principal[c] = ".";
                d->cnt--;
            }
        }
    }
}

void print(dictionary* d){
    printf("%d\n", d->cnt);
    for(int c = 0; c < d->size; c++){
        if(d->array_principal[c] != "."){
            printf("%d:", c);
            cout << d->array_principal[c];
            printf("\n");
        }
    }
}


int main(){
    int blocos, num_comandos;
    cin >> blocos;
    for(int c = 0; c < blocos; c++){
        dictionary* dict = create_dict();
        cin >> num_comandos;
        for(int i = 0; i < num_comandos; i++){
            string frase, frase_aux;
            cin >> frase;
            frase_aux = frase.substr(4, frase.length());
            if(frase[0] == 'A'){
                insert(dict, frase_aux);
            }else{
                remover(dict, frase);
            }
        }
    print(dict);
    }
    
    return 0;
}