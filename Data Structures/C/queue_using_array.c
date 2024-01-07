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
    int choice, element;

    while (1 == 1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &element);
            insert(element);
            break;
        case 2:
            delete ();
            break;
        case 3:
            printf("The front element is: %d\n", peek());
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
