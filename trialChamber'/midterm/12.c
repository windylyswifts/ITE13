#include <stdio.h>
#include <string.h>
// Write a program to convert all characters in a string to uppercase without using library
// functions.
int main(){
    char str[50];
    int length;


    printf("Enter the string:");
    fgets(str, 50, stdin);

    str[strcspn(str, "\n")] = '\0';

    length = strlen(str);
    
    for (int i = 0; i < length; i++){
        //in ASCII lowercase letters has more value
        if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
        
    }
    
    

    return 0;
}