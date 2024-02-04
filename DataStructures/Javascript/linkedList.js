class node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class linkedList {
    constructor() {
        this.head = null;
    }

    addNode(data) {
        let newNode = new node(data);
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

    addNodeAtStart(data) {
        let newNode = new node(data);
        newNode.next = this.head;
        this.head = newNode;
    }

    addNodeAtEnd(data) {
        let newNode = new node(data);
        let current = this.head;
        while (current.next !== null) {
            current = current.next;
        }
        current.next = newNode;
    }

    printList() {
        let current = this.head;
        while (current !== null) {
            console.log(current.data);
            current = current.next;
        }
    }
}

let list = new linkedList();
list.addNode(1);
list.addNode(2);
list.addNode(3);
list.addNode(4);

list.printList();
