#include <stdio.h>

int main(){
    int n, m;
    printf("Digite n: ");
    scanf("%d", &n);

    printf("Digite m: ");
    scanf("%d", &m);

    if(m % n == 0){
        print("%d eh divisor de %d", n, m);
    }else{
        printf("%d nao eh divisor de %d", n, m);
    }

    return 0;
}