#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Whole system with many functions

#define MAXSIZE 125
#define MAXBUFFER 1024

//this variable is used as a updater for iterations
int old = 0;

struct Hotel{
    int roomCode;
    int beds;
    float price;
    char name[MAXSIZE];
    int occupation;
};

void ADD(struct Hotel *rooms, int *n){
    //old is used here marks as the starting point for each adding
    for (int i = old; i < *n; i++){
        printf("Room Number %d\n", i+1);
        printf("What is the name of the room?:");
        fgets(rooms[i].name, MAXSIZE, stdin);
        rooms[i].name[strcspn(rooms[i].name, "\n")] = '\0';
        printf("What is the room code for this?: ");
        scanf("%d", &rooms[i].roomCode);
        printf("How many beds does this room has?: ");
        scanf("%d", &rooms[i].beds);
        printf("How much is the rate per booking?: ");
        scanf("%f", &rooms[i].price);
        printf("Is this available right now [1] if occopied [0] if not: ");
        scanf("%d", &rooms[i].occupation);
        //This condition is to know if the user did input the right numbers
        while (rooms[i].occupation != 0 && rooms[i].occupation != 1){
            printf("WRONG INPUT!!\n");
            printf("Is this available right now [1] if occopied [0] if not: ");
            scanf("%d", &rooms[i].occupation);
        }
        //becuse the next is fgets
        getchar();
    }

    old = *n;
}

void VIEW(struct Hotel *rooms, int *n){
    for (int i = 0; i < *n; i++){
        printf("\n\n========================================\n");
        printf("Room Number %d\n", i+1);
        printf("Room Code %d\n", rooms[i].roomCode);
        printf("Name of the Room: %s\n", rooms[i].name);
        printf("Bed Count: %d\n", rooms[i].beds);
        printf("Price per night: %.2f\n", rooms[i].price);
        //for User readability, they'll jus tsee Vacant or Occupied
        if (rooms[i].occupation == 0){
            printf("Availability: VACANT\n");
        }
        else{
            printf("Availibility: Occupied\n");
        }
    }
    printf("\n\n========================================\n");
}

void EDIT(struct Hotel *rooms, int *n){
    int temp, choice;
    printf("What is the room code your trying to find?: ");
    scanf("%d", &temp);
    for(int i = 0; i < *n; i++){
        //this way we can find the index just by finding the ID or roomCode
        if (temp == rooms[i].roomCode){
            printf("Found Room!\n");
            //this is over the top but basically an option on which you want to edit
            do{
                printf("[1] Edit roomCode\n");
                printf("[2] Edit beds\n");
                printf("[3] Edit price\n");
                printf("[4] Edit name\n");
                printf("[5] Edit occupation\n");
                printf("[6] Exit\n");
                printf("Enter Ans:");
                scanf("%d", &choice);
                //since there is an option where we can change the name so we getchar first here
                getchar();
                switch (choice){
                case 1:
                    printf("What is the new Room Code?: ");
                    scanf("%d", &rooms[i].roomCode);
                    break;
                case 2:
                    printf("What is the new Bed Cunt?: ");
                    scanf("%d", &rooms[i].beds);
                    break;
                case 3:
                    printf("What is the new price?: ");
                    scanf("%f", &rooms[i].price);
                    break;
                case 4:
                    printf("What is the new name?: ");
                    fgets(rooms[i].name, MAXSIZE, stdin);
                    rooms[i].name[strcspn(rooms[i].name, "\n")] = '\0';
                    break;
                case 5:
                    printf("What is the new occupation? [0] for vacant, [1] is occupied: ");
                     scanf("%d", &rooms[i].occupation);
                    //This condition is to know if the user did input the right numbers
                    while (rooms[i].occupation != 0 && rooms[i].occupation != 1){
                        printf("WRONG INPUT!!\n");
                        printf("What is the new occupation? [0] for vacant, [1] is occupied: ");
                        scanf("%d", &rooms[i].occupation);
                    }
                    break;
                default:
                    break;
                }
            } while (choice != 6);            
            //Because the ID was already found
            return;
        }
    }
}

void VACANT(struct Hotel *rooms, int *n){
    for (int i = 0; i < *n; i++){
        if (rooms[i].occupation == 0){
            printf("\n\n========================\n");
            printf("Vacant Room number %d:\n", i+1);
            printf("Room Code %d\n", rooms[i].roomCode);
            printf("Name of the Room: %s\n", rooms[i].name);
            printf("Bed Count: %d\n", rooms[i].beds);
            printf("Price per night: %.2f\n", rooms[i].price);
            printf("\n\n========================\n");
        }
    }
}

