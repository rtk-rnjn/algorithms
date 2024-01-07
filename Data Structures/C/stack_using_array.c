#include <stdio.h>

#define SIZE 100

int STACK[SIZE];

int TOP = -1;

int push(int element)
{
    if (TOP == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return -1;
    }
    else
    {
        TOP++;
        STACK[TOP] = element;
    }

    return 0;
}

int pop()
{
    if (TOP == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        TOP--;
    }

    return 0;
}

int peek()
{
    if (TOP == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return STACK[TOP];
    }
}

void display()
{
    if (TOP == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    else
    {
        printf("The stack is: ");
        for (int i = 0; i <= TOP; i++)
        {
            printf("%d ", STACK[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, element;

    while (1 == 1)
    {
        printf("0. Display\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            display();
            break;
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("The top element is: %d\n", peek());
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
