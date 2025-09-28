#include <stdio.h>
//Accounting project

typedef struct{
    char particular[50];
    

    
}jounralize;

void addParticular();
void addParticular(){
    
}

void menu();
void menu(){
    int choice = 0;
    while(choice !=4){
        printf("\n===MENU===\n");
        printf("1.ADD PARTICULAR\n");
        printf("2.SEE ALL PARTICULAR");
        printf("3.ADJUST A PARTICULAR\n");
        printf("4.INCOME STATEMENT\n");
        printf("5.CLOSING ENTRIES\n");
        printf("6.SAVE INFORMATION\n");
        printf("7.RESUME PREVIOUS JOUNRALIZE\n");
        printf("ENTER YOUR ANSWER:");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            addParticular();
            break;
        
        default:
            break;
        }
    }

}

int main(){

    printf("WECLOME TO THE ACCOUNTING SYSTEM\n");
    menu();

    return 0;
}