void BOOK(struct Hotel *rooms, int *n){
    int choice,booking, checker = 0;
    printf("Enter the Room Code that you want to book for today: ");
    scanf("%d", &booking);

    do{
        for (int i = 0; i < *n; i++){
            if (booking == rooms[i].roomCode && rooms[i].occupation== 0){
                printf("\nFound Room and booked succesfully!\n");
                rooms[i].occupation = 1;
                checker++;
            }
        }
        if (checker == 0){
            do{
                printf("Couldn't find the room OR room is occupied\n");
                printf("Do you want to try again and enter another Room Code?: [1] for yes, [0] for no\n");
                scanf("%d", &choice);
                switch (choice){
                case 0:
                    //to stop the outer do while loop
                    checker++;
                    break;
                case 1:
                    printf("Enter the Room Code that you want to book for today: ");
                    scanf("%d", &booking);
                    break;
                default:
                    break;
                }
            } while (choice != 1 && choice != 0);
        }
    } while (checker == 0);
}

void DELETE(struct Hotel *rooms, int *n){
    int findRoom, tempINT = 0;
    char tempCHAR[MAXSIZE];
    printf("Note that this will PERMANENTLY remove the data\n");
    printf("What is the room code for this?: ");
    scanf("%d", &findRoom);
    for (int i = 0; i < *n; i++){
        if (findRoom == rooms[i].roomCode){
            printf("Found room code\n");
            for (int j = i; j < (i - (1 - *n)); j++){ //its 1 - *n because we want to leave the last open
                tempINT = rooms[j].roomCode;
                rooms[j].roomCode = rooms[j+1].roomCode;
                rooms[j+1].roomCode = tempINT;

                tempINT = 0;
                //updater for old so that by the end of this there is an empty space that the user can input
                //i think its likely that there should be a conditioning inside of ADD
                //i think we need to remove the increased size and put it as a system in ADD
                
                //because there is a free index that must be used whenever the user wants to add another room
                old--;
            }
            return;
        }
    }
}

struct Hotel* REALLOC(struct Hotel *rooms, int newN, int *n){
    struct Hotel *temp = realloc(rooms, newN * sizeof(struct Hotel));
    *n = newN;
    return temp;
}

int main(){
    int n, choice, checker, newN;
    printf("WELCOME TO THE ROOM BOOKING SYSTEM\n");
    printf("How many rooms do you know?");
    scanf("%d", &n);

    //mallocating for the rooms using the varaible n as the size
    struct Hotel *rooms = malloc(n * sizeof(struct Hotel));
    if (rooms == NULL){
        printf("There was a problem When Mallocating");
        return 1;
    }
    
    do{
        printf("=========MENU=========\n");
        printf("[1] ADD ROOMS\n");
        printf("[2] VIEW ROOMS\n");
        printf("[3] EDIT INFO\n");
        printf("[4] Vacant ROOM\n");
        printf("[5] BOOK A ROOM\n");
        printf("[6] DELETE INFO\n");
        printf("[7] SAVE\n");
        printf("[8] RESUME\n");
        printf("[9] DataFinder(Only when there is an existing data in the file)\n");
        printf("[10] EXIT\n");
        
        scanf("%d", &choice);
        //its best to getchar here because we are calling functions and some may start with fgets so better
        //to avoid more dugging
        getchar();

        switch (choice){
        case 1:
            if (old == n){
                do{
                    printf("It seems that you're list is full. Do you want to add more rooms?[1] for yes [0] for no: ");
                    scanf("%d", &checker);
                } while (checker != 0 && checker != 1);
                if (checker == 1){
                    printf("How much do you want to add?: ");
                    scanf("%d", &newN);

                    newN += n;

                    rooms = REALLOC(rooms, newN, &n);
                    ADD(rooms, &n);
                }
            }
            else
                ADD(rooms, &n);
            break;
        case 2:
            VIEW(rooms, &n);
            break;
        case 3:
            EDIT(rooms, &n);
            break;
        case 4:
            VACANT(rooms, &n);
            break;
        case 5:
            BOOK(rooms, &n);
            break;
        case 6:
            DELETE(rooms, &n);
            break;
        case 7:
            
            break;
        
        default:
            break;
        }

    } while (choice != 10);
    


    free(rooms);
    return 0;
}