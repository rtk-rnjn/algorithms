import java.util.ArrayList;

class Stack {
    private int top = 0;
    private final int maxSize;

    private ArrayList<Integer> stack;

    Stack(final int size) {
        this.maxSize = size;
        this.stack = new ArrayList<Integer>(this.maxSize);
    }

    public void push(final int value) {
        if (this.top == this.maxSize) {
            System.out.println("Stack Overflow");
            return;
        }

        this.stack.add(this.top, value);
        this.top++;
    }

    public int pop() {
        if (this.top == 0) {
            System.out.println("Stack Underflow");
            return -1;
        }

        this.top--;
        return this.stack.remove(this.top);
    }

    public int peek() {
        if (this.top == 0) {
            System.out.println("Stack Underflow");
            return -1;
        }

        return this.stack.get(this.top - 1);
    }

    public boolean isEmpty() {
        return this.top == 0;
    }

    public boolean isFull() {
        return this.top == this.maxSize;
    }

    public void print() {
        System.out.print("Stack: ");
        for (int i = 0; i < this.top; i++) {
            System.out.print(this.stack.get(i) + " ");
        }
        System.out.println();
    }

    public static void main(final String[] args) {
        Stack stack = new Stack(5);

        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.print(); // Output: 1 2 3 4

        stack.push(5);
        stack.print(); // Output: 1 2 3 4 5

        stack.push(6); // Output: Stack Overflow
        stack.print(); // Output: 1 2 3 4 5

        System.out.println("Peek: " + stack.peek()); // Output: 5
        stack.print(); // Output: 1 2 3 4 5

        System.out.println("Pop: " + stack.pop()); // Output: 5
        stack.print(); // Output: 1 2 3 4
    }
}
