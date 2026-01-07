#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at beginning
void insertBegin(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

// Insert at end
void insertEnd(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL) {
        head = newnode;
        return;
    }

    struct node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

// Delete from beginning
void deleteBegin() {
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted\n");
}

// Display list
void display() {
    struct node *temp = head;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    while(1) {
        printf("\n1.Insert Begin\n2.Insert End\n3.Delete Begin\n4.Display\n5.Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                scanf("%d", &value);
                insertBegin(value);
                break;

            case 2:
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                deleteBegin();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
