#include <stdio.h>
//Write a program to find the length of a string using pointers.
int main(){
    char str[50];
    char *ptr;
    int length = 0;

    printf("Enter a String:");
    fgets(str, sizeof(str), stdin);
    
    ptr = str;

    printf("%p\n", str);
    printf("%p", ptr);

    // while (*ptr != '\0'){
    //     length++;
    //     ptr++;
    // }
    
    // if (str[length - 1] == '\n')
    //     length--;

    // printf("Length %d", length);


    return 0;
}