#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    // Step 1: Create first node (head)
    struct Node *head = malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL; // no next yet

    // Step 2: Create second node
    struct Node *second = malloc(sizeof(struct Node));
    second->data = 20;
    second->next = NULL;

    // Step 3: Connect first node to second
    head->next = second;

    // Step 4: Traverse and print the list
    struct Node *temp = head;  // start from the first node
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next; // move to next node
    }
    printf("NULL\n");

    // Step 5: Free the memory
    free(second);
    free(head);

    return 0;
}
