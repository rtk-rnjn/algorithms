#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

int CIRCULAR_QUEUE[SIZE];

int front = 0;
int rear = 0;

bool is_empty()
{
    return front == rear;
}

bool is_full()
{
    return (rear + 1) % SIZE == front;
}

void enqueue(int data)
{
    if (is_full())
    {
        printf("Queue is full\n");
        return;
    }

    CIRCULAR_QUEUE[rear] = data;
    rear = (rear + 1) % SIZE;
}

int dequeue()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return -1;
    }

    int data = CIRCULAR_QUEUE[front];
    front = (front + 1) % SIZE;
    return data;
}

int peek()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return -1;
    }

    return CIRCULAR_QUEUE[front];
}

int queue_size()
{
    if (is_empty())
    {
        return 0;
    }

    if (is_full())
    {
        return SIZE;
    }

    if (front < rear)
    {
        return rear - front;
    }

    return SIZE - front + rear;
}

void print_queue()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue [%d]: ", queue_size());
    for (int i = front; i != rear; i = (i + 1) % SIZE)
    {
        printf("%d ", CIRCULAR_QUEUE[i]);
    }
    printf("\n");
}

int main()
{
    print_queue();

    for (int i = 1; i <= 5; i++)
    {
        printf("Enqueued: %d\n", i);
        enqueue(i);
    }
    print_queue();

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());
    print_queue();

    for (int i = 6; i <= 10; i++)
    {
        printf("Enqueued: %d\n", i);
        enqueue(i);
    }

    print_queue();

    enqueue(11);
    print_queue();

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    print_queue();

    enqueue(100);
    enqueue(200);
    enqueue(300);
    enqueue(400);

    print_queue();
}