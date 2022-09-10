//C program to implement recursive Binary Search

#include<stdio.h>
#define MAX 50

void createArray(int arr[MAX],int size){
  printf("Enter the Elements: ");
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

int binarySearch(int arr[MAX],int element,int low,int high){
  if(low>high){
    return -1;
  }
  else{
    int mid=(low+high)/2;
    if(element==arr[mid]){
      return mid;
    }
    else if(element<arr[mid]){              //Element is on the Left Side
      binarySearch(arr,element,0,mid-1);
    }
    else{
      binarySearch(arr,element,mid+1,high); //Element is on the Right Side
    }
  }
}

int main(){
  int size,arr[MAX],element;
  printf("Enter the Number of Elements: ");
  scanf("%d",&size);
  createArray(arr,size);
  printf("Enter the Element: ");
  scanf("%d",&element);
  int result=binarySearch(arr,element,0,size-1);
  (result==-1)?printf("%d is not Found\n",element):printf("%d is Fount at Index %d",element,result);
  return 0;
}
