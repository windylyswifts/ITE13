#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkVow(char str[], int length);
int checkVow(char str[], int length){
    int counter = 0;
    for (int i = 0; i < length; i++){
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            counter++;
    }
    return counter;
}

int main(){
    char str[25];
    int length, result;
    printf("Enter your string");
    fgets(str, 25, stdin);
    str[strcspn(str, "\n")] = '\0';
    length = strlen(str);

    for (int i = 0; i < length; i++){
        str[i] = tolower(str[i]);
    }
    

    result = checkVow(str, length);
    printf("here is the result: you have a total of %d", result);
    
    return 0;
}