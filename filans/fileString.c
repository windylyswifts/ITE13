#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

// --- PART 1: STRING MANIPULATION HELPER ---
// Since C doesn't have a built-in "replace" function, we must build one.
// This function returns a NEW allocated string with the replacement applied.
char *replace_substring(const char *original, const char *target, const char *replacement) {
    char *result;
    int i, count = 0;
    int target_len = strlen(target);
    int replacement_len = strlen(replacement);

    // Step 1: Count how many times the target word appears
    // We need this to calculate how much memory to allocate for the new string.
    for (i = 0; original[i] != '\0'; i++) {
        if (strstr(&original[i], target) == &original[i]) {
            count++;
            i += target_len - 1;
        }
    }

    // Step 2: Allocate memory for the new string
    // New length = Old length + (number of replacements * size difference) + 1 for null terminator
    result = (char *)malloc(i + count * (replacement_len - target_len) + 1);

    if (result == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Step 3: Construct the new string
    i = 0;
    while (*original) {
        // If we find the target substring at the current position
        if (strstr(original, target) == original) {
            strcpy(&result[i], replacement); // Copy the replacement word here
            i += replacement_len;            // Move index forward by replacement length
            original += target_len;          // Skip the target word in the original string
        } else {
            result[i++] = *original++;       // Just copy the character
        }
    }
    result[i] = '\0'; // Null-terminate the string

    return result;
}

// --- PART 2: HELPER TO CREATE A DUMMY FILE ---
// This creates a file so you have something to read/edit immediately.
void create_sample_file(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Could not create sample file");
        exit(1);
    }
    fprintf(fp, "Hello World.\n");
    fprintf(fp, "The World is a large place.\n");
    fprintf(fp, "File handling in C is powerful.\n");
    fclose(fp);
    printf("--- Created 'input.txt' with sample text ---\n\n");
}

// --- PART 3: MAIN LOGIC ---
int main() {
    const char *INPUT_FILENAME = "input.txt";
    const char *TEMP_FILENAME = "temp.tmp";
    
    // 1. Create a file to test with
    create_sample_file(INPUT_FILENAME);

    FILE *sourceFile;
    FILE *tempFile;
    char buffer[MAX_BUFFER];

    printf("Attempting to replace 'World' with 'Universe'...\n");

    // 2. Open Source (Read) and Temp (Write)
    sourceFile = fopen(INPUT_FILENAME, "r");
    tempFile = fopen(TEMP_FILENAME, "w");

    if (sourceFile == NULL || tempFile == NULL) {
        perror("Error opening files");
        return 1;
    }


    // 3. Read Line-by-Line -> Manipulate -> Write
    while (fgets(buffer, MAX_BUFFER, sourceFile) != NULL) {
        // Manipulate: Call our custom function
        // We are replacing "World" with "Universe"
        char *modifiedLine = replace_substring(buffer, "World", "Universe");

        // Write: Put the modified string into the temp file
        fputs(modifiedLine, tempFile);

        // FREE MEMORY: replace_substring used 'malloc', so we must 'free'
        // to prevent memory leaks.
        free(modifiedLine); 
    }

    // 4. Close both files
    fclose(sourceFile);
    fclose(tempFile);

    // 5. Delete original and Rename temp
    // This makes the changes "permanent"
    if (remove(INPUT_FILENAME) == 0) {
        printf("Original file deleted successfully.\n");
    } else {
        perror("Error deleting original file");
    }

    if (rename(TEMP_FILENAME, INPUT_FILENAME) == 0) {
        printf("Temp file renamed to original filename.\n");
    } else {
        perror("Error renaming temp file");
    }

    printf("\n--- Operation Complete. Check 'input.txt' content. ---\n");

    return 0;
}