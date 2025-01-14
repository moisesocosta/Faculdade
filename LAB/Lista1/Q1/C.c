#include <stdio.h>

int main(){
    int n, s = 0;
    printf("Digite n: ");
    scanf("%d", &n);

    for(int i = 0; i < 2 * n; i++){
        if(i % 2 == 1){
            printf("%d ", i);
            s = s + i;
        }
    }

    printf("\n%d", s);

    return 0;
}