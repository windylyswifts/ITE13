#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char str[25], filler;
    int length, counter = 0; 

    printf("Enter String");
    fgets(str, 25, stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Enter what letter:");
    scanf("%c", &filler);
    filler = tolower(filler);

    length = strlen(str);

    for (int i = 0; i < length; i++){
        str[i] = tolower(str[i]);
        if (str[i] == filler)
            counter++;
    }
    
    printf("Result: %d's of %c", counter, filler);

    return 0;
}