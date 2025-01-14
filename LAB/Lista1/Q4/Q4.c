#include <stdio.h>

int main(){
    int n, cont = 0, a, b, s = 0;
    printf("Digite n: ");
    scanf("%d", &n);

    for(int i = 1; cont < n; i++){
        a = i;
        b = i + 2;
        s = 0;
        for(int j = 2; j < a; j++){
            if(a % j == 0){
                s = s + j;
            }
        }
        if(s == 0){
            for(int j = 2; j < b; j++){
                if(b % j == 0){
                    s = s + j;
                }
            }
            if(s == 0){
                printf("%d %d\n", a, b);
                cont++;
            }else{
                s = 0;
            }
        }
    }

    return 0;
}