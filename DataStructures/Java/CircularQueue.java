import java.util.ArrayList;

class CircularQueue {
    private ArrayList<Integer> queue;
    private int front = 0;
    private int rear = 0;

    private final int MAX_SIZE;

    CircularQueue(final int size) {
        this.MAX_SIZE = size;
        this.queue = new ArrayList<Integer>(MAX_SIZE);
    }

    public void enqueue(final int data) {
        if (this.isFull()) {
            System.out.println("Queue is full");
            return;
        }

        queue.add(rear, data);
        rear = (rear + 1) % MAX_SIZE;
    }

    public int dequeue() {
        if (this.isEmpty()) {
            System.out.println("Queue is empty");
            return -1;
        }

        int data = queue.get(front);
        front = (front + 1) % MAX_SIZE;
        return data;
    }

    public boolean isEmpty() {
        return front == rear;
    }

    public boolean isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    public void print() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return;
        }

        for (int i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            System.out.print(queue.get(i) + " ");
        }
        System.out.println();
    }
}
