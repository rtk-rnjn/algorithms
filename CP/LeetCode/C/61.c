// 61. Rotate List

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode *temp = head;
    int len = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        len++;
    }
    temp->next = head;
    k = k % len;
    k = len - k;
    while (k--)
    {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}

void free_list(struct ListNode *head)
{
    struct ListNode *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
}

int main()
{
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;

    int k = 2;
    head = rotateRight(head, k);
    struct ListNode *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    free(temp);
    free_list(head);
    return 0;
}
