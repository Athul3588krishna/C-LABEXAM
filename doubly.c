#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Insert at beginning
void insertBegin(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->prev = NULL;
    n->next = head;

    if (head != NULL)
        head->prev = n;

    head = n;
}

// Insert at end
void insertEnd(int x) {
    struct node *n = malloc(sizeof(struct node));
    struct node *t = head;

    n->data = x;
    n->next = NULL;

    if (head == NULL) {
        n->prev = NULL;
        head = n;
        return;
    }

    while (t->next != NULL)
        t = t->next;

    t->next = n;
    n->prev = t;
}

// Delete at beginning
void deleteBegin() {
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }

    struct node *t = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(t);
}

// Display
void display() {
    struct node *t = head;
    if (head == NULL) {
        printf("List Empty\n");
        return;
    }

    while (t != NULL) {
        printf("%d <-> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main() {
    int ch, x;

    while (1) {
        printf("\n1.Insert Begin 2.Insert End 3.Delete Begin 4.Display 5.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                scanf("%d", &x);
                insertBegin(x);
                break;

            case 2:
                scanf("%d", &x);
                insertEnd(x);
                break;

            case 3:
                deleteBegin();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);
        }
    }
}
