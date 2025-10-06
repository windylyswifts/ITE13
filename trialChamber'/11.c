#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline from fgets
    str[strcspn(str, "\n")] = '\0';

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[j] = str[i];  // Copy only non-space characters
            j++;
        }
    }
    str[j] = '\0';  // End the modified string

    printf("String without spaces: %s\n", str);

    return 0;
}
