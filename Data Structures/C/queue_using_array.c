#include <stdio.h>

#define SIZE 100

int QUEUE[SIZE];

int FRONT = -1;
int REAR = -1;

int insert(int element)
{
    if (REAR == SIZE - 1)
    {
        printf("Queue Overflow\n");
        return -1;
    }
    else
    {
        if (FRONT == -1)
        {
            FRONT = 0;
        }
        REAR++;
        QUEUE[REAR] = element;
    }

    return 0;
}

int delete()
{
    if (FRONT == -1 || FRONT > REAR)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        FRONT++;
    }

    return 0;
}

int peek()
{
    if (FRONT == -1 || FRONT > REAR)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        return QUEUE[FRONT];
    }
}

void display()
{
    if (FRONT == -1 || FRONT > REAR)
    {
        printf("Queue Underflow\n");
        return;
    }
    else
    {
        printf("The queue is: ");
        for (int i = FRONT; i <= REAR; i++)
        {
            printf("%d ", QUEUE[i]);
        }
        printf("\n");
    }
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        insert(i);
    }

    printf("The front element is: %d\n", peek());

    for (int i = 0; i < 5; i++)
    {
        delete();
    }

    display();

    return 0;
}
