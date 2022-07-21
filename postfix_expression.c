#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int stack[10];
int top=-1;

void push(int x){
    stack[++top]=x; //Pushes data into the Stack
}
int pop(){
    return stack[top--];  //Pops data from the Stack
}
int main(){
    char expression[20],*e;
    int n1,n2,n3,num;
    printf("Enter the Expression: ");
    scanf("%s",expression);
    e=expression;
    while(*e!='\0'){
        if(isdigit(*e)){
            num=*e-48;  //To convert the data from ASCII to a integer type
            push(num);
        }
        else{
          //When a character is encountered Pop two elements
            n1=pop();
            n2=pop();
            switch(*e){
                case '+':n3=n1+n2;
                break;
                case '-':n3=n2-n1;
                break;
                case '/':n3=n2/n1;
                break;
                case '*':n3=n2*n1;
                break;
            }
            push(n3);
        }
        e++;
    }
    printf("The Result of the Expression %s is %d",expression,pop());
    return 0;
}
