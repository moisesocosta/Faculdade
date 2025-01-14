#include <stdio.h>

int main(){
    int n, s = 0;
    printf("Digite n: ");
    scanf("%d", &n);

    for(int i = 2; i < n; i++){
        if(n % i == 0){
            printf("%d ", i);
            s = s + 1;
        }
    }

    if(s == 0){
        printf("\neh primo");
    }else{
        printf("\nnao eh primo");
    }

    return 0;
}