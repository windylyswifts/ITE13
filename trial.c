#include <stdio.h>
#include <string.h>

void reverseString(char str[], int length);
void reverseString(char str[], int length){
    char temp[50];
    int counter = 0;
    //length - 1 because length reads \0
    for (int i = length - 1; i >= 0; i--){
        temp[counter] = str[i];
        counter++;
    }
    
    temp[counter] = '\0';
    strcpy(str, temp);

}

int main(){
    char str[50];
    int length;
    
    printf("Enter the string:");
    fgets(str, 50, stdin);

    str[strcspn(str, "\n")] = '\0';
    
    length = strlen(str);

    reverseString(str, length);

    printf("%s", str);

    return 0;
}