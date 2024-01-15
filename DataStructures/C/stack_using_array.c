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
    for (int i = 0; i < 10; i++)
    {
        push(i);
    }

    printf("The top element is: %d\n", peek());

    pop();
    pop();

    display();

    return 0;
}
