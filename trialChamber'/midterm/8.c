#include <stdio.h>
// Write a program to demonstrate pointer arithmetic by printing addresses and values of
// an array.
int main() {
    int arr[] = {10, 20, 30, 40, 50};   // Example array
    int n = sizeof(arr) / sizeof(arr[0]); // Number of elements
    int *ptr = arr;   // Pointer pointing to the first element of array

    printf("Array elements using pointer arithmetic:\n\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: Value = %d, Address = %p\n", i, *(ptr + i), (ptr + i));
    }

    return 0;
}
