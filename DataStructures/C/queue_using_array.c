#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

int QUEUE[SIZE];

int front = 0;
int rear = 0;

bool is_empty()
{
    return front == rear;
}

bool is_full()
{
    return rear == SIZE;
}

void enqueue(int data)
{
    if (is_full())
    {
        printf("Queue is full\n");
        return;
    }

    QUEUE[rear++] = data;
}

int dequeue()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return -1;
    }

    return QUEUE[front++];
}

int peek()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return -1;
    }

    return QUEUE[front];
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

    return rear - front;
}

void print_queue()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue [%d]: ", queue_size());
    for (int i = front; i < rear; i++)
    {
        printf("%d ", QUEUE[i]);
    }
    printf("\n");
}

int main()
{
    print_queue();

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    print_queue();

    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());
    print_queue();

    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    print_queue();

    enqueue(11);
    print_queue();

    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());
    printf("Dequeue: %d\n", dequeue());

    print_queue();
}
