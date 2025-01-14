#include <stdio.h>

int q5(int *x, int *y, int n);

int main(){
    int x[] = {1, 2, 3};
    int y[] = {1, 2, 3};
    printf("prod = %d\n", q5(x, y, 3));
    return 0;
}

int q5(int *x, int *y, int n){
    int s = 0;
    for(int i = 0; i < n; i++){
        s = s + x[i] * y[i];
    }
    return s;
}