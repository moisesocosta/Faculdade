#include <stdio.h>

int itemB(int n, int d){
    int cont = 0;

    if(n == 0 && d == 0)
        return 1;
    
    while(n != 0){
        if(n % 10 == d)
            cont++;
        n = n / 10;
    }
    return cont;
}

int itemC(int x, int y){
    for(int i = 0; i <= 9; i++){
        if(itemB(x, i) != itemC){
            return 0;
        }
    }

    return 1;
}

int main(){
    printf("%d \n", itemC(456, 5640));
    return 0;
}