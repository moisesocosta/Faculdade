#include <stdio.h>

int itemE(int x, int y){
    int aux;
    if(x > y){
        aux = x;
        x = y;
        y = aux;
    }

    while(y != 0){
        if(itemD(x, y) == 1){
            return 1;
        }
        y = y / 10;
    }

    return 0;
}

int main(){
    printf("%d \n", itemE(56, 5167));
    return 0;
}