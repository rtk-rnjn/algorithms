class DoublyCircularLinkedList {
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

    private Node head = null;
    private Node tail = null;

    public final void insertAtLast(final int data) {
        Node newNode = new Node(data);
        if (this.head == null) {
            this.head = newNode;
            this.tail = newNode;
            this.head.next = this.head;
            this.head.prev = this.head;
            return;
        }
        this.tail.next = newNode;
        newNode.prev = this.tail;
        newNode.next = this.head;
        this.head.prev = newNode;
        this.tail = newNode;
    }

    public final void insertAtFirst(final int data) {
        Node newNode = new Node(data);
        newNode.next = this.head;
        newNode.prev = this.tail;
        this.head.prev = newNode;
        this.tail.next = newNode;
        this.head = newNode;
    }

    public final void insertAfter(final int data, final int after) {
        Node newNode = new Node(data);
        Node temp = this.head;
        while (temp != null) {
            if (temp.data == after) {
                newNode.next = temp.next;
                newNode.prev = temp;
                temp.next.prev = newNode;
                temp.next = newNode;
                return;
            }
            temp = temp.next;
        }
    }

    public final void delete(final int data) {
        if (this.head == null) {
            return;
        }
        if (this.head.data == data) {
            this.head = this.head.next;
            this.head.prev = this.tail;
            this.tail.next = this.head;
            return;
        }
        Node temp = this.head;
        while (temp != null) {
            if (temp.data == data) {
                temp.prev.next = temp.next;
                temp.next.prev = temp.prev;
                return;
            }
            temp = temp.next;
        }
    }

    public final void delete(final Node node) {
        if (this.head == null) {
            return;
        }
        if (this.head == node) {
            this.head = this.head.next;
            this.head.prev = this.tail;
            this.tail.next = this.head;
            return;
        }
        Node temp = this.head;
        while (temp != null) {
            if (temp == node) {
                temp.prev.next = temp.next;
                temp.next.prev = temp.prev;
                return;
            }
            temp = temp.next;
        }
    }

    public final void print() {
        Node temp = this.head;
        do {
            System.out.print(temp.data + " <-> ");
            temp = temp.next;
        } while (temp != this.head);
    }

    public static void main(final String[] args) {
        CircularLinkedList list = new CircularLinkedList();
        list.insertAtLast(1);
        list.insertAtLast(2);
        list.insertAtLast(3);
        list.insertAtLast(4);
        list.insertAtLast(5);
        list.insertAtFirst(0);
        list.insertAfter(6, 5);
        list.print();
    }
}
