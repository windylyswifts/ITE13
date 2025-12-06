#include <stdio.h>

int main()
{
    FILE *fptr;
    //char line[100];
    fptr = fopen("sample.txt", "a");
    if(fptr == NULL){
        printf("File not found!\n");
        return 1;
    }
    // while(fgets(line, sizeof(line), fptr)){
    //     printf("%s", line);
    // }
    fprintf(fptr, "\nAppended text: Learning C is fun!\n ");
    fclose(fptr);
    printf("New text appendede successfully");
    return 0;
}