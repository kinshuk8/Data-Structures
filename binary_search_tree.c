#include<stdio.h>
#include<stdlib.h>

typedef struct binary_search_tree{
    int data;
    struct binary_search_tree *left,*right;
}bst;

bst *create(int data){
    bst *node=(bst *)malloc(sizeof(bst));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

bst *insert(bst *root,int data){
    if(root==NULL){
        return create(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

bst *search(bst *root,int data){
    if(root==NULL || root->data==data){
        return root;
    }
    else if(root->data<data){
        return search(root->right,data);
    }
    else if(root->data>data){
        return search(root->left,data);
    }
}

//To find the Inorder Successor
bst *min_value_node(bst *root){
    bst *cur=root;
    while(cur && cur->left!=NULL){
        cur=cur->left;
    }
    return cur;
}

bst *delete_node(bst* root,int data){
    if(root==NULL){
        return root;
    }
    if(data<root->data){
        root->left=delete_node(root->left,data);
    }
    else if(data>root->data){
        root->right=delete_node(root->right,data);
    }
    else{
        //with only one child or no child
        if(root->left==NULL){
            bst *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            bst *temp=root->left;
            free(root);
            return temp;
        }
        //node with two children
        //find in_order successor
        bst *temp=min_value_node(root->right);
        root->data=temp->data;
        root->right=delete_node(root->right,temp->data);
    }
    return root;
}
void in_order(bst *root){
    if(root!=NULL){
        in_order(root->left);
        printf("%d\t",root->data);
        in_order(root->right);
    }
};
void pre_order(bst *root){
    if(root!=NULL){
        printf("%d\t",root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}
void post_order(bst *root){
    if(root!=NULL){
        post_order(root->left);
        post_order(root->right);
        printf("%d\t",root->data);
    }
}
int main(){
    int data,choice;
    bst *root=NULL;
    do{
        printf("\n1. Create Binary Tree");
        printf("\n2. Inorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Postorder Traversal");
        printf("\n5. Delete Node");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the Data: ");
            scanf("%d",&data);
            root=insert(root,data);
            break;
            case 2:in_order(root);
            break;
            case 3:pre_order(root);
            break;
            case 4:post_order(root);
            break;
            case 5:printf("Enter the Data to be Deleted: ");
            scanf("%d",&data);
            root=delete_node(root,data);
            break;
        }
    }while(choice!=6);
    return 0;
}
