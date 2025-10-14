#include <stdio.h>
#include <string.h>

void addStudent(int *count, int account[][50]);


struct Student {
    int id;
    char name[50];
    char course[30];
    int year;
};



int main(){
    int checker, count = 0, account[50][50];
    do{
        printf("\n======Students======\n");
        printf("1.Add student\n");
        printf("2.Display student\n");
        printf("3.Search Student\n");
        printf("4.Exit\n");
        scanf("%d", &checker);

        switch (checker){
        case 1:
            addStudent(&count, account);
            break;
        case 2:
            
        default:
            break;
        }
    } while (checker != 4);
    
    
    return 0;
}


void addStudent(int *count, int account[][50]){
    

    //this is when the the system doesn't have a student yet 
    if (*count == 0){
        printf("How many student you'd be adding?");
        scanf("%d", count);
    }

    

    for (int i = 0; i < *count; i++){
        printf
    }
    

    
    

}