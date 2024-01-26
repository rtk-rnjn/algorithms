#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insert_data(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation of temp node failed.\n");
        exit(1);
    }

    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *temp1 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }

    return head;
}

void f_list(struct node *head)
{
    while (head != NULL)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}

void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {

        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }

    printf("nil\n");
}

void delete_node(struct node *node)
{
    struct node *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    free(temp);
}

void delete_node_at(struct node *head, int index)
{
    struct node *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    struct node *temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
}

int main()
{
    struct node *head = NULL;
    for (int i = 0; i < 5; i++)
    {
        head = insert_data(head, i);
    }

    display(head);
    delete_node(head->next->next);

    display(head);
    delete_node_at(head, 3);

    display(head);
    f_list(head);

    return 0;
}
