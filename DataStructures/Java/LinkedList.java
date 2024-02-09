class LinkedList {
    private Node head = null;

    static class Node {
        // CSOFF: VisibilityModifier
        int data;
        Node next;
        // CSOFF: VisibilityModifier

        Node(final int newData) {
            this.data = newData;
            this.next = null;
        }
    }

    public void insertAtLast(final int data) {
        Node newNode = new Node(data);
        if (this.head == null) {
            this.head = newNode;
            return;
        }
        Node temp = this.head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
    }

    public void insertAtFirst(final int data) {
        Node newNode = new Node(data);
        newNode.next = this.head;
        this.head = newNode;
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

    public void print() {
        Node temp = this.head;
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("null");
    }

    public void delete(final int data) {
        if (this.head == null) {
            return;
        }
        if (this.head.data == data) {
            this.head = this.head.next;
            return;
        }
        Node temp = this.head;
        while (temp.next != null) {
            if (temp.next.data == data) {
                temp.next = temp.next.next;
                return;
            }
            temp = temp.next;
        }
    }

    public void reverse() {
        Node previousNode = null;
        Node currentNode = this.head;
        Node nextNode = null;
        while (currentNode != null) {
            nextNode = currentNode.next;
            currentNode.next = previousNode;

            previousNode = currentNode;
            currentNode = nextNode;
        }
        this.head = previousNode;
    }

    void extend(final LinkedList list) {
        if (this.head == null) {
            this.head = list.head;
            return;
        }
        Node temp = this.head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = list.head;
    }

    public int length() {
        int length = 0;
        Node temp = this.head;
        while (temp != null) {
            length++;
            temp = temp.next;
        }
        return length;
    }

    public static void main(final String[] args) {
        LinkedList list = new LinkedList();
        list.insertAtLast(1);
        list.insertAtLast(2);
        list.insertAtLast(3);
        list.insertAtLast(4);
        list.insertAtLast(5);

        list.print();

        list.insertAtFirst(0);
        list.insertAtFirst(-1);
        list.insertAtFirst(-2);

        list.print();

        list.insertAfter(6, 5);
        list.insertAfter(7, 6);
        list.insertAfter(8, 7);

        list.print();

        list.delete(8);
        list.delete(7);
        list.delete(6);

        list.print();

        list.reverse();

        list.print();
    }

}
