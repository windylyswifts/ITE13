#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for strdup (POSIX)

int main() {
    char str1[50] = "Hello";
    char str2[50] = "World";
    char buffer[100];

    // ---------------- Copying ----------------
    printf("1. strcpy: %s\n", strcpy(buffer, str1));              // Copy str1 to buffer
    printf("2. strncpy: %s\n", strncpy(buffer, str2, 3));         // Copy first 3 chars of str2

    // ---------------- Concatenation ----------------
    strcpy(buffer, str1);                                         // Reset buffer
    printf("3. strcat: %s\n", strcat(buffer, str2));              // Append str2 to buffer
    strcpy(buffer, str1);                                         // Reset buffer
    printf("4. strncat: %s\n", strncat(buffer, str2, 3));         // Append first 3 chars of str2

    // ---------------- Comparison ----------------
    printf("5. strcmp: %d\n", strcmp("abc", "abc"));              // Compare equal strings
    printf("6. strncmp: %d\n", strncmp("abc", "abd", 2));         // Compare first 2 chars
    // POSIX only:
    // printf("7. strcasecmp: %d\n", strcasecmp("Hello", "hello")); // Case-insensitive
    // printf("8. strncasecmp: %d\n", strncasecmp("Hello", "HelX", 3)); // Case-insensitive first 3

    // ---------------- Length ----------------
    printf("9. strlen: %zu\n", strlen(str1));                     // Length of string

    // ---------------- Search ----------------
    printf("10. strchr: %s\n", strchr(str1, 'e'));                // Find 'e' in str1
    printf("11. strrchr: %s\n", strrchr("Hello Hello", 'o'));     // Last 'o'
    printf("12. strstr: %s\n", strstr("Hello World", "World"));   // Find substring
    char text[50] = "apple,banana,grape";
    char *token = strtok(text, ",");                              // Tokenize
    printf("13. strtok:\n");
    while(token) {
        printf("   %s\n", token);
        token = strtok(NULL, ",");
    }
    printf("14. strpbrk: %s\n", strpbrk("abcdef", "xzde"));       // First matching char
    printf("15. strspn: %zu\n", strspn("abcde123", "abcde"));     // Initial chars in set
    printf("16. strcspn: %zu\n", strcspn("abc123", "123"));       // Initial non-matching length

    // ---------------- Memory ----------------
    char mem1[10] = "abcdef";
    char mem2[10];
    memcpy(mem2, mem1, 6);                                        // Copy 6 bytes
    printf("17. memcpy: %s\n", mem2);
    memmove(mem2+2, mem2, 4);                                     // Safe overlapping copy
    printf("18. memmove: %s\n", mem2);
    memset(mem2, '*', 5);                                         // Fill with '*'
    mem2[5] = '\0';
    printf("19. memset: %s\n", mem2);
    printf("20. memcmp: %d\n", memcmp("abc", "abd", 3));          // Compare 3 bytes
    printf("21. memchr: %s\n", (char*)memchr("abcdef", 'd', 6));  // Find char in memory

    // ---------------- Miscellaneous ----------------
    char *copy = strdup(str1);                                    // Duplicate string
    printf("22. strdup: %s\n", copy);
    free(copy);

    return 0;
}
