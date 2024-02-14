#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *TOP = NULL;
int SIZE = 0;
const int MAX_SIZE = 10;

int push(int element)
{
    if (SIZE == MAX_SIZE)
    {
        printf("Stack Overflow\n");
        return -1;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = element;
    new_node->next = TOP;
    TOP = new_node;
    SIZE++;

    return 0;
}

int pop()
{
    if (SIZE == 0)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node *temp = TOP;
    TOP = TOP->next;
    int popped = temp->data;
    free(temp);
    SIZE--;

    return popped;
}

int peek()
{
    if (SIZE == 0)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    return TOP->data;
}

void display()
{
    if (SIZE == 0)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("The stack is: ");
    struct Node *temp = TOP;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int size()
{
    return SIZE;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        push(i);
    }

    display();
    printf("The size of the stack is: %d\n", size());
    printf("Top element: %d\n", peek());

    for (int i = 0; i < 5; i++)
    {
        printf("Popped: %d\n", pop());
    }

    display();
    printf("The size of the stack is: %d\n", size());
    printf("Top element: %d\n", peek());

    return 0;
}
