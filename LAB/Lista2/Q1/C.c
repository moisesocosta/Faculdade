#include <stdio.h>

int fat(int n){
    if(n == 0)
        return 1;

    int p = 1;
    for(int i = 1; i <= n; i++){
        p = p * i;
    }
    return p;
}

int comb(int n, int m){
    return fat(n) / (fat(m) * fat(n-m));
}

void pascal(int k){
    for(int j = 0; j <= k; j++){
        for(int i = 0; i <= j; i--){
            printf("%d ", comb(j, i));
        }
        printf("\n");
    }
}

int main(){
    pascal(20);
    return 0;
}