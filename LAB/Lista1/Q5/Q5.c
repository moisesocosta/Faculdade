#include <stdio.h>

int main(){
    float s = 0;
    int n;
    printf("Digite n: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        printf("1/%d ", i);
        s = s + (float)1 / i;
    }

    printf("\n%f", s);

    return 0;
}