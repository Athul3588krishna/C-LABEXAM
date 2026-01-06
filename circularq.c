#include <stdio.h>
#define SIZE 5

int q[SIZE], front=-1, rear=-1;

void enqueue(int x){
    if((rear+1)%SIZE == front)
        printf("Queue Full\n");
    else{
        if(front==-1) front=0;
        rear = (rear+1)%SIZE;
        q[rear]=x;
    }
}

void dequeue(){
    if(front==-1)
        printf("Queue Empty\n");
    else{
        printf("Deleted: %d\n",q[front]);
        if(front==rear) front=rear=-1;
        else front = (front+1)%SIZE;
    }
}

void display(){
    int i=front;
    if(front==-1){
        printf("Queue Empty\n");
        return;
    }
    while(i!=rear){
        printf("%d ",q[i]);
        i=(i+1)%SIZE;
    }
    printf("%d\n",q[rear]);
}

int main(){
    int ch,x;
    while(1){
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter value: "); scanf("%d",&x); enqueue(x); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
        }
    }
}
