#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int ID;
    char name[100];
    float price;
    int quantity;
}game;

int old = 0;

int main(){
    int n, choice;
    printf("how many games do you have in mind?: ");
    scanf("%d", &n);

    game *gameHolder = malloc(n * sizeof(game));
    if(gameHolder == NULL){
        printf("SOMETHING WENT WRONG IN MALLOC");
        return 1;

    }

    do{
        printf("WECLOME!\n");
        pritnf("[1] ADD\n");
        pritnf("[2] EDIT\n");
        pritnf("[3] BUY\n");
        pritnf("[4] REALLOC\n");
        
        scanf("%d", &choice);

        switch (choice){
        case 1:
            getchar();
            add(&n, &gameHolder);
            break;
        case 2:
            edit();
            break;
        case 3:
            break;
        case 4:
            reallocNew(&n, &gameHolder);
            break;
        default:
            printf("not valid!\n");
            break;
        }

        
    } while (choice != 5);
    

    return 0;
}

void add(int *n, game **gameholder){
    for (int i = old; i < *n; i++){
        printf("Game %d", i+1);
        printf("Game name: ");
        fgets((*gameholder)[i].name, 100, stdin);
        (*gameholder)[i].name[strcspn((*gameholder)[i].name, "\n")] = '\0';
        printf("Game ID:");
        scanf("%d", &(*gameholder)[i].ID);
        printf("Game's price: ");
        scnaf("%f", &(*gameholder)[i].price);
        printf("Game's quantity: ");
        scnaf("%d", &(*gameholder)[i].quantity);
        getchar();
    }

    old = *n;
}

void reallocNew(int *n, game **gameholder){
    int temp;
    printf("how much do yu want to realloc?:");
    scanf("%d", &temp);

    *gameholder = realloc(*gameholder, (*n + temp) * sizeof(game));
    *n += temp;

}
