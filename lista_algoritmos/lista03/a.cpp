#include<iostream>
#include<string.h> 
using namespace std;

typedef struct dictionary{
    int size; // size of the hash table
    int cnt; // numbers of elements in the dict
    string array_principal[101]; // array das entradas
}dictionary;

dictionary* create_dict(){
   dictionary* d = (dictionary*)malloc(sizeof(dictionary));
   d->size = 101;
   d->cnt = 0;
   for(int c = 0; c < 101; c++){
        d->array_principal[c] = "NULL";
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
        value = ch.at(c) * (c + 1);
        sum += value;
    }
    sum = 19 * sum;
    sum = sum % 101;
    return sum;
}

int find(dictionary* d, string ch){ // 1 - achou
    int key = hash_function(ch, ch.length());
    int pos = key;
    
    for(int c = 0; c < 20; c++){
        if(d->array_principal[pos] == ch){
            return 1;
        }
        pos = re_hash(key, c);
        
    }
    
    return 0;
}

void insert(dictionary* d, string element){
    int key = hash_function(element, element.length());
    if((d->cnt < d->size) && (find(d, element) == 0)){
        int pos = key;
        if(d->array_principal[pos] != "NULL"){
            int i = 0;
            do{
                i++;
                if(i >= 20){
                    return;
                }
                pos = re_hash(key, i);
            }while(d->array_principal[pos] != "NULL");
            key = pos;
        }
        d->array_principal[key] = element;
        d->cnt++;
    }
}

void remover(dictionary* d, string element){
    for(int c = 0; c < d->size; c++){
        if(d->array_principal[c] == "NULL"){
            continue;
        }else{
            if(d->array_principal[c] == element){
                d->array_principal[c] = "NULL";
                d->cnt--;
            }
        }
    }
}

void print(dictionary* d){
    printf("%d\n", d->cnt);
    for(int c = 0; c < d->size; c++){
        if(d->array_principal[c] != "NULL"){
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
            if(frase.length() <= 4){
                continue;
            }
            frase_aux = frase.substr(4, frase.length());
            if(frase[0] == 'A'){
                insert(dict, frase_aux);
            }else{
                remover(dict, frase_aux);
            }
        }
    print(dict);
    }
    
    return 0;
}