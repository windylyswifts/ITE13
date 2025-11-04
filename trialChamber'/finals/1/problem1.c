#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct library{
    int book_id;
    char name[50];
    char date[50];
    int status;
};

void addbook(struct library *holder, int *store, int *temp);

int main(){
    int store, checker = 0, temp = 0, newSize;

    printf("Enter how many book you'd be adding?(MAX):");
    scanf("%d", &store);

    struct library *holder = malloc(store * sizeof(struct library));
    if(holder == NULL){
        printf("there was an earror");
        return 1;
    }

    do{
        printf("1. Add book\n");
        printf("2. Display\n");
        printf("3. EXIT\n");
        scanf("%d", &checker);
        getchar();

        switch(checker){
            case 1:
                addbook(holder, &store, &temp);
                break;
            default:
                display(holder, &store, &temp);
                break;

        }

    }while(checker != 3);

    free(holder);
}

void addbook(struct library *holder, int *store, int *temp){
    int checker = 0;

    for(int i = *temp; i <  *store; i++){
        printf("Enter the Book number %d:\n", i+1);
        printf("Book ID:");
        scanf("%d", &holder[i].book_id);
        getchar();
        printf("name of the book:");
        fgets(holder[i].name, 50, stdin);
        holder[i].name[strcspn(holder[i].name, "\n")] = '\0';


        printf("enter date:");
        fgets(holder[i].date, 50, stdin);
        holder[i].date[strcspn(holder[i].name, "\n")] = '\0';


        printf("status: 1 = available, 2 = borrowed, 3 = not used\n");
        scanf("%d", &checker);
        getchar();

        if(checker == 0 || checker > 3){
            while(checker == 0 || checker > 3){
                printf("Invalid input!\n");
                printf("status: 1 = available, 2 = borrowed, 3 = not used\n");
                scanf("%d", &checker);
            }
        }

        holder[i].status = checker;

    }
}

void display(struct library *holder, int *store, int *temp){
    for(int i = *temp; i < *store; i++){
        printf("Book ID:%d", holder[i].book_id);
        printf("name:%s", holder[i].name);
        printf("Date:%s", holder[i].date);
        printf("Status:%d", holder[i].status);
    }
}
