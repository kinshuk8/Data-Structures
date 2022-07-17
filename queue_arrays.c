#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int queue[MAX];
int front=-1;
int rear=-1;

void insert_element();
void delete_element();
void display();

int main(){
    int option;
    do{
        printf("\n\n***Main Menu***\n\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Queue\n");
        printf("4. Exit");
        printf("\nEnter Option: ");
        scanf("%d",&option);
        switch(option){
            case 1:insert_element();
            break;
            case 2:delete_element();
            break;
            case 3:display();
            break;
        }
    }while(option!=4);
    return 0;
}
void insert_element(){
    int data;
    printf("Enter the Data: ");
    scanf("%d",&data);
    if(rear==MAX-1) printf("Queue is Overflown");
    else if(rear==-1 &&front==-1){
        front=rear=0;
        queue[rear]=data;
    }
    else{
        rear++;
        queue[rear]=data;
    }
}
void delete_element(){
    if(front==-1 || front>rear){
        printf("Queue is Underflown");
    }
    else{
        printf("Data being Deleted is %d",queue[front]);
        front+=1;
        if(front>rear){
            front=rear=-1;
        }
    }
}
void display(){
    if(front==-1 || front>rear) printf("Stack is Empty");
    else{
        for(int i=front;i<=rear;i++) printf("%d\t",queue[i]);
    }
}
