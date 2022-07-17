#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int stack[MAX];
void push();
void pop();
void display();
int top=-1;

int main(){
    int option;
    do{
        printf("\n\n\n***Main Menu***\n\n");
        printf("1. Push\n");
        printf("2. Delete Element\n");
        printf("3. Display\n");
        printf("4. Exit");
        printf("\nEnter option: ");
        scanf("%d",&option);
        switch(option){
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
        }
    }while(option!=4);
    return 0;
}
void push(){
    int data;
    if(top==MAX-1)  printf("Stack is OVERFLOWN");
    else{
        top++;
        printf("Enter the Data: ");
        scanf("%d",&data);
        stack[top]=data;
        printf("Data has been pushed into the Stack");
    }
}
void pop(){
    if(top==-1) printf("Stack is UNDERFLOWN");
    else{
        printf("Popped Element is %d",stack[top]);
        top-=1;
    }
}
void display(){
    if(top==-1) printf("Stack is Empty");
    else{
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}
