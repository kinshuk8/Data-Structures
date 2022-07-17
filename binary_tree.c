#include<stdio.h>
#include<stdlib.h>

typedef struct binary_tree{
    int data;
    struct binary_tree *left,*right;
}tree;

//To Create a Node and to get Left and Right Childs
tree *create(){
    int data;
    tree *newnode=(tree *)malloc(sizeof(tree));
    printf("\nEnter -1 to End");
    printf("\nEnter the Data: ");
    scanf("%d",&data);
    newnode->data=data;
    if(data==-1)    return 0;
    printf("Enter the left child of %d: ",data);
    newnode->left=create();
    printf("Enter the Right Child of %d: ",data);
    newnode->right=create();
    return newnode;
}

//For Inorder Traversal of Binary Tree
void in_order(tree *root){
    if(root!=NULL){
        in_order(root->left);
        printf("%d\t",root->data);
        in_order(root->right);
    }
}

//For Preorder Traversal of Binary Tree
void pre_order(tree *root){
    if(root!=NULL){
        printf("%d\t",root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

//For Postorder Traversal of Binary Tree
void post_order(tree *root){
    if(root!=NULL){
        post_order(root->left);
        post_order(root->right);
        printf("%d\t",root->data);
    }
}

int main(){
    int choice;
    tree *root=NULL;
    do{
        printf("\n1. Create Binary Tree");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:root=create();
            break;
            case 2:in_order(root);
            break;
            case 3:pre_order(root);
            break;
            case 4:post_order(root);
            break;
        }
    }while(choice!=5);
    return 0;
}
