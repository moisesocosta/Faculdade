#include <stdio.h>

int main(){
    int x, y, s = 0, s1 = 0;
    printf("Digite x: ");
    scanf("%d", &x);

    printf("Digite y: ");
    scanf("%d", &y);

    for(int i = x; i <= y; i++){
        s1 = 0;
        for(int j = 1; j < i; j++){
            if(i % j == 0){
                s1 = s1 + j;
            }
        }
        if(i == s1){
            printf("%d ", i);
            s = s + i;
        }
    }

    printf("\n%d", s);

    return 0;
}