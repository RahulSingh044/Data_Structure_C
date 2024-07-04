#include <stdio.h>
#define MAX 3
int queue[MAX];
int rear = -1;
int front = -1;

void enqueue(int value) {
    if(rear >= MAX-1) {
        printf("Queue is overflow\n");
        return;
    }
    else{
        if(front == -1) {
            front = 0;
        }
        queue[++rear] = value;
        printf("The enqueued element in queue is %d\n",value);
    }
}

int dequeue() {
    if(front == -1) {
        printf("Queue is underflow");
        return -1;
    }
    else {
        printf("The dequeued element is %d \n", queue[front++]);
        if(front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

int main() {
   enqueue(10);
   enqueue(20);
   enqueue(30);
   dequeue();
   dequeue();
   dequeue();
   dequeue();
}
