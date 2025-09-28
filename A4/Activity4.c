#include <stdio.h>

int zigzagFlatten(int arr[][4], int *row, int *i, int leftToRight) {
    if (*row >= 3) return 0;  

    printf("%d ", arr[*row][*i]);

    if (leftToRight) {
        if (*i < 3) {
            (*i)++;
        } else {
            (*row)++;
            *i = 3;   
            leftToRight = 0;
        }
    } else {  
        if (*i > 0) {
            (*i)--;
        } else {
            (*row)++;
            *i = 0;   
            leftToRight = 1;
        }
    }

    return zigzagFlatten(arr, row, i, leftToRight);
}

int main() {
    int arr[][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int row = 0, i = 0;

    zigzagFlatten(arr, &row, &i, 1);  

    return 0;
}
