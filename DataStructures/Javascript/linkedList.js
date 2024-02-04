class Node {
    constructor (data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    constructor () {
        this.head = null;
    }

    addNode (data) {
        const newNode = new Node(data);
        if (this.head === null) {
            this.head = newNode;
        } else {
            let current = this.head;
            while (current.next !== null) {
                current = current.next;
            }
            current.next = newNode;
        }
    }

    addNodeAtStart (data) {
        const newNode = new Node(data);
        newNode.next = this.head;
        this.head = newNode;
    }

    addNodeAtEnd (data) {
        const newNode = new Node(data);
        let current = this.head;
        while (current.next !== null) {
            current = current.next;
        }
        current.next = newNode;
    }

    printList () {
        let current = this.head;
        while (current !== null) {
            console.log(current.data);
            current = current.next;
        }
    }
}

const list = new LinkedList();
list.addNode(1);
list.addNode(2);
list.addNode(3);
list.addNode(4);

list.printList();
