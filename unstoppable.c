#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 50

struct Student {
    int id;
    char name[50];
    char course[30];
    int year;
};

/* Helper: remove trailing newline from fgets */
void trim_newline(char *s) {
    size_t len = strlen(s);
    if (len > 0 && s[len-1] == '\n') s[len-1] = '\0';
}

/* Print single student in table row */
void print_student_row(const struct Student *s) {
    printf("%-10d  %-22s  %-10s  %2d\n", s->id, s->name, s->course, s->year);
}

/* Search for student by ID, return index or -1 if not found */
int find_student_by_id(struct Student list[], int count, int id) {
    for (int i = 0; i < count; ++i) {
        if (list[i].id == id) return i;
    }
    return -1;
}

int main(void) {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("[1] Add Student\n");
        printf("[2] Display All Students\n");
        printf("[3] Search Student\n");
        printf("[4] Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            /* non-number input: clear and continue */
            int c;
            while ((c = getchar()) != '\n' && c != EOF) ;
            printf("Invalid choice. Try again.\n");
            continue;
        }

        /* consume leftover newline so fgets works */
        int ch = getchar();
        (void)ch;

        if (choice == 1) {
            if (count >= MAX_STUDENTS) {
                printf("Cannot add more students. Storage is full (%d students).\n", MAX_STUDENTS);
                continue;
            }

            struct Student s;
            printf("\nEnter Student ID: ");
            if (scanf("%d", &s.id) != 1) {
                while ((ch = getchar()) != '\n' && ch != EOF) ;
                printf("Invalid ID. Aborting add.\n");
                continue;
            }
            /* clear newline after scanf */
            while ((ch = getchar()) != '\n' && ch != EOF) ;

            /* check duplicate ID */
            if (find_student_by_id(students, count, s.id) != -1) {
                printf("A student with ID %d already exists. Add canceled.\n", s.id);
                continue;
            }

            printf("Enter Name: ");
            if (fgets(s.name, sizeof s.name, stdin) == NULL) {
                printf("Input error. Aborting add.\n");
                continue;
            }
            trim_newline(s.name);

            printf("Enter Course: ");
            if (fgets(s.course, sizeof s.course, stdin) == NULL) {
                printf("Input error. Aborting add.\n");
                continue;
            }
            trim_newline(s.course);

            printf("Enter Year Level: ");
            if (scanf("%d", &s.year) != 1) {
                while ((ch = getchar()) != '\n' && ch != EOF) ;
                printf("Invalid year. Aborting add.\n");
                continue;
            }
            while ((ch = getchar()) != '\n' && ch != EOF) ;

            /* store */
            students[count++] = s;
            printf("Student added successfully!\n");
        }
        else if (choice == 2) {
            if (count == 0) {
                printf("\nNo student records to display.\n");
                continue;
            }
            printf("\n%-10s  %-22s  %-10s  %s\n", "ID", "Name", "Course", "Year");
            printf("--------------------------------------------------------------\n");
            for (int i = 0; i < count; ++i) {
                print_student_row(&students[i]);
            }
        }
        else if (choice == 3) {
            int idsearch;
            printf("\nEnter ID to search: ");
            if (scanf("%d", &idsearch) != 1) {
                while ((ch = getchar()) != '\n' && ch != EOF) ;
                printf("Invalid ID.\n");
                continue;
            }
            while ((ch = getchar()) != '\n' && ch != EOF) ;

            int idx = find_student_by_id(students, count, idsearch);
            if (idx == -1) {
                printf("Student with ID %d not found.\n", idsearch);
            } else {
                printf("\nRecord found:\n");
                printf("%-10s  %-22s  %-10s  %s\n", "ID", "Name", "Course", "Year");
                printf("--------------------------------------------------------------\n");
                print_student_row(&students[idx]);
            }
        }
        else if (choice == 4) {
            printf("Exiting program. Goodbye.\n");
            break;
        }
        else {
            printf("Invalid choice. Please enter a number from 1 to 4.\n");
        }
    }

    return 0;
}