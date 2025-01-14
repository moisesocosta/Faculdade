#include <stdio.h>

void q4(int *v, int n);

int main(){
    int v[] = {5, 7, 3, 1, 10, 0};
    q4(v, 6);
    return 0;
}

void q4(int *v, int n){
    int max = v[0], min = v[0];

    for(int i = 0; i < n; i++){
        if(v[i] > max)
            max = v[i];
        if(v[i] < min)
            min = v[i];
    }
    printf("max = %d\n", max);
    printf("min = %d", min);
}