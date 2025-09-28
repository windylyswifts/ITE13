#include <stdio.h>
#include <string.h>

// strlen(str) → Returns the length of a string (excluding \0).
// strcpy(dest, src) → Copies src into dest.
// strncpy(dest, src, n) → Copies first n chars of src into dest.
// strcat(dest, src) → Appends src to the end of dest.
// strncat(dest, src, n) → Appends first n chars of src to dest.
// strcmp(str1, str2) → Compares two strings (0 if equal).
// strncmp(str1, str2, n) → Compares first n chars of two strings.
// strchr(str, ch) → Finds first occurrence of character ch in string.
// strrchr(str, ch) → Finds last occurrence of character ch in string.
// strstr(str, substr) → Finds first occurrence of substring in string.
// strtok(str, delim) → Splits string into tokens using delimiter.
// memset(str, ch, n) → Sets first n bytes of memory block to ch.
// memcpy(dest, src, n) → Copies n bytes from src to dest.
// memmove(dest, src, n) → Similar to memcpy but safer for overlap.
// memcmp(str1, str2, n) → Compares first n bytes of two strings.

int main() {
    char str1[50] = "Hello";
    char str2[50] = "World";
    char str3[50];
    char str4[50] = "Hello World!";
    char buffer[50];

    // 1. strlen
    printf("Length of str1: %zu\n", strlen(str1));

    // 2. strcpy
    strcpy(str3, str1); // str3 = "Hello"
    printf("str3 after strcpy: %s\n", str3);

    // 3. strncpy
    strncpy(str3, str2, 3); // Copy first 3 chars of str2 ("Wor")
    str3[3] = '\0'; // Add null terminator
    printf("str3 after strncpy: %s\n", str3);

    // 4. strcat
    strcat(str1, str2); // str1 = "HelloWorld"
    printf("str1 after strcat: %s\n", str1);

    // 5. strncat
    strncat(str1, "12345", 3); // Append first 3 chars ("123")
    printf("str1 after strncat: %s\n", str1);

    // 6. strcmp
    printf("strcmp(str1, str2): %d\n", strcmp(str1, str2));

    // 7. strncmp
    printf("strncmp(str1, str2, 3): %d\n", strncmp(str1, str2, 3));

    // 8. strchr
    printf("First 'o' in str4: %s\n", strchr(str4, 'o'));

    // 9. strrchr
    printf("Last 'o' in str4: %s\n", strrchr(str4, 'o'));

    // 10. strstr
    printf("Substring 'World' in str4: %s\n", strstr(str4, "World"));

    // 11. strtok
    char str5[] = "apple,banana,orange";
    char *token = strtok(str5, ",");

    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, ",");
    }

    // 12. memset
    memset(buffer, '*', 10); // fill first 10 chars with '*'
    buffer[10] = '\0';
    printf("Buffer after memset: %s\n", buffer);

    // 13. memcpy
    memcpy(buffer, str4, strlen(str4) + 1); // copy str4 into buffer
    printf("Buffer after memcpy: %s\n", buffer);

    // 14. memmove
    memmove(buffer + 6, buffer, 5); // overlap copy
    buffer[11] = '\0';
    printf("Buffer after memmove: %s\n", buffer);

    // 15. memcmp
    printf("memcmp(str1, str2, 5): %d\n", memcmp(str1, str2, 5));

    return 0;
}
