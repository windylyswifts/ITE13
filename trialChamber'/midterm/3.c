#include <stdio.h>

int main(){
    int num[3], result;

    for (int i = 0; i < 3; i++){
        printf("%d number:", i+1);
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < 3; i++){
        if (num[i] >= num[0] && num[i] >= num[1] && num[i] >= num[2]){
            result = num[i];
        }
    }

    printf("%d is the greatest among the 3 number", result);
    
    
    


    

    return 0;
}