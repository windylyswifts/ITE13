#include <stdio.h>
#include <stdlib.h>   // for malloc and free

float averageArr(int *arr, int *size) {
    int sum = 0;
    for (int i = 0; i < *size; i++) {
        sum += *(arr + i);  // pointer arithmetic
    }
    return (float)sum / (*size);   // cast to float for decimal average
}

int main() {
    int size;
    int *arr;   // pointer for dynamic array

    printf("Enter how many numbers: ");
    scanf("%d", &size);

    // allocate memory dynamically
    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  // exit program
    }

    for (int i = 0; i < size; i++) {
        printf("Enter %d Number: ", i + 1);
        scanf("%d", &arr[i]);  // same as *(arr+i)
    }

    float result = averageArr(arr, &size);
    printf("The average is: %.2f\n", result);

    free(arr);  // release allocated memory
    return 0;
}
