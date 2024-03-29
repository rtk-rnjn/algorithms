#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void insert_data(Node *head, int data)
{
    Node *temp = new Node();
    if (temp == nullptr)
    {
        cout << ("Memory allocation of temp node failed.\n");
        exit(1);
    }

    temp->data = data;
    temp->next = nullptr;

    if (head == nullptr)
    {
        head = temp;
    }
    else
    {
        Node *temp1 = head;
        while (temp1->next != nullptr)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
}

void f_list(Node *head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;

        delete temp;
    }
}

void delete_node(Node *node)
{
    Node *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;

    delete temp;
}

void delete_node_at(Node *head, int index)
{
    Node *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }
    Node *temp1 = temp->next;
    temp->next = temp1->next;

    delete temp1;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << "[" << temp->data << "] ->";
        temp = temp->next;
    }

    cout << ("nil\n");
}

int main()
{
    Node *a = new Node();
    Node *b = new Node();
    Node *c = new Node();
    Node *d = new Node();

    a->data = 1;
    b->data = 2;
    c->data = 3;
    d->data = 4;

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = nullptr;
    insert_data(a, 5);
    delete_node(b);
    delete_node_at(a, 2);

    display(a);
    f_list(a);
}
