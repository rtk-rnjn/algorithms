import java.util.ArrayList;

class Queue {
    private static final int SIZE = 10;
    private static ArrayList<Integer> queue = new ArrayList<>(SIZE);
    private static int front = 0;
    private static int rear = 0;

    private static boolean isEmpty() {
        return front == rear;
    }

    private static boolean isFull() {
        return rear == SIZE;
    }

    private static void enqueue(final int data) {
        if (isFull()) {
            System.out.println("Queue is full");
            return;
        }
        queue.add(rear++, data);
    }

    private static int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return -1;
        }
        return queue.get(front++);
    }

    private static int peek() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return -1;
        }
        return queue.get(front);
    }

    private static void printQueue() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return;
        }
        System.out.print("Queue: ");
        for (int i = front; i < rear; i++) {
            System.out.print(queue.get(i) + " ");
        }
        System.out.println();
    }

    public static void main(final String[] args) {
        printQueue();

        for (int i = 1; i <= 5; i++) {
            enqueue(i);
        }

        printQueue();

        System.out.println("Dequeue: " + dequeue());
        System.out.println("Dequeue: " + dequeue());
        printQueue();

        for (int i = 6; i <= 10; i++) {
            enqueue(i);
        }

        printQueue();

        enqueue(11);
        printQueue();

        System.out.println("Peek: " + peek());
        printQueue();

        for (int i = 0; i < 5; i++) {
            System.out.println("Dequeue: " + dequeue());
        }
        printQueue();

        for (int i = 0; i < 3; i++) {
            System.out.println("Dequeue: " + dequeue());
        }

        printQueue();
        enqueue(1);
        enqueue(2);
        printQueue();
    }
}
