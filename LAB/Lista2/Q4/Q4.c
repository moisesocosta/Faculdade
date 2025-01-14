#include <stdio.h>

int q4(int n){
    int aux = n, invertido = 0;

    if(0 <= n && n <= 9)
        return 1;

    while(aux > 0){
        invertido = (invertido * 10) + (aux % 10)
        aux = aux / 10;
    }
    
    if(n == invertido)
        return 1;
    else
        return 0;
}

int main(){
    printf("%d \n", q4(1232));
    return 0;
}