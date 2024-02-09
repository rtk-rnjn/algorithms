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

    public void insertAtEnd(final int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            tail = newNode;
            newNode.next = head;
            newNode.prev = tail;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            newNode.next = head;
            head.prev = newNode;
            tail = newNode;
        }
    }

    public void insertAtStart(final int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            tail = newNode;
            newNode.next = head;
            newNode.prev = tail;
        } else {
            newNode.next = head;
            head.prev = newNode;
            newNode.prev = tail;
            tail.next = newNode;
            head = newNode;
        }
    }

    public void insertAfter(final int data, final int previousData) {
        Node newNode = new Node(data);
        Node temp = head;
        do {
            if (temp.data == previousData) {
                newNode.next = temp.next;
                temp.next.prev = newNode;
                temp.next = newNode;
                newNode.prev = temp;
                return;
            }
            temp = temp.next;
        } while (temp != head);
    }
}
