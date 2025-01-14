#include <stdio.h>

int itemD(int x, int y){
    if(x > y){
        return 0;
    }

    while(x != 0){
        if(x % 10 != y % 10)
            return 0;
        x = x / 10;
        y = y / 10;
    }
    return 1;
}

int main(){
    printf("%d \n", itemD(0, 121));
    return 0;
}