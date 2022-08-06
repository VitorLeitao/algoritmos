#include <stdio.h>
#include <stdlib.h>


int main(){
    int var = 5;
    int* ponteiro1 = &var;
    int* ponteiro2 = ponteiro1;
    printf("%d\n", ponteiro2);
    printf("%d", *ponteiro2);
    return 0;
}






