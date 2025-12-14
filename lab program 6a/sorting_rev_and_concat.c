#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node *list1 = NULL, *list2 = NULL;

/* ---------- Utility Functions ---------- */

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

node* insertEnd(node* head, int data) {
    node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* ---------- Sort ---------- */

void sortList(node* head) {
    for (node* i = head; i != NULL; i = i->next) {
        for (node* j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

/* ---------- Reverse ---------- */

node* reverseList(node* head) {
    node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

/* ---------- Concatenation ---------- */

node* concatenate(node* head1, node* head2) {
    if (head1 == NULL)
        return head2;

    node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

/* ---------- Main Menu ---------- */

int main() {
    int choice, data;

    while (1) {
        printf("\n------ MENU ------\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List 1 and List 2\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                list1 = insertEnd(list1, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                list2 = insertEnd(list2, data);
                break;

            case 3:
                printf("List 1: ");
                display(list1);
                break;

            case 4:
                printf("List 2: ");
                display(list2);
                break;

            case 5:
                sortList(list1);
                printf("List 1 sorted successfully!\n");
                break;

            case 6:
                list1 = reverseList(list1);
                printf("List 1 reversed successfully!\n");
                break;

            case 7:
                list1 = concatenate(list1, list2);
                list2 = NULL;
                printf("Lists concatenated successfully!\n");
                break;

            case 8:
                printf("Program exited.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}

