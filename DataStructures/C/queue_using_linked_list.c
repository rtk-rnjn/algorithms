#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 10

int SIZE = 0;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

bool is_empty()
{
    return front == NULL;
}

bool is_full()
{
    return SIZE == MAX_SIZE;
}

void enqueue(int data)
{
    if (is_full())
    {
        printf("Queue is full\n");
        return;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (is_empty())
    {
        front = new_node;
        rear = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
    }

    SIZE++;
}

int dequeue()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return -1;
    }

    struct Node *temp = front;
    int data = temp->data;
    front = front->next;
    free(temp);

    SIZE--;

    return data;
}

int peek()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return -1;
    }

    return front->data;
}

int queue_size()
{
    return SIZE;
}

void print_queue()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return;
    }

    struct Node *temp = front;

    printf("Queue [%d]: ", queue_size());

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
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

    for (int i = 1; i <= 3; i++)
    {
        printf("Dequeued: %d\n", dequeue());
    }

    print_queue();

    for (int i = 6; i <= 14; i++)
    {
        printf("Enqueued: %d\n", i);
        enqueue(i);
    }

    print_queue();

    printf("Peeked: %d\n", peek());

    return 0;
}
