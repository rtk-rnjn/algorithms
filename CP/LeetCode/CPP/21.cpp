// 21. Merge Two Sorted Lists

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
        {
            return list2;
        }
        else if (list2 == NULL)
        {
            return list1;
        }
        ListNode *p1 = list1, *p2 = list2;
        ListNode *head;
        ListNode *p0;
        if (list1->val < list2->val)
        {
            head = list1;
            p1 = p1->next;
        }
        else
        {
            head = list2;
            p2 = p2->next;
        }
        p0 = head;
        while (p1 && p2)
        {
            if (int(p1->val) >= int(p2->val))
            {
                p0->next = p2;
                p0 = p2;
                p2 = p2->next;
            }
            else if (p1->val < p2->val)
            {
                p0->next = p1;
                p0 = p1;
                p1 = p1->next;
            }
        }

        if (p1 == NULL)
        {
            p0->next = p2;
        }
        else if (p2 == NULL)
        {
            p0->next = p1;
        }
        return head;
    }
};

void free_list(ListNode *head)
{
    ListNode *p = head;
    while (p)
    {
        ListNode *temp = p;
        p = p->next;

        delete temp;
    }
}

void display(ListNode *head)
{
    ListNode *temp = head;
    while (temp)
    {
        cout << "[" << temp << " " << temp->val << " -> " << temp->next << "] -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    Solution s;
    ListNode *list1 = new ListNode(1);
    ListNode *list2 = new ListNode(2);
    ListNode *list3 = new ListNode(3);
    ListNode *list4 = new ListNode(1);
    ListNode *list5 = new ListNode(2);
    ListNode *list6 = new ListNode(3);

    list1->next = list2;
    list2->next = list3;
    list4->next = list5;
    list5->next = list6;
    ListNode *mergedHead = s.mergeTwoLists(list1, list4);

    // display(mergedHead);

    ListNode *temp = mergedHead;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    free_list(mergedHead);

    return 0;
}
