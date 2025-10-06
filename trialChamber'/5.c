#include <stdio.h>

int main(){
    int age;

    printf("What is your age:");
    scanf("%d", &age);

    if (age <= 0)
        printf("Im not joking around please");
    else if (age <= 12)
        printf("You are currently a Child");
    else if (age <= 19)
        printf("You are currently a Teeneger");
    else if (age <= 39)
        printf("You are currently a Adult");
    else if (age <= 110)
        printf("You are currently a Senior Citizen");
    else
        printf("you are above 110 or maybe you are just joking around");
    return 0;
}