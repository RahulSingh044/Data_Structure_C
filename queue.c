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

int search(int target) {
    for(int i=front; i<=rear; i++) {
        if(queue[i] == target) {
            return i;
        }
    }
    return -1;
}

void traverse() {
    for(int i=front; i<=rear; i++) {
        printf("%d\t",queue[i]);
    }
}

int main() {
    int n;
   enqueue(10);
   enqueue(20);
   enqueue(30);
   dequeue();
   traverse();
   printf("\nEnter the element to be searched in queue: \t");
   scanf("%d",&n);
   int result = search(n);
   if(result != -1) {
       printf("Element is found at index %d",result);
   }
   else
    printf("Element is not in the queue");
}
