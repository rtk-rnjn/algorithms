import java.util.ArrayList;

class Stack {
    private int TOP = 0;
    private final int MAX_SIZE;

    private ArrayList<Integer> stack;

    public Stack(int size) {
        this.MAX_SIZE = size;
        this.stack = new ArrayList<Integer>(this.MAX_SIZE);
    }

    public void push(int value) {
        if (this.TOP == this.MAX_SIZE) {
            System.out.println("Stack Overflow");
            return;
        }

        this.stack.add(this.TOP, value);
        this.TOP++;
    }

    public int pop() {
        if (this.TOP == 0) {
            System.out.println("Stack Underflow");
            return -1;
        }

        this.TOP--;
        return this.stack.remove(this.TOP);
    }

    public int peek() {
        if (this.TOP == 0) {
            System.out.println("Stack Underflow");
            return -1;
        }

        return this.stack.get(this.TOP - 1);
    }

    public boolean isEmpty() {
        return this.TOP == 0;
    }

    public boolean isFull() {
        return this.TOP == this.MAX_SIZE;
    }

    public void print() {
        System.out.print("Stack: ");
        for (int i = 0; i < this.TOP; i++) {
            System.out.print(this.stack.get(i) + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Stack stack = new Stack(5);

        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.print();  // Output: 1 2 3 4

        stack.push(5);
        stack.print();  // Output: 1 2 3 4 5

        stack.push(6);  // Output: Stack Overflow
        stack.print();  // Output: 1 2 3 4 5

        System.out.println("Peek: " + stack.peek());  // Output: 5
        stack.print();  // Output: 1 2 3 4 5

        System.out.println("Pop: " + stack.pop());  // Output: 5
        stack.print();  // Output: 1 2 3 4
    }
}
