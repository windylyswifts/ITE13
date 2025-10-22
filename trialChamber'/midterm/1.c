#include <stdio.h>

void number(int num);
void number(int num){
    if (num == 0)
        printf("Number is Zero!");
    else if (num > 0)
        printf("Number is positive");
    else
        printf("Number is Negative");
}


int main(){
    int num, result;

    printf("ENTER NUMBER:");
    scanf("%d", &num);

    number(num);    


    return 0;
}