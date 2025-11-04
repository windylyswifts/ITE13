#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int old = 0;

typedef struct{
    int book_id;
    char name[MAX];
    int quantity;
    char author[MAX];
}library;


void add(library *account, int *max_books){
    int val = 0, changer = 0;
    for(int i = old ;i < *max_books + old; i++){
        printf("Book number %d\n", i+1);
        printf("Enter book ID:");
        scanf("%d", &account[i].book_id);
        getchar();
        printf("Enter name of the book");
        fgets(account[i].name, MAX, stdin);
        account[i].name[strcspn(account[i].name, "\n")] = '\0';
        printf("How many?: ");
        scanf("%d", &account[i].quantity);
        getchar();
        printf("Who is the author?: ");
        fgets(account[i].author, MAX, stdin);
        account[i].author[strcspn(account[i].author, "\n")] = '\0';
    }

    old = *max_books;
}

void display(library *account, int max_books){
    for(int i = 0; i < max_books + old; i++){
        printf("Book number %d\n", i+1);
        printf("Book ID:%d\n", account[i].book_id);
        printf("Book name's: %s\n4", account[i].name);
        printf("Quantity: %d\n", account[i].quantity);
        printf("Book's author: %s\n", account[i].author);
    }
}

void edit(library *account, int max_books){
    int n, changer;
    printf("What is the ID of the book?:");
    scanf("%d", &n);

    for(int i = 0; i < max_books;i++){
        if(account[i].book_id == n){
            printf("What do you wish to edit on this book?\n");
            printf("1.book_id\n");
            printf("2.name\n");
            printf("3.quantity\n");
            printf("4.author\n");
            scanf("%d", &changer);
            getchar();
            if(changer < 0 || changer > 5){
                printf("invalid input, putting you back to the menu.\n");
                changer = 0;
                break;
            }

            switch(changer){
            case 1:
                printf("What is the new book_id?: ");
                scanf("%d", &account[i].book_id);
                printf("Success!\n");
                break;
            case 2:
                printf("What is the new name?: ");
                fgets(account[i].name, MAX, stdin);
                account[i].name[strcspn(account[i].name, "\n")] = '\0';
                printf("Success!\n");
                break;
            case 3:
                printf("What is the new Quantity?:");
                scanf("%d", &account[i].quantity);
                printf("Success!\n");
                break;
            case 4:
                printf("Who is the new author");
                fgets(account[i].author, MAX, stdin);
                account[i].author[strcspn(account[i].author, "\n")] = '\0';
            default:
                break;
            }
        }
    }
}

int main(){
    int max_books, checker = 0, ifNew = 0, newMax_books;

    printf("How many books you'd be adding?: ");
    scanf("%d", &max_books);

    library *account = malloc(max_books * sizeof(library));
    if(account == NULL){
        printf("THERE WAS AN ERROR IN ALLOCATING MEMORY");
        return 1;
    }

    do{
        printf("1.ADD\n");
        printf("2.Display\n");
        printf("3.Edit\n");
        printf("4.Exit\n");
        scanf("%d", &checker);

        switch(checker){
        case 1:
            if(ifNew == 0){
                add(account, &max_books);
                ifNew++;
                break;
            }
            else{
                printf("it seems that you want to add more, how much you'd want to allocate?:");
                scanf("%d", &newMax_books);
                account = realloc(account, newMax_books * sizeof(library));
                add(account, &newMax_books);
                break;
            }
        case 2:
            if(ifNew == 0){
                display(account, max_books);
                break;
            }
            else{
                display(account, newMax_books);
                break;
            }
        case 3:
            if(ifNew == 0){
                edit(account, max_books);
                break;
            }
            else{
                edit(account, newMax_books);
                break;
            }

        case 4:
            printf("Thank you!\n");
            break;
        default:
            break;
        }
    }while(checker !=4);

    free(account);

    return 0;

}


