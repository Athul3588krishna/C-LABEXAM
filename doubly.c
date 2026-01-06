#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev,*next;
};

struct node *head=NULL;

void insert_begin(int x){
    struct node *n=malloc(sizeof(struct node));
    n->data=x;
    n->prev=NULL;
    n->next=head;
    if(head!=NULL) head->prev=n;
    head=n;
}

void insert_end(int x){
    struct node *n=malloc(sizeof(struct node));
    n->data=x; n->next=NULL;
    if(head==NULL){ n->prev=NULL; head=n; return; }
    struct node *t=head;
    while(t->next!=NULL) t=t->next;
    t->next=n; n->prev=t;
}

void display(){
    struct node *t=head;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
}

int main(){
    int ch,x;
    while(1){
        printf("\n1.Insert Begin 2.Insert End 3.Display 4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: scanf("%d",&x); insert_begin(x); break;
            case 2: scanf("%d",&x); insert_end(x); break;
            case 3: display(); break;
            case 4: return 0;
        }
    }
}
