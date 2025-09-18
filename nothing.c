#include <stdio.h>
#include <string.h>

int main(){
    char name[20];
    printf("Enter name:");
    scanf("%s", name);
    printf("Your name is %d", (int)strlen(name)); //declaring inside of print, add () when declaring on the spot
    
    

    return 0;
}

