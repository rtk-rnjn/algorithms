#include <iostream>
#include <vector>

using namespace std;

class Stack
{
public:
    int size;
    int top = -1;
    vector<int> stack;

    explicit Stack(int n)
    {
        this->size = n;
    }

    int push(int element)
    {
        if (this->top == this->size - 1)
        {
            cout << ("Stack Overflow\n");
            return -1;
        }

        this->top++;
        this->stack.push_back(element);

        return 0;
    }

    int pop()
    {
        if (this->top == -1)
        {
            cout << ("Stack Underflow\n");
            return -1;
        }

        this->top--;

        return 0;
    }

    int peek()
    {
        if (this->top == -1)
        {
            cout << ("Stack Underflow\n");
            return -1;
        }

        return this->stack[top];
    }

    void display()
    {
        if (this->top == -1)
        {
            cout << ("Stack Underflow\n");
            return;
        }

        cout << ("The stack is: ");
        for (int i = 0; i <= this->top; i++)
        {
            cout << (this->stack[i]) << " ";
        }
        cout << ("\n");
    }
};

int main()
{
    Stack s = Stack(5);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();

    cout << s.peek() << endl;
    s.display();

    return 0;
}
