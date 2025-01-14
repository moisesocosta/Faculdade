#include <stdio.h>

int f_rec(int n){
    if(n <= 1)
        return n;
    return f_rec(n - 1) + f_rec(n - 2);
}

int main(){
    printf("%d", f_rec(6));
    return 0;
}