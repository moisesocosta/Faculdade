#include <stdio.h>

int q5(int n){
    int s = 0, x = 1;

    if(n == 0)
        return 0;

    while(n != 0){
        s = s + (n % 10) * x;
        n = n / 10;
        x = x * 2;
    }
    return s;
}

int main(){
    printf("%d \n", q5(1));
    return 0;
}