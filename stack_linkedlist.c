#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack *next;
};

struct stack *top=NULL;
struct stack *push(struct stack *);
struct stack *pop(struct stack *);
struct stack *display(struct stack *);

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
            case 1:top=push(top);
            printf("Data is Pushed into the Stack");
            break;
            case 2:top=pop(top);
            break;
            case 3:display(top);
            break;
        }
    }while(option!=4);
    return 0;
}
struct stack *push(struct stack *top){
    int value;
    struct stack *ptr=(struct stack*)malloc(sizeof(struct stack));
    printf("Enter the Data: ");
    scanf("%d",&value);
    ptr->data=value;
    if(top==NULL){
        ptr->next=NULL;
        top=ptr;
    }
    else{
        ptr->next=top;
        top=ptr;
    }
    return top;
}
struct stack *pop(struct stack *top){
    struct stack *ptr=top;
    if(top==NULL)   printf("\nStack is UNDERFLOWN");
    else{
        top=top->next;
        printf("\nThe element being deleted is %d",ptr->data);
        free(ptr);
    }
    return top;
}
struct stack *display(struct stack *top){
    struct stack *ptr;
    ptr=top;
    if(top==NULL)   printf("Stack is Empty");
    else{
        while(ptr->next!=NULL){
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
        printf("%d",ptr->data);
    }
}
