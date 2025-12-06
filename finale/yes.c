#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    int id;
    char name[100];
    float grade;
};

int main() {
    char BUFFER[255];
    //assuming there is only two students
    struct Student currentStudent[2]; 
    int i = 0;

    FILE *ptr = fopen("practice.txt", "r");
    if (ptr == NULL) {
        printf("There was a problem when opening the file");
        return 1;
    }

    printf("--- Loading Data ---\n");


    while (fgets(BUFFER, 255, ptr) != NULL) {
        currentStudent[i].id = atoi(BUFFER);
        if (fgets(BUFFER, 255, ptr) != NULL) {
            BUFFER[strcspn(BUFFER, "\n")] = '\0';
            strcpy(currentStudent[i].name, BUFFER);
        }
        if (fgets(BUFFER, 255, ptr) != NULL) {
            // Convert string to float
            currentStudent[i].grade = atof(BUFFER);
        }
        printf("Student Found: [%d] %s (GPA: %.2f)\n",
               currentStudent[i].id,
               currentStudent[i].name,
               currentStudent[i].grade);
        i++;
    }
    fclose(ptr);
    return 0;
}
