#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void insert_at_last(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    if (head == NULL)
    {
        new_node->data = data;
        new_node->next = new_node;
        new_node->prev = new_node;
        head = new_node;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        new_node->data = data;
        new_node->next = head;
        new_node->prev = temp;
        temp->next = new_node;
        head->prev = new_node;
    }
}

void insert_at_first(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = data;

    new_node->next = head;
    new_node->prev = head->prev;

    head->prev->next = new_node;
    head->prev = new_node;

    head = new_node;
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

    if (head->data == data)
    {
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        free(temp);
        return;
    }

    while (temp->next != head)
    {
        if (temp->data == data)
        {
            prev->next = temp->next;
            temp->next->prev = prev;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (temp->data == data)
    {
        prev->next = head;
        head->prev = prev;
        free(temp);
        return;
    }

    printf("Element not found\n");
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
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main()
{
    insert_at_last(10);
    insert_at_last(20);
    insert_at_last(30);
    insert_at_last(40);
    insert_at_last(50);
    display();

    insert_at_first(5);
    display();

    delete_node(5);
    display();

    delete_node(30);
    display();

    delete_node(50);
    display();

    delete_node(100);
    display();

    return 0;
}