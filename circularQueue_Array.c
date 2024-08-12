#include<stdio.h>
#define size 10

int queue[size];
int front = -1;
int rear = -1;

void enqueue(int data){
    if((rear+1)%size == front){
        printf("Queue is full\n");
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear = (rear+1)%size;
    queue[rear] = data;
}

void dequeue(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued element is %d\n", queue[front]);
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front = (front+1)%size;
    }
}

void display(){
    for(int i = front; i<= rear; i++){
        printf("%d ", queue[i]);
    }
}

void main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    dequeue();
    display();
}
