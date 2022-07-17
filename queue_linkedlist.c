#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

//Function for the Creation of the Queue
void enqueue(){
    int value;
    printf("Enter the Data: ");
    scanf("%d",&value);
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=value;
    ptr->next=NULL;
    if(front==NULL && rear ==NULL){
        front=rear=ptr;
    }
    else{
        rear->next=ptr;
        rear=ptr;
    }
    printf("Node is Inserted");
}

//Function for Deleting an Element from the Queue
void dequeue(){
    if(front==NULL) printf("Queue is Underflown");
    else{
        struct node *ptr=front;
        front=front->next;
        printf("Data Being Removed is %d",ptr->data);
        free(ptr);
    }
}

//To display the Queue
void display(){
    struct node *ptr=front;
    if(front==NULL && rear==NULL)   printf("Queue is Empty");
    else{
        printf("The Queue is:\n");
        while(ptr!=NULL){
            printf("%d\t",ptr->data);
            ptr=ptr->next;
        }
    }
}

int main(){
    int option;
    do{
        printf("\n\n***Main Menu***\n\n");
        printf("\n1. Insert Element");
        printf("\n2. Delete Element");
        printf("\n3. Display Queue");
        printf("\n4. Exit");
        printf("\nEnter Option: ");
        scanf("%d",&option);
        switch(option){
            case 1:enqueue();
            break;
            case 2:dequeue();
            break;
            case 3:display();
        }
    }while(option!=4);
    return 0;
}
