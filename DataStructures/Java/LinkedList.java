class LinkedList {
    static class Node {
        int data;
        Node next;

        Node(int d) {
            this.data = d;
            this.next = null;
        }
    }

    protected Node head;

    LinkedList() {
        this.head = null;
    }

    public void insertAtLast(int d) {
        Node newNode = new Node(d);
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

    public void insertAtFirst(int d) {
        Node newNode = new Node(d);
        newNode.next = this.head;
        this.head = newNode;
    }

    public void insertAfter(int d, int after) {
        Node newNode = new Node(d);
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

    public void delete(int d) {
        if (this.head == null) {
            return;
        }
        if (this.head.data == d) {
            this.head = this.head.next;
            return;
        }
        Node temp = this.head;
        while (temp.next != null) {
            if (temp.next.data == d) {
                temp.next = temp.next.next;
                return;
            }
            temp = temp.next;
        }
    }

    public void reverse() {
        Node prev = null;
        Node curr = this.head;
        Node next = null;
        while (curr != null) {
            next = curr.next;
            curr.next = prev;

            prev = curr;
            curr = next;
        }
        this.head = prev;
    }

    public static void main(String[] args) {
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