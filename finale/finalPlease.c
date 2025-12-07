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
    //couldn't find the bug that was distrupting this functions so i added getchar
    getchar();
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
    float tempFLOAT = 0;
    printf("Note that this will PERMANENTLY remove the data\n");
    printf("What is the room code for this?: ");
    scanf("%d", &findRoom);
    for (int i = 0; i < *n; i++){
        if (findRoom == rooms[i].roomCode){
            printf("Found room code\n");
            for (int j = i; j < (i - (1 - *n)); j++){ //its 1 - *n because we want to leave the last open
                //simply bubble sorting
                tempINT = rooms[j].roomCode;
                rooms[j].roomCode = rooms[j+1].roomCode;
                rooms[j+1].roomCode = tempINT;
                //reset 
                tempINT = 0;
                tempINT = rooms[j].beds;
                rooms[j].beds = rooms[j+1].beds;
                rooms[j+1].beds = tempINT;
                tempINT = 0;

                tempINT = rooms[j].occupation;
                rooms[j].occupation = rooms[j+1].occupation;
                rooms[j+1].occupation = tempINT;
                tempINT = 0;

                tempFLOAT = rooms[j].price;
                rooms[j].price = rooms[j+1].price;
                rooms[j+1].price = tempFLOAT;
                tempFLOAT = 0;

                strcpy(tempCHAR, rooms[j].name);
                strcpy(rooms[j].name, rooms[j+1].name);
                strcpy(rooms[j+1].name, tempCHAR);

                
            }
            //this is important because if we use "VIEW" function it doesn't show random stuff
            (*n)--;
            //because there is a free index that must be used whenever the user wants to add another room
            old--;
            return;
        }
    }
}

void SAVE(struct Hotel *rooms, int *n){
    //everything will overwrite
    FILE *ptr = fopen("HotelList_rooms.txt", "w");
    for (int i = 0; i < *n; i++){
        fprintf(ptr, "Name of the room: %s\n", rooms[i].name);
        fprintf(ptr, "Room code: %d\n", rooms[i].roomCode);
        fprintf(ptr, "Beds: %d\n", rooms[i].beds);
        fprintf(ptr, "price: %f\n", rooms[i].price);
        fprintf(ptr, "Occupation: %d\n", rooms[i].occupation);
        fprintf(ptr, "\n");
    }
    //we need this for resuming
    fprintf(ptr,"n: %d", *n);
    fclose(ptr);
}

void RESUME(struct Hotel *rooms){
    char BUFFER[MAXBUFFER];
    //we can get all of this information from "SAVE" function
    int nameSize = strlen("Name of the room: ");
    int roomCodeSize = strlen("Room code: ");
    int bedSize = strlen("Beds: ");
    int priceSize = strlen("price: ");
    int occupationSize = strlen("Occupation: ");
    //this is for the index
    int i = 0;

    FILE *ptr = fopen("HotelList_rooms.txt", "r");
    if (ptr == NULL ){
        printf("THERE WAS SOMETHING WRONG INSIDE OF RESUME VARIABLE");
        exit(1);
    }

    while (fgets(BUFFER, MAXBUFFER, ptr)){
        if (strstr(BUFFER, "Name of the room: ")){
            //this works because buffer stats with index 0 and avoids all characters of nameSize
            char *temp = BUFFER + nameSize;//We need a temp to tansfer this to rooms
            strcpy(rooms[i].name, temp);
            rooms[i].name[strcspn(rooms[i].name, "\n")] = '\0';
        }
        if (strstr(BUFFER, "Room code: ")){
            rooms[i].roomCode = atoi(BUFFER + roomCodeSize);
        }
        if (strstr(BUFFER, "Beds: ")){
            rooms[i].beds = atoi(BUFFER + bedSize);
        }
        if (strstr(BUFFER, "price: ")){
            rooms[i].price = atoi(BUFFER + priceSize);
        }
        if (strstr(BUFFER, "Occupation: ")){
            rooms[i].occupation = atoi(BUFFER + occupationSize);
            //this is where we increment i because in the file or the "SAVE" function it ends at occupation
            i++;
        }
    }

    fclose(ptr);
}
struct Hotel* REALLOC(struct Hotel *rooms, int newN, int *n){
    struct Hotel *temp = realloc(rooms, newN * sizeof(struct Hotel));
    *n = newN;
    return temp;
}

int main(){
    int n, choice, checker, newN;
    char BUFFER[MAXBUFFER];
    struct Hotel *rooms;
    printf("WELCOME TO THE ROOM BOOKING SYSTEM\n");
    //checking if the file already has existing data
    FILE *ptr = fopen("HotelList_rooms.txt", "r");
    if (ptr == NULL){
        printf("How many rooms do you know?");
        scanf("%d", &n);
        getchar();
        //mallocating for the rooms using the varaible n as the size
        rooms = malloc(n * sizeof(struct Hotel));
        if (rooms == NULL){
            printf("There was a problem When Mallocating");
            return 1;
        }
    }
    else{ //this is the part where the program resume where it left off
        //this is only my calculation but i wanted to get n first to create size of the "room"
        int sizeN = strlen("n: "); // we can find "n: " from the SAVE function
        while (fgets(BUFFER, MAXBUFFER, ptr) != NULL){
            if (strstr(BUFFER, "n: ")){
                n = atoi(BUFFER + sizeN);
            }
        }
        old = n;
        rooms = malloc(n * sizeof(struct Hotel));
        RESUME(rooms);
    }
    //to be efficient and not slowing down the user's runtime 
    fclose(ptr);

    do{
        printf("=========MENU=========\n");
        printf("[1] ADD ROOMS\n");
        printf("[2] VIEW ROOMS\n");
        printf("[3] EDIT INFO\n");
        printf("[4] Vacant ROOM\n");
        printf("[5] BOOK A ROOM\n");
        printf("[6] DELETE INFO\n");
        printf("[7] EXIT\n");
        
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
                    //because we need to make it bigger than n
                    newN += n;

                    rooms = REALLOC(rooms, newN, &n);
                    ADD(rooms, &n);
                    SAVE(rooms, &n);
                }
            }
            else
                ADD(rooms, &n);
                SAVE(rooms, &n);
            break;
        case 2:
            VIEW(rooms, &n);
            break;
        case 3:
            EDIT(rooms, &n);
            SAVE(rooms, &n);
            break;
        case 4:
            VACANT(rooms, &n);
            break;
        case 5:
            BOOK(rooms, &n);
            SAVE(rooms, &n);
            break;
        case 6:
            DELETE(rooms, &n);
            SAVE(rooms, &n);
            break;
        case 7:
            printf("Thank you for using my system");
            break;
        default:
            break;
        }

    } while (choice != 7);
    
    free(rooms);
    return 0;
}