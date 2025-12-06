#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store a single student's data
typedef struct {
    char *fullname;  // pointer to dynamically allocated string for name
    int score;       // student's score
} Record;

// Struct to store the database
typedef struct {
    Record *data;    // pointer to an array of Records
    int total;       // sum of all scores
    float average;   // average score
    int count;       // number of students
} Database;

// Function prototypes
void enterRecords(Database *db);
void displayRecords();
void computeAverage();
void deleteOneRecord();
void clearInput();

int main() {
    int choice;
    Database db = {NULL, 0, 0.0, 0}; // initialize database

    // Main menu loop
    do {
        printf("\n===== STUDENT RECORD SYSTEM =====\n");
        printf("1. Enter Student Records\n");
        printf("2. Display Records (from file)\n");
        printf("3. Compute Class Average\n");
        printf("4. Delete One Student Record\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);  // read user choice
        clearInput();           // clear leftover newline

        switch (choice) {
            case 1: enterRecords(&db); break; // input new records
            case 2: displayRecords(); break;  // show all records
            case 3: computeAverage(); break;  // calculate average
            case 4: deleteOneRecord(); break; // delete a student by name
            case 5: printf("Exiting program...\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 5); // repeat until user chooses exit

    // Free all dynamically allocated memory for student names
    if (db.data != NULL) {
        for (int i = 0; i < db.count; i++) {
            free(db.data[i].fullname);
        }
        free(db.data); // free the array of Records
    }

    return 0;
}

// ---------------------------------------------
// Function to enter student records
// ---------------------------------------------
void enterRecords(Database *db) {
    printf("Enter number of students: ");
    scanf("%d", &db.count); // number of students
    clearInput();             // remove leftover newline

    // Allocate memory for all student records
    db.data = (Record *)malloc(sizeof(Record) * db.count);

    // Open file to store grades
    FILE *file = fopen("grades.txt", "w");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < db->count; i++) {
        // Allocate memory for the student's name
        db->data[i].fullname = (char *)malloc(50);

        printf("Enter name of student %d: ", i + 1);
        fgets(db->data[i].fullname, 50, stdin); // read name including spaces
        db->data[i].fullname[strcspn(db->data[i].fullname, "\n")] = '\0'; // remove newline

        printf("Enter %s's score: ", db->data[i].fullname);
        scanf("%d", &db->data[i].score); // read score
        clearInput();

        // Write the record to the file
        fprintf(file, "%s %d\n", db->data[i].fullname, db->data[i].score);
    }

    fclose(file); // close file
    printf("Records saved successfully.\n");
}

// ---------------------------------------------
// Function to display all records from file
// ---------------------------------------------
void displayRecords() {
    FILE *file = fopen("grades.txt", "r"); // open file for reading
    char name[50];
    int score;

    if (!file) {
        printf("No file found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (fscanf(file, "%s %d", name, &score) != EOF) {
        printf("Name: %s, Score: %d\n", name, score);
    }

    fclose(file);
}

// ---------------------------------------------
// Function to compute class average
// ---------------------------------------------
void computeAverage() {
    FILE *file = fopen("grades.txt", "r"); // open file for reading
    char name[50];
    int score, total = 0, count = 0;

    if (!file) {
        printf("No file found.\n");
        return;
    }

    // Read each record and accumulate scores
    while (fscanf(file, "%s %d", name, &score) != EOF) {
        total += score;
        count++;
    }

    fclose(file);

    if (count > 0) {
        printf("Class Average: %.2f\n", (float)total / count);
    } else {
        printf("No records found.\n");
    }
}

// ---------------------------------------------
// Function to delete one record by name
// ---------------------------------------------
void deleteOneRecord() {
    char nameToDelete[50], name[50];
    int score, found = 0;

    FILE *file = fopen("grades.txt", "r"); // open original file
    FILE *temp = fopen("temp.txt", "w");   // temporary file to store remaining records

    if (!file) {
        printf("No records found.\n");
        if (temp) fclose(temp);
        return;
    }

    printf("Enter the name of the student to delete: ");
    fgets(nameToDelete, 50, stdin);
    nameToDelete[strcspn(nameToDelete, "\n")] = '\0'; // remove newline

    // Read each record from original file
    while (fscanf(file, "%s %d", name, &score) != EOF) {
        // Copy all records except the one to delete
        if (strcmp(name, nameToDelete) != 0) {
            fprintf(temp, "%s %d\n", name, score);
        } else {
            found = 1; // mark that record was found
        }
    }

    fclose(file);
    fclose(temp);

    // Replace original file with the updated file
    remove("grades.txt");
    rename("temp.txt", "grades.txt");

    if (found)
        printf("Record '%s' deleted successfully.\n", nameToDelete);
    else
        printf("Record not found.\n");
}

// ---------------------------------------------
// Function to clear leftover input from buffer
// ---------------------------------------------
void clearInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}