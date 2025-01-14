#include <stdio.h>
#include <math.h>

float media(int n, float *x);
float variancia(int n, float *x);

int main(){
    int n = 10;
    float med = 0, x[10], var = 0;

    printf("Qtd de num? ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Digite num %d: ", i + 1);
        scanf("%f", &x[i]);
    }

    printf("media = %f\n", media(n, x));
    printf("var = %f\n", variancia(n, x));
    printf("var = %f\n", sqrt(variancia(n, x)));

    return 0;
}

float media(int n, float *x){
    float med = 0;

    for(int i = 0; i < n; i++){
        med = med + x[i];
    }

    return med / n;
}

float variancia(int n, float *x){
    float var = 0, med = media(n, x);
    for(int i = 0; i < n; i++)
        var = var + (x[i] - med) * (x[i] - med);
    
    return var / n;
}