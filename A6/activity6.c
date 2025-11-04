#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//to minimize variables
int counter = 0; 

struct Student {
    int id;
    char name[50];
    char course[30];
    int year;
};

void addStudent(int *count, struct Student *account);
void displayStudents(int *count, struct Student *account);
void searchStudent(int *count, struct Student *account);
void menu(int *count, struct Student **account);

int main() {
    int studentCount;

    printf("Enter how many students you'd be adding?: ");
    scanf("%d", &studentCount);

    struct Student *account = malloc(studentCount * sizeof(struct Student));
    if (account == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    addStudent(&studentCount, account);
    menu(&studentCount, &account);

    free(account);  
    return 0;
}

void menu(int *count, struct Student **account) {
    int checker = 0, temp = 0;

    do {
        printf("\n======Students======\n");
        printf("1. Add student\n");
        printf("2. Display student\n");
        printf("3. Search student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &checker);

        switch (checker) {
            case 1:
                printf("How many students you'd be adding more?: ");
                scanf("%d", &temp);

                struct Student *newPtr = realloc(*account, (*count + temp) * sizeof(struct Student));
                if (newPtr == NULL) {
                    printf("Memory reallocation failed.\n");
                    break;
                }
                *account = newPtr;

                counter = *count;       // start adding from where we left off
                *count += temp;         // update total number
                addStudent(count, *account);
                break;

            case 2:
                displayStudents(count, *account);
                break;

            case 3:
                searchStudent(count, *account);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid option. Try again.\n");
        }

    } while (checker != 4);
}

void addStudent(int *count, struct Student *account) {
    for (int i = counter; i < *count; i++) {
        printf("Enter the %d student ID: ", i + 1);
        scanf("%d", &account[i].id);
        getchar(); // clear leftover newline

        printf("Student's name: ");
        fgets(account[i].name, 50, stdin);
        account[i].name[strcspn(account[i].name, "\n")] = '\0';

        printf("Enter Student's Course: ");
        fgets(account[i].course, 30, stdin);
        account[i].course[strcspn(account[i].course, "\n")] = '\0';

        printf("Student's Year Level: ");
        scanf("%d", &account[i].year);
        getchar(); 

        printf("Student added successfully!\n\n");
    }
}

void displayStudents(int *count, struct Student *account) {
    if (*count == 0) {
        printf("There are no students yet.\n");
        return;
    }

    for (int i = 0; i < *count; i++) {
        printf("\nStudent number %d:\n", i + 1);
        printf("Student ID: %d\n", account[i].id);
        printf("Name: %s\n", account[i].name);
        printf("Course: %s\n", account[i].course);
        printf("Year: %d\n", account[i].year);
    }
}

void searchStudent(int *count, struct Student *account) {
    int temp = 0, found = 0;

    printf("Enter Student's ID: ");
    scanf("%d", &temp);

    for (int i = 0; i < *count; i++) {
        if (account[i].id == temp) {
            printf("\nFound ID!\n");
            printf("Student number %d:\n", i + 1);
            printf("Student ID: %d\n", account[i].id);
            printf("Name: %s\n", account[i].name);
            printf("Course: %s\n", account[i].course);
            printf("Year: %d\n", account[i].year);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Couldn't find the ID!\n");
        printf("Try displaying all students to find it manually.\n");
    }
}
