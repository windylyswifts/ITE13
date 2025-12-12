#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//bartender shop

#define MAXSIZE 125
#define MAXBUFFER 1225

int old = 0;

typedef struct{
    int liquors;
    char name[MAXSIZE];
    float price;
    int liquorCode;
    
}shop;

void ADD(shop *bartender, int *n){
    for (int i = old; i < *n; i++){
        printf("Liquor number %d\n", i+1);
        printf("Enter Liquor Code: ");
        scanf("%d", &bartender[i].liquorCode);
        getchar();
        printf("Liquor's name: ");
        fgets(bartender[i].name, MAXSIZE, stdin);
        bartender[i].name[strcspn(bartender[i].name, "\n")] = '\0';
        printf("Liquor's price: ");
        scanf("%f", &bartender[i].price);
        printf("How many is there?: ");
        scanf("%d", &bartender[i].liquors);
    }

    old = *n;
}



int main(){
    int n, choice;
    printf("how much liqour");
    scanf("%d", &n);
    getchar();
    shop *bartender = malloc(n * sizeof(shop));
    if (bartender == NULL){
        printf("There was an error during mallocating");
        return 1;
    }

    printf("Welcome to the Shop.\n");
    do{
        printf("\n=========MENU=========\n");
        printf("[1] ADD\n");
        printf("[2] EDIT\n");
        printf("[3] REMOVE\n");
        printf("[4] BUY\n");
        printf("[5] LIST\n");
        printf("[6] EXIT\n");
        scanf("%d", &choice);
        getchar();
        
        switch (choice){
        case 1:
            ADD(choice, &n);
            break;
        // case 2:
        //     ADD();
        //     break;
        // case 3:
        //     ADD();
        //     break;
        // case 4:
        //     ADD();
        //     break;
        // case 5:
        //     ADD();
        //     break;
        // case 6:
        //     ADD();
        //     break;
        
        default:
            break;
        }
        
    } while (choice !=6);
    



    return 0;
}