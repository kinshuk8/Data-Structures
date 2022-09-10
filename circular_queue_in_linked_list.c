#include<stdio.h>
#define MAX 10

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int element){
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=element;
    }
    else if((rear+1)%MAX==front){
        printf("Queue is OVERFLOWN");
    }
    else{
        rear=(rear+1)%MAX;
        queue[rear]=element;
    }
}

int dequeue(){
    if(front==-1 && rear==-1){
        printf("Queue is Overflown");
    }
    else if(front==rear){
        printf("The dequeued element is %d",queue[front]);
        front=rear=-1;
    }
    else{
        printf("The dequeued element is %d",queue[front]);
        front=(front+1)%MAX;
    }
}

void display(){
    int i=front;
    if(front==-1 && rear==-1){
        printf("Queue is Empty");
    }
    else{
        printf("\nElements in the Queue are: ");
        while(i<=rear){
            printf("%d ",queue[i]);
            i=(i+1)%MAX;
        }
    }
}

int main(){
    int choice,value;
    do{
        printf("\n\n**MAIN MENU**\n\n");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display Queue");
        printf("\n4. Exit");
        printf("\nEnter the Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the element to be inserted: ");
            scanf("%d",&value);
            enqueue(value);
            break;
            case 2:dequeue();
            break;
            case 3:display();
        }
    }while(choice!=4);
    return 0;
}
