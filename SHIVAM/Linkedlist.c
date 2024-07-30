#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void print(struct node*head){
    if(head==NULL){
        printf("Empty linked list \n");
    }
    struct node*ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        printf("%d \n",ptr->data);
        ptr=ptr->link;
    }
}

int main(){
struct node *head=malloc(sizeof(struct node));
head->data=10;
head->link=NULL;

struct node *ptr=malloc(sizeof(struct node));
ptr->data=20;
ptr->link=NULL;

head->link=ptr;

ptr =malloc(sizeof(struct node));
ptr->data=30;
ptr->link=NULL;

head->link->link=ptr;

print(head);
return 0;
}
