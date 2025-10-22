#include <stdio.h>

void arrAsc(int arr[], int length);
void arrAsc(int arr[], int length){
    int temp[50];
    
    for (int i = 0; i < length; i++){
        for (int j = 0; j < j - 1; j++){
             
        }
    }
}

int main(){
    int arr[50], length;

    printf("Enter how many numbers you'll input:");
    scanf("%d", &length);

    for (int i = 0; i < length; i++){
        printf("Enter the %d Number", i+1);
        scanf("%d", &arr[i]);
    }

    arrAsc(arr, length);
    
    return 0;
}