#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 100
typedef struct{
    char name_coffee[MAX];
    int quanity;
    float ml;
}coffee;

int old = 0;

int main(){
    int n;
    printf("how many coffee do you want to add to the inventory?: ");
    scanf("%d", &n);

    coffee *shop = malloc(n * sizeof(coffee));
    if(shop == NULL){
        printf("THERE WAS A PROBLEM ALLOCATING MEMORY!");
        return 1;
    }

    menu(&n, &shop);

    free(shop);
    return 0;
}

void menu(int *n, coffee **shop){
    int choice;

    do{
        printf("======MENU======\n");
        printf("[1] ADD\n");
        printf("[2] EDIT\n");
        printf("[3] REALLOC\n");
        
        scanf("%d", &choice);

        switch (choice){
        case 1:
            break;
        case 2:
            break;
        case 3:
            old = *n;
            newMemory(n, *shop);
            break;
        
        default:
            printf("THANK YOU FOR USING THE SYSTEM");
            break;
        }
    
    } while (choice != 4);

}
void newMemory(int *n, coffee *shop){
    printf("how much ")


}