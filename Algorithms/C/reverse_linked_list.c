#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    return head;
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

int main(void)
{
    struct node last = {5, NULL};
    struct node fourth = {4, &last};
    struct node third = {3, &fourth};
    struct node second = {2, &third};
    struct node first = {1, &second};

    struct node *head = &first;

    printf("Before reverse: ");
    display(head);

    struct node *new_head = reverse(head);

    printf("After reverse: ");
    display(new_head);

    return 0;
}
