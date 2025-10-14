#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    char course[30];
    int year;
};

void addStudent(int *count, struct Student *account);
void displayStudents(int *count, struct Student *account);
void searchStudent(int *count, struct Student *account);

int main() {
    struct Student account[50];
    int checker, count = 0;

    do {
        printf("\n======Students======\n");
        printf("1. Add student\n");
        printf("2. Display student\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        scanf("%d", &checker);

        switch (checker) {
        case 1:
            if (count >= 50) {
                printf("ERROR, EXCEEDED 50 STUDENTS\n");
                continue;
            }
            addStudent(&count, account);
            break;
        case 2:
            displayStudents(&count, account);
            break;
        case 3:
            searchStudent(&count, account);
        default:
            break;
        }
    } while (checker != 4);

    return 0;
}

void addStudent(int *count, struct Student *account) {
    int addCount;
        printf("How many students you'd be adding? ");
        scanf("%d", &addCount);
    if (addCount > 50){
        printf("ERROR too much student");
        return;
    }
    

    for (int i = *count; i < *count + addCount; i++) {
        printf("Enter the %d student ID: ", i + 1);
        scanf("%d", &account[i].id); 
        //since next is a character input, it might read things that aren't supposed to be read
        getchar();
        printf("Student's name:");
        fgets(account[i].name, 50, stdin);
        account[i].name[strcspn(account[i].name, "\n")] = '\0';

        printf("Enter Student's Course:");
        fgets(account[i].course, 50, stdin);
        account[i].course[strcspn(account[i].course, "\n")] = '\0';

        printf("Student's Year Level:");
        scanf("%d", &account[i].year);

        printf("Student added Succesfully\n\n");
    }

    //this prepares for the next batch 
    *count += addCount;
}

void displayStudents(int *count, struct Student *account){
    if (*count == 0){
        printf("there is no student yet");
        return;
    }

    for (int i = 0; i < *count; i++){
        printf("Student number %d:\n", i+1);
        printf("Student ID: %d\n", account[i].id);
        printf("Name: %s\n", account[i].name);
        printf("Course: %s\n", account[i].course);
        printf("Year: %d\n", account[i].year);
    }
    
}

void searchStudent(int *count, struct Student *account){
    int temp = 0, found = 0;
    printf("Enter Student's ID:");
    scanf("%d", &temp);

    for (int i = 0; i < *count; i++){
        if (account[i].id == temp){
            printf("\nFound ID!\n");
            printf("Student number %d:\n", i+1);
            printf("Student ID: %d\n", account[i].id);
            printf("Name: %s\n", account[i].name);
            printf("Course: %s\n", account[i].course);
            printf("Year: %d\n", account[i].year);
            found++;
        }        
    }

    if (found == 0){
        printf("Couldn't find the ID!\n");
        printf("I suggest displaying all student to find it manually\n");
    }
}