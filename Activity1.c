#include <stdio.h>

int main(){
    int rows, increseNum, sumRow=0, sumCounter=0,i=1, twiceCounter=0, primeCounter=0, check;
    int roundedRows;

    printf("How many rows you want for this pryamid?");
    scanf("%d", &rows);

    for (int i = 1; i <= rows ; i++){
        increseNum = i;
        for (int j  = 1; j <= i; j++){
            if (i == 1){
                printf("%d", i);
                break;
            }
            printf("%d ", increseNum);
            sumRow += increseNum;
            increseNum += i;
        }
        if (sumRow % i != 0 && i != 1){
            printf(" Sum = %d", sumRow);
            sumCounter++;
        }
        sumRow = 0;//resetting
        printf("\n");
    }
    
        printf("\n========PART2========\n");

        while (i != 51){
        if (i % 10 == 3 || i / 10 == 3){
            i++;
        }
        else if(i == 1){
            printf("%d ", i);
            i++;
        }
        else if(i % 7 == 0){
            printf(" %d ", i);
            printf(" %d ", i);
            i++;
            twiceCounter++;
        }
        //seperated 2 because its a prime  itself but i also use this number to based on other number
        else if (i == 2 || i == 5){
            printf(" %d ", i+10);
            i++;
            primeCounter++;
        }
        else if((i % 2 != 0 && i % 3 != 0 && i % 5 != 0)){
            printf(" %d ", i+10);
            i++;
            primeCounter++;
        }
        else{
            printf(" %d ", i);
            i++;
        }
    }

    printf("\n=======PART 3=======\n");

    printf("RULE A. TOTAL AMOUNT OF SUMS:%d", sumCounter);
    printf("\nRULE B. TOTAL NUMBERS PRINTED TWICE:%d", twiceCounter);
    printf("\nRULE C. TOTAL OF PRIME NUMBERS ADDED BY 10:%d", primeCounter);


    //its (row + 1) / 2 because we need to round it up
    if (sumCounter == (rows + 1)/2 && twiceCounter == 7 && primeCounter == 15)
        check++;
    if (check == 1)
        printf("\nVALID");
    else
        printf("\nINVALID");

    return 0;
}
