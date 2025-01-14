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

int main(){
    printf("%d \n", itemB(0, 0));
    return 0;
}