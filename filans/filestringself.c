#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER 1024

void create_file(const char *filename){
    FILE *ptr = fopen(filename, "w");
    if (ptr == NULL){
        printf("THERE WAS A PROBLEM CREATING A FILE");
        return;
    }
    fprintf(ptr,"Hello World");
}


int main(){
    const char *input_text = "input.txt";
    const char *temp_filename = "temp.tmp";

    create_file(input_text);

    FILE *sourcefile;
    FILE *tempfile;

    char buffer[MAX_BUFFER];

    sourcefile = fopen(input_text, "r");
    tempfile = fopen(*temp_filename, "w");

    if (sourcefile == NULL || tempfile == NULL){
        printf("THere was a problem when checking the sources");
        return 1;
    }
    
    while (fgets(buffer, MAX_BUFFER, sourcefile) != NULL){
        /* code */
    }
    
    

    return 0;
}