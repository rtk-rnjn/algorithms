class CircularLinkedList {
    static class Node {
        // CSOFF: VisibilityModifier
        int data;
        Node next;
        // CSON: VisibilityModifier

        Node(final int newData) {
            this.data = newData;
            this.next = null;
        }
    }

    private Node head = null;

    public final void insertAtLast(final int data) {
        Node newNode = new Node(data);
        if (this.head == null) {
            this.head = newNode;
            this.head.next = this.head;
            return;
        }
        Node temp = this.head;
        while (temp.next != this.head) {
            temp = temp.next;
        }
        temp.next = newNode;
        newNode.next = this.head;
    }

    public void insertAtFirst(final int data) {
        Node newNode = new Node(data);
        if (this.head == null) {
            this.head = newNode;
            this.head.next = this.head;
            return;
        }
        Node temp = this.head;
        while (temp.next != this.head) {
            temp = temp.next;
        }
        newNode.next = this.head;
        this.head = newNode;
        temp.next = this.head;
    }

    public void insertAfter(final int data, final int after) {
        Node newNode = new Node(data);
        Node temp = this.head;
        while (temp != null) {
            if (temp.data == after) {
                newNode.next = temp.next;
                temp.next = newNode;
                return;
            }
            temp = temp.next;
        }
    }

    public void delete(final int data) {
        if (this.head == null) {
            return;
        }
        if (this.head.data == data) {
            Node temp = this.head;
            while (temp.next != this.head) {
                temp = temp.next;
            }
            temp.next = this.head.next;
            this.head = this.head.next;
            return;
        }
        Node temp = this.head;
        while (temp.next != this.head) {
            if (temp.next.data == data) {
                temp.next = temp.next.next;
                return;
            }
            temp = temp.next;
        }
    }

    public void print() {
        Node temp = this.head;
        if (temp != null) {
            do {
                System.out.print(temp.data + " -> ");
                temp = temp.next;
            } while (temp != this.head);
        }
        System.out.println("null");
    }

    public static void main(final String[] args) {
        CircularLinkedList list = new CircularLinkedList();

        for (int i = 1; i <= 5; i++) {
            list.insertAtLast(i);
        }

        list.print();

        list.insertAtFirst(0);
        list.insertAfter(6, 5);

        list.print();
    }
}
