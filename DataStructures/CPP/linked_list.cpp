#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void pushAtFirst(Node **head, int newData)
{
    Node *p = new Node();
    if (p == NULL)
    {
        cout << "Memory Allocation Failed";
        exit(1);
    }

    p->data = newData;
    p->next = *head;
    *head = p;
}

void pushAtLast(Node **head, int newData)
{
    Node *p = new Node();
    if (p == NULL)
    {
        cout << "Memory Allocation Failed";
        exit(1);
    }

    p->data = newData;
    p->next = NULL;
    Node *ptr = *head;
    while ((ptr)->next != NULL)
    {
        ptr = (ptr)->next;
    }
    (ptr)->next = p;
}

void insertAt(Node **head, int index, int newData)
{
    Node *p = new Node();
    if (p == NULL)
    {
        cout << "Memory Allocation Failed";
        exit(1);
    }
    p->data = newData;
    Node *ptr = *head;
    if (index == 1)
    {
        pushAtFirst(&(*head), newData);
    }
    else
    {
        for (int i = 2; i < index; i++)
        {
            if (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
        }
        p->next = ptr->next;
        ptr->next = p;
    }
}

int popAtEnd(Node **head)
{
    Node *ptr = *head;
    while (ptr->next->next)
    {
        ptr = ptr->next;
    }
    int data = ptr->next->data;
    ptr->next = NULL;
    free(ptr->next);

    return data;
}

int popAtFirst(Node **head)
{
    Node *ptr = *head;
    int data = (*head)->data;
    *head = (*head)->next;
    free(ptr);
    return data;
}

int deleteAtIndex(Node **head, int index)
{
    Node *ptr = *head;
    for (int i = 1; i < index - 1; i++)
    {
        if (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
    }
    int data = ptr->next->data;
    Node *p = ptr->next;
    ptr->next = ptr->next->next;
    free(p);
    return data;
}

void deleteList(Node **head)
{
    Node *ptr = *head;
    while ((*head) != NULL)
    {
        free(ptr);
        *head = (*head)->next;
        ptr = *head;
    }
}

void transversal(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}
int main()
{
    Node *head = new Node();
    head->data = 1;
    head->next = NULL;
    pushAtFirst(&head, 2);
    pushAtLast(&head, 3);
    pushAtLast(&head, 4);
    pushAtLast(&head, 5);
    insertAt(&head, 1, 6);
    popAtEnd(&head);
    popAtFirst(&head);
    deleteAtIndex(&head, 2);
    transversal(head);
    deleteList(&head);
}