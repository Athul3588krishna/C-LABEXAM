#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;


void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is Full\n");
        return;
    }

    if (front == -1)  
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("%d inserted\n", value);
}


void dequeue() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear) {   // last element
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}


void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}


int main() {
    int choice, value;

    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
