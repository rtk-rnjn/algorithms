// 2. Add Two Numbers

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *result = NULL;
    struct ListNode *temp = NULL;
    struct ListNode *prev = NULL;
    int carry = 0;
    int sum;

    while (l1 != NULL || l2 != NULL)
    {
        sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = sum;
        temp->next = NULL;

        if (result == NULL)
        {
            result = temp;
        }
        else
        {
            prev->next = temp;
        }
        prev = temp;

        if (l1)
        {
            l1 = l1->next;
        }
        if (l2)
        {
            l2 = l2->next;
        }
    }

    if (carry > 0)
    {
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = carry;
        temp->next = NULL;
        prev->next = temp;
    }

    return result;
}

void display(struct ListNode *head)
{
    struct ListNode *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

void free_list(struct ListNode *head)
{
    struct ListNode *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        free(head);
        head = temp;
    }
}

int main()
{
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
    struct ListNode *result = NULL;

    l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->val = 2;
    l1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->next->val = 4;
    l1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->next->next->val = 3;
    l1->next->next->next = NULL;

    l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->val = 5;
    l2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->next->val = 6;
    l2->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->next->next->val = 4;
    l2->next->next->next = NULL;

    result = addTwoNumbers(l1, l2);
    display(result);

    free_list(l1);
    free_list(l2);
    free_list(result);

    return 0;
}
