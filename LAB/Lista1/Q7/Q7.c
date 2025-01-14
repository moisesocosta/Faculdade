#include <stdio.h>

int main(){
    float s = 0, aux = -1;
    int n;
    printf("Digite n: ");
    scanf("%d", &n);
    
    float soma = 0;
    int cont = 0;
    for(int i = 1; i <= n; i++){
        if(i == 1){
            soma = 1;
        }else if(i > 1 && cont == 0){
            soma = soma - (float)1 / i;
            cont++;
        }else if(i > 1 && cont == 1){
            soma = soma + (float)1 / i;
            cont--;
        }
    }

    printf("%f", soma);
    
    return 0;
}