#include <stdio.h>

int main(){
    float s = 0, aux = -1;
    int n;
    printf("Digite n: ");
    scanf("%d", &n);
    
    for(int i = 0; i <= n; i++){
        if(i % 2 == 0){
            printf("+ 4 / %d ", 2 * i + 1);
            s = s + 4.0 / (2 * i + 1);
        }else{
            printf("- 4 / %d ", 2 * i + 1);
            s = s - 4.0 / (2 * i + 1);
        }
    }

    printf("\n%f", s);
    
    return 0;
}