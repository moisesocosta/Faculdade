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

int main(){
    int n;
    printf("Digite n: ");
    scanf("%d", &n);

    printf("fat = %d", fat(n));
    return 0;
}