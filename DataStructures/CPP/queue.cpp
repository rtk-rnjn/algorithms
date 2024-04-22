#include <iostream>
#include <vector>

using namespace std;

class queue
{
public:
    int size;
    int front = 0;
    int rear = 0;
    vector<int> array;

    queue(int size)
    {
        this->size = size;
        this->array = vector<int>(size);
    }

    int enqueue(int element)
    {
        if (this->rear == this->size)
        {
            cout << ("Queue Overflow\n");
            return -1;
        }

        this->array[this->rear] = element;
        this->rear++;

        return 0;
    }

    int dequeue()
    {
        if (this->front == this->rear)
        {
            cout << ("Queue Underflow\n");
            return -1;
        }

        this->front++;

        return 0;
    }

    int peek()
    {
        if (this->front == this->rear)
        {
            cout << ("Queue Underflow\n");
            return -1;
        }

        return this->array[this->front];
    }

    void display()
    {
        if (this->front == this->rear)
        {
            cout << ("Queue Underflow\n");
            return;
        }

        for (int i = this->front; i < this->rear; i++)
        {
            cout << this->array[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    cout << q.peek() << endl;

    return 0;
}
