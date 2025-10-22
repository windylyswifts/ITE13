#include <stdio.h>
#include <string.h>
//Write a program to count the number of words in a string.
int main(){
    char str[50];
    int counter = 0;

    printf("Enter your String:");
    fgets(str, 50, stdin);
    str[strcspn(str, "\n")] = '\0';

    char *token = strtok(str, " ");
    while (token){
        counter++;
        token = strtok(NULL, " ");
    }

    printf("Total words:%d", counter);
    

    return 0;
}