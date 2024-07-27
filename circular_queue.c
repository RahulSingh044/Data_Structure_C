#include <stdio.h>
#include <stdlib.h>

typedef struct circularQueueNode
{
    int size;
    int front;
    int rear;
    int *arr;
} QueueN;

void enqueue(QueueN *q, int value)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is Full");
        return;
    }

    if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
    }
    q->arr[q->rear] = value;
}

void dequeue(QueueN *q)
{
    if (q->front == q->rear)
    {
        printf("Queue is empty");
        return;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
    }
}

void display(QueueN *q)
{
    int i = q->front;
    if (q->front == q->rear)
    {
        return;
    }
    printf("\nThe circular queue is \n");
    while (i != q->rear)
    {
        printf("%d->", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("%d", q->arr[i]);
}

void main()
{
    QueueN *q;
    q->size = 5;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    enqueue(q, 10);
    enqueue(q, 8);
    enqueue(q, 15);
    enqueue(q, 12);
    enqueue(q, 20);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    display(q);
}
