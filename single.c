#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;

void insert_begin(int x){
    struct node *n = malloc(sizeof(struct node));
    n->data=x;
    n->next=head;
    head=n;
}

void insert_end(int x){
    struct node *n = malloc(sizeof(struct node));
    n->data=x; n->next=NULL;
    if(head==NULL){ head=n; return; }
    struct node *t=head;
    while(t->next!=NULL) t=t->next;
    t->next=n;
}

void delete_begin(){
    if(head==NULL) return;
    struct node *t=head;
    head=head->next;
    free(t);
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
        printf("\n1.Insert Begin 2.Insert End 3.Delete 4.Display 5.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: scanf("%d",&x); insert_begin(x); break;
            case 2: scanf("%d",&x); insert_end(x); break;
            case 3: delete_begin(); break;
            case 4: display(); break;
            case 5: return 0;
        }
    }
}
