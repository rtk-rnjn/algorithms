#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void insert_at_last(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    if (head == NULL)
    {
        new_node->data = data;
        new_node->next = new_node;
        new_node->prev = new_node;
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->data = data;
        new_node->next = head;
        new_node->prev = tail;
        tail->next = new_node;
        head->prev = new_node;
        tail = new_node;
    }
}

void insert_at_first(int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = data;

    new_node->next = head;
    new_node->prev = tail;

    head->prev = new_node;
    tail->next = new_node;

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
    while (temp->data != data)
    {
        temp = temp->next;
        if (temp == head)
        {
            printf("Data not found\n");
            return;
        }
    }
    if (temp == head)
    {
        head = head->next;
    }
    if (temp == tail)
    {
        tail = tail->prev;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void display()
{
    struct Node *temp = head;
    do
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        insert_at_last(i);
    }
    display();

    for (int i = 10; i < 20; i++)
    {
        insert_at_first(i);
    }
    display();

    delete_node(19);

    display();

    delete_node(-5);

    display();

    return 0;
}