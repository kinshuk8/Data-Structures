#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *start=NULL;
struct node *create_dll(struct node *);
struct node *display_dll(struct node *);
struct node *insert_beginning(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *delete_beginning(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *);

int main(){
    int option;
    do{
        printf("\n\n****Main Menu****\n");
        printf("\n1. Create List");
        printf("\n2. Display List");
        printf("\n3. Insert a Node at the Beginning");
        printf("\n4. Insert a Node at the End");
        printf("\n5. Insert a Node Before a Value");
        printf("\n6. Delete a Node at the Beginning");
        printf("\n7. Delete a Node at the End");
        printf("\n8. Delete a Node before a value");
        printf("\n9. To Stop");
        printf("\nEnter Option: ");
        scanf("%d",&option);
        switch(option){
            case 1:start=create_dll(start);
            printf("List is Created");
            break;
            case 2:start=display_dll(start);
            break;
            case 3:start=insert_beginning(start);
            break;
            case 4:start=insert_end(start);
            break;
            case 5:start=insert_before(start);
            break;
            case 6:start=delete_beginning(start);
            break;
            case 7:start=delete_end(start);
            break;
            case 8:start=delete_before(start);
            break;
        }
    }while(option!=9);
    return 0;
}

struct node *create_dll(struct node *start){
    struct node *newnode,*ptr;
    int num;
    printf("Enter -1 to Stop the Iteration");
    printf("\nEnter the Data: ");
    scanf("%d",&num);
    while(num!=-1){
        if(start==NULL){
            newnode=(struct node *)malloc(sizeof(struct node));
            newnode->data=num;
            newnode->next=NULL;
            newnode->prev=NULL;
            start=newnode;
        }
        else{
            newnode=(struct node *)malloc(sizeof(struct node));
            newnode->data=num;
            ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->prev=ptr;
            newnode->next=NULL;
        }
        printf("Enter the Data: ");
        scanf("%d",&num);
    }
    return start;
}

struct node *display_dll(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
    return start;
}

struct node *insert_beginning(struct node *start){
    struct node *newnode;
    int num;
    printf("Enter the Data: ");
    scanf("%d",&num);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=start;
    newnode->prev=NULL;
    start->prev=newnode;
    start=newnode;
    return start;
}

struct node *insert_end(struct node *start){
    struct node *newnode,*ptr;
    int num;
    printf("Enter the Data: ");
    scanf("%d",&num);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    ptr=start;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    newnode->prev=ptr;
    ptr->next=newnode;
    newnode->next=NULL;
    return start;
}

struct node *insert_before(struct node *start){
    struct node *newnode,*ptr,*preptr;
    int num,pos;
    printf("Enter the Data: ");
    scanf("%d",&num);
    printf("Enter the value before where the Node has to be inserted: ");
    scanf("%d",&pos);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    ptr=start;
    while(ptr->data!=pos){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=newnode;
    newnode->next=ptr;
    return start;
}

struct node *delete_beginning(struct node *start){
    struct node *ptr;
    ptr=start;
    start=start->next;
    start->prev=NULL;
    free(ptr);
}

struct node *delete_end(struct node *start){
    struct node *ptr,*preptr;
    ptr=start;
    while(ptr->next!=NULL){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    return start;
}

struct node *delete_before(struct node *start){
    struct node *ptr,*temp;
    int var;
    printf("Enter the value before where the node has to be Deleted: ");
    scanf("%d",&var);
    ptr=start;
    while(ptr->data!=var){
        ptr=ptr->next;
    }
    temp=ptr->prev;
    ptr->prev=temp->prev;
    temp->prev->next=ptr;
}
