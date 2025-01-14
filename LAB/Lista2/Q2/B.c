#include <stdio.h>

int f_rec(int n){
    if(n <= 1)
        return n;
    return f_rec(n - 1) + f_rec(n - 2);
}

int f(int n){
    if(n <= 1)
        return n;
    
    int a = 0, b = 1;
    for(int i = 2; i <= n; i++){
        b = b + a;
        a = b - a;
    }
}

int main(){
    printf("%d", f_(7));
    return 0;
}