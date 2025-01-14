#include <stdio.h>

int main(){
    float s = 0;
    int n, m;
    printf("Digite n: ");
    scanf("%d", &n);
    m = n;

    for(int i = 1; i <= n; i++){
        printf("%d / %d ", i, m);
        s = s + (float)i / m;
        m--;
    }

    printf("\n%f", s);
    
    return 0;
}