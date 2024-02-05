public class DoublyLinkedList {
    private Node head;
    private Node tail;

    static class Node {
        // CSOFF: VisibilityModifier
        int data;
        Node next;
        Node prev;
        // CSON: VisibilityModifier

        Node(final int newData) {
            this.data = newData;
            this.next = null;
            this.prev = null;
        }
    }

    public DoublyLinkedList() {
        this.head = null;
        this.tail = null;
    }

    public final void insertAtLast(final int data) {
        Node newNode = new Node(data);
        if (this.head == null) {
            this.head = newNode;
            this.tail = newNode;
            return;
        }
        this.tail.next = newNode;
        newNode.prev = this.tail;
        this.tail = newNode;
    }

    public final void insertAtFirst(final int data) {
        Node newNode = new Node(data);
        newNode.next = this.head;
        this.head.prev = newNode;
        this.head = newNode;
    }

    public final void insertAfter(final int data, final int after) {
        Node newNode = new Node(data);
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

    public final void print() {
        Node temp = this.head;
        while (temp != null) {
            System.out.print(temp.data + " <-> ");
            temp = temp.next;
        }
        System.out.println("null");
    }

    public final void delete(final int data) {
        if (this.head == null) {
            return;
        }
        if (this.head.data == data) {
            this.head = this.head.next;
            this.head.prev = null;
            return;
        }
        Node temp = this.head;
        while (temp.next != null) {
            if (temp.next.data == data) {
                temp.next = temp.next.next;
                if (temp.next != null) {
                    temp.next.prev = temp;
                }
                return;
            }
            temp = temp.next;
        }
    }

    public static void main(final String[] args) {
        DoublyLinkedList dll = new DoublyLinkedList();
        for (int i : new int[] { 1, 2, 3, 4, 5 }) {
            dll.insertAtLast(i);
        }
        dll.print();
    }
}
