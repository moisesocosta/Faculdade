#include <stdio.h>

int main(){
    int n, s = 0;
    printf("Digite n: ");
    scanf("%d", &n);

    for(int i = 1; i < n; i++){
        if(n % i == 0){
            printf("%d ", i);
            s = s + 1;
        }
    }

    if(s == n){
        printf("\neh perfeito");
    }else{
        printf("\nnao eh perfeito");
    }

    return 0;
}