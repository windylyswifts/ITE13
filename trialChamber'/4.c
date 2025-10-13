#include <stdio.h>

// Function to find the second largest number in the array
int secFinder(int length, int arr[]) {
    int first, second;

    // Initialize with first two elements
    if (arr[0] > arr[1]) {
        first = arr[0];
        second = arr[1];
    } else {
        first = arr[1];
        second = arr[0];
    }

    // Loop through the rest of the array
    for (int i = 2; i < length; i++) {
        if (arr[i] > first) {
            // New largest found
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] < first) {
            // New second largest found
            second = arr[i];
        }
    }

    return second;
}

int main() {
    int arr[25], length, second;

    printf("Enter total elements in the list: ");
    scanf("%d", &length);

    // Input the array elements
    for (int i = 0; i < length; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    if (length < 2) {
        printf("Need at least 2 numbers to find the second largest.\n");
        return 0;
    }

    second = secFinder(length, arr);

    printf("Second largest: %d\n", second);

    return 0;
}
