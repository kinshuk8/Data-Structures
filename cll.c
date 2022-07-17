#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display_ll(struct node *);
struct node *insert_beginning(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *delete_beginning(struct node *);
struct node *delete_end(struct node *);
struct node *delete_atpos(struct node *);

int main(){
    int option;
    do{
        printf("\n\n****Main Menu****\n");
        printf("\n1. Create List");
        printf("\n2. Display List");
        printf("\n3. Insert Node at Beginning");
        printf("\n4. Insert Node at End");   
        printf("\n5. Insert Node in Before a Data");
        printf("\n6. Delete Node at Beginning");
        printf("\n7. Delete Node at End");
        printf("\n8. Delete Node at position");
        printf("\n9. To Stop");
        printf("\nEnter Option: ");
        scanf("%d",&option);
        switch(option){
            case 1:start=create_ll(start); 
            printf("List Created\n");
            break;
            case 2:start=display_ll(start);
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
            case 8:start=delete_atpos(start);
            break;
        }
    }while(option!=9);
    return 0;
}
struct node *create_ll(struct node *start){
    struct node *newnode,*ptr;
    int num;
    printf("Enter -1 to End\n");
    printf("Enter the Data: ");
    scanf("%d",&num);
    while(num!=-1){
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=num;
        if(start==NULL){
            newnode->next=newnode;
            start=newnode;
        }
        else{
            ptr=start;
            while(ptr->next!=start){
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->next=start;
        }
        printf("Enter the Data: ");
        scanf("%d",&num);
    }
    return start;
}
struct node *display_ll(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=start){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
    return start;
}
struct node *insert_beginning(struct node *start){
    struct node *newnode,*ptr;
    int num;
    printf("Enter the Data: ");
    scanf("%d",&num);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    ptr=start;
    while(ptr->next!=start)
        ptr=ptr->next;
    ptr->next=newnode;
    newnode->next=start;
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
    while(ptr->next!=start){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->next=start;
    return start;
}
struct node *insert_before(struct node *start){
    struct node *newnode,*ptr,*preptr;
    int num,var;
    printf("\nEnter the Data: ");
    scanf("%d",&num);
    printf("\nEnter the value before where the data has to be inserted: ");
    scanf("%d",&var);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    ptr=start;
    while(ptr->data!=var){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=newnode;
    newnode->next=ptr;
    return start;
}   
struct node *delete_beginning(struct node *start){
    struct node *ptr;  
        ptr = start;   
        while(ptr -> next != start)  
            ptr = ptr -> next;   
        ptr->next = start->next;  
        free(start);  
        start= ptr->next;  
        printf("\nNode Deleted\n");   
    return start;
}
struct node *delete_end(struct node *start){
    struct node *ptr,*preptr;
    ptr=start;
    while(ptr->next!=start){
        preptr=ptr;
        ptr=ptr->next; 
    }
    preptr->next=start;
    free(ptr);
    return start;
}
struct node *delete_atpos(struct node *start){
    struct node *ptr,*preptr;
    int num;
    printf("Enter the value before where the data has to be deleted: ");
    scanf("%d",&num);
    ptr=start;
    while(ptr->data!=num){
        preptr=ptr;
        ptr=preptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    return start;
}
