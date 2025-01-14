#include <stdio.h>

int main(){
    int x, y, s = 0;
    printf("Digite x: ");
    scanf("%d", &x);

    printf("Digite y: ");
    scanf("%d", &y);

    for(int i = x; i <= y; i++){
        if(i%2 == 0){
            printf("%d ", i);
            s = s + i;
        }
    }

    printf("\n%d", s);

    return 0;
}