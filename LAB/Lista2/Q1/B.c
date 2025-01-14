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

int main(){
    int n, m;
    printf("Digite n: ");
    scanf("%d", &n);

    printf("Digite m: ");
    scanf("%d", &m);

    printf("fat = %d", comb(n, m));
    return 0;
}