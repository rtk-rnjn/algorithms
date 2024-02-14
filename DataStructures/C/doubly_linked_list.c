// Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insert_at_last(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    if (head == NULL)
    {
        new_node->value = data;
        new_node->next = new_node;
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->value = data;
        new_node->next = head;
        tail->next = new_node;
        tail = new_node;
    }
}

void insert_at_first(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->value = data;
    new_node->next = head;
    head = new_node;
    tail->next = head;
}

void delete_node(int data)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    if (head->value == data)
    {
        head = head->next;
        tail->next = head;
        free(temp);
        return;
    }

    while (temp->value != data)
    {
        if (temp->next == head)
        {
            printf("Element not found\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    do
    {
        printf("%d ", temp->value);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{
    insert_at_last(1);
    insert_at_last(2);
    insert_at_last(3);
    insert_at_last(4);
    insert_at_last(5);
    insert_at_first(0);
    delete_node(3);
    display();
    return 0;
}