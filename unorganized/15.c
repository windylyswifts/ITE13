#include <stdio.h>
//Write a function to swap two numbers using call by reference.

void numSwap(int number[]);
void numSwap(int number[]){
    int temp = 0;

    for (int i = 0; i < 1; i++){
        temp = number[i];
        number[i] = number[i+1];
        number[i+1] = temp;
    }
    
    for (int i = 0; i < 2; i++){
        printf("%d\n", number[i]);
    }
    

}

int main(){
    int number[2];

    for (int i = 0; i < 2; i++){
        printf("enter the number %d:", i+1);
        scanf("%d", &number[i]);
    }

    numSwap(number);
    

    return 0;
}