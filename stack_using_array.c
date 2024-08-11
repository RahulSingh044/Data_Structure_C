#include<stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if(top == MAX-1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() { 
    if(top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if(top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

void display(){
    if(top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    for(int i=top; i>=0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    pop();
    pop();
    printf("The value at top is %d", peek());
    printf("\n");
    display();

}
