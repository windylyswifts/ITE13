#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};  
    int sum = 0;
    int *ptr = arr; // pointer to the first element of the array
    int length = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < length; i++) {
        sum += *(ptr + i); // access array elements using pointer arithmetic
    }

    printf("The sum of all elements = %d\n", sum);
    return 0;
}
