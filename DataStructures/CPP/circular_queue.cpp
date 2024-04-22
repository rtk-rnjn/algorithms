#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class circular_queue
{
public:
    int size;
    int front = 0;
    int rear = 0;
    vector<T> array;

    circular_queue(int size)
    {
        this->size = size + 1;
        this->array = vector<T>(this->size);
    }

    bool is_empty() const
    {
        return this->front == this->rear;
    }

    bool is_full() const
    {
        return (this->rear + 1) % this->size == this->front;
    }

    void enqueue(int element)
    {
        if (this->is_full())
        {
            cout << "Queue is full\n";
            return;
        }

        this->array[this->rear] = element;
        this->rear = (this->rear + 1) % this->size;
    }

    T dequeue()
    {
        if (this->is_empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }

        int element = this->array[this->front];
        this->front = (this->front + 1) % this->size;

        return element;
    }

    T peek()
    {
        if (this->is_empty()) {
            cout << "Queue is empty\n";
        }
        return this->array[this->front];
    }

    int real_size()
    {
        if (this->is_empty()) {
            return 0;
        }

        if (this->is_full()) {
            return this->size;
        }

        int size = (this->front < this->rear) ? this->rear - this->front : this->size - this->front + this->rear;
        return size;
    }

    void display()
    {
        if (this->is_empty())
        {
            cout << "Queue is empty\n";
            return;
        }

        for (int i = this->front; i != this->rear; i = (i + 1) % this->size)
        {
            cout << this->array[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    circular_queue<int> queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    queue.display();

    cout << "Dequeue: " << queue.dequeue() << endl;
    cout << "Dequeue: " << queue.dequeue() << endl;

    queue.display();

    cout << "Peek: " << queue.peek() << endl;

    cout << "Queue size: " << queue.real_size() << endl;

    return 0;
}
