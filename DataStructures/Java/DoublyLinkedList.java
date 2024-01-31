public class DoublyLinkedList {
    static class Node {
        int data;
        Node next;
        Node prev;

        public Node(int d) {
            this.data = d;
            this.next = null;
            this.prev = null;
        }
    }

    private Node head;
    private Node tail;

    public DoublyLinkedList() {
        this.head = null;
        this.tail = null;
    }

    public void insertAtLast(int d) {
        Node newNode = new Node(d);
        if (this.head == null) {
            this.head = newNode;
            this.tail = newNode;
            return;
        }
        this.tail.next = newNode;
        newNode.prev = this.tail;
        this.tail = newNode;
    }

    public void insertAtFirst(int d) {
        Node newNode = new Node(d);
        newNode.next = this.head;
        this.head.prev = newNode;
        this.head = newNode;
    }

    public void insertAfter(int d, int after) {
        Node newNode = new Node(d);
        Node temp = this.head;
        while (temp != null) {
            if (temp.data == after) {
                newNode.next = temp.next;
                newNode.prev = temp;
                temp.next = newNode;
                return;
            }
            temp = temp.next;
        }
    }

    public void print() {
        Node temp = this.head;
        while (temp != null) {
            System.out.print(temp.data + " <-> ");
            temp = temp.next;
        }
        System.out.println("null");
    }

    public void delete(int d) {
        if (this.head == null) {
            return;
        }
        if (this.head.data == d) {
            this.head = this.head.next;
            this.head.prev = null;
            return;
        }
        Node temp = this.head;
        while (temp.next != null) {
            if (temp.next.data == d) {
                temp.next = temp.next.next;
                if (temp.next != null) {
                    temp.next.prev = temp;
                }
                return;
            }
            temp = temp.next;
        }
    }

    public static void main(String[] args) {
        DoublyLinkedList dll = new DoublyLinkedList();
        for (int i : new int[] { 1, 2, 3, 4, 5 }) {
            dll.insertAtLast(i);
        }
        dll.print();
    }
}
