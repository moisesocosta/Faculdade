#include <stdio.h>

int itemA(int n){
    int cont = 0;

    if(n == 0){
        return 1;
    }

    while(n != 0){
        n = n / 10;
        cont = cont + 1;
    }
    return cont;
}

int main(){
    printf("%d \n", itemA(9));
    return 0;
}