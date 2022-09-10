//C code to linearly search an element.

#include<stdio.h>
#define MAX 50

void createArray(int arr[MAX],int size){
    printf("Enter the Elements: \n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
}

void printArray(int arr[MAX],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int search(int arr[MAX],int size,int element){
    for(int i=0;i<size;i++){
        if(element==arr[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int size,arr[MAX],element;
    printf("Enter the Number of Elements: ");
    scanf("%d",&size);
    createArray(arr,size);
    printf("Enter the Element: ");
    scanf("%d",&element);
    int result=search(arr,size,element);
    (result==-1)?printf("%d is not Found\n",element):printf("%d is Found at index %d\n",element,result);
    return 0;
}
