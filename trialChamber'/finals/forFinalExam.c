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

void EDIT(shop *bartender, int *n){
    int temp, choice;
    printf("Enter the Liquor Code: ");
    scanf("%d", &temp);
    for (int i = 0; i < *n; i++){
        if (temp == bartender[i].liquorCode){
            printf("Found Liquor!\n");
            do{
                printf("Liquor name:%s\n", bartender[i].name);
                printf("Liquor Count:%d\n", bartender[i].liquors);
                printf("Liquor Code:%d\n", bartender[i].liquorCode);
                printf("Liquor price:%.2f\n", bartender[i].price);
                
                printf("What do you wish to change?\n");
                printf("[1] Name\n");
                printf("[2] Quantity\n");
                printf("[3] Liquor Code\n");
                printf("[4] Liquor Price\n");
                printf("[5] EXIT\n");
                
                scanf("%d", &choice);
                getchar();

                switch (choice){
                case 1:
                    printf("What is the new name:");
                    fgets(bartender[i].name, MAXSIZE, stdin);
                    break;
                case 2:
                    printf("What is the new Quantity?: ");
                    scanf("%d", bartender[i].liquors);
                    break;
                case 3:
                    printf("What is the new Liquor Code?: ");
                    scanf("%d", bartender[i].liquorCode);
                    break;
                case 4:
                    printf("What is the new Liquor Price?: ");
                    scanf("%f", bartender[i].price);
                    break;
                case 5:
                    printf("EDIT COMPLETE!");
                    break;
                default:
                    break;
                }
            } while (choice != 5);
        }
    }
    
    

}

void REMOVE(shop *bartender, int *n){
    int elimate, temp;
    char charTemp[MAXSIZE];
    float floatTemp;
    
    printf("What do you wish to remove from the list");
    scanf("%d", &elimate);
    getchar();
    for (int i = 0; i < *n; i++){
        if (elimate == bartender[i].liquorCode){
            printf("Found Liquor");
            for (int j = i; j < (*n-1); j++){
                strcpy(charTemp,bartender[j].name);
                strcpy(bartender[j].name, bartender[j+1].name);
                strcpy(bartender[j+1].name, charTemp);

                temp = bartender[j].liquors;
                bartender[j].liquors = bartender[j+1].liquors;
                bartender[j+1].liquors = temp;

                temp = bartender[j].liquorCode;
                bartender[j].liquorCode = bartender[j+1].liquorCode;
                bartender[j+1].liquorCode = temp;
                
                floatTemp = bartender[j].price;
                bartender[j].price = bartender[j+1].price;
                bartender[j+1].price = floatTemp;
            }
            printf("Removed Succesfully\n");
            //because we reduced the list
            old--;
            *n--;
        }
    }
}

shop *REALLOC(shop *bartender, int *newN){
    shop *temp = realloc(bartender, *newN * sizeof(shop));
    return temp;
}

int main(){
    int n, choice, newN, detector;
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
            if (old == n){
                printf("It seems that you want to add more. do you wish to continue?[1] for yes [0] for no: ");
                scanf("%d", &detector);
                if (detector != 0 && detector != 1){
                    while (detector != 0 && detector != 1){
                        printf("Wrong input!\n");
                        printf("It seems that you want to add more. do you wish to continue?[1] for yes [0] for no: ");
                        scanf("%d", &detector);
                        getchar();
                    }
                }
                if (detector == 1){
                    printf("How much do you want to add?: ");
                    scanf("%d", &newN);
                    newN += n;
    
                    bartender = REALLOC(bartender, &newN);
                    ADD(choice, &n);
                }
                else{
                    break;
                }
            }
            else{
                ADD(choice, &n);
            }
            break;
        case 2:
            EDIT(choice, &n);
            break;
        case 3:
            REMOVE(choice, &n);
            break;
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