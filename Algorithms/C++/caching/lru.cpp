#include <iostream>
#include <unordered_map>

class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    std::unordered_map<int, Node*> cacheMap;
    Node* head;
    Node* tail;
    int size;
    int capacity;

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    void freeNode(Node* node) {
        delete node;
    }

public:
    LRUCache(int capacity) : capacity(capacity), size(0) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }
        Node* node = cacheMap[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            Node* node = cacheMap[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* newNode = new Node(key, value);
            cacheMap[key] = newNode;
            addNode(newNode);
            size++;

            if (size > capacity) {
                Node* tailNode = tail->prev;
                removeNode(tailNode);
                cacheMap.erase(tailNode->key);
                freeNode(tailNode);
                size--;
            }
        }
    }

    void displayAsArray() {
        Node* node = head->next;
        std::cout << "[";
        while (node != tail) {
            std::cout << "[key=" << node->key << " value=" << node->value << "], ";
            node = node->next;
        }
        std::cout << "\b\b]" << std::endl;
    }

    ~LRUCache() {
        Node* node = head->next;
        while (node != tail) {
            Node* temp = node;
            node = node->next;
            freeNode(temp);
        }
        delete head;
        delete tail;
    }
};

int main() {
    LRUCache cache(5);

    for (int i = 1; i <= 5; i++) {
        cache.put(i, i * 2 + 3);
    }

    cache.displayAsArray();

    std::cout << "Getting key 3: " << cache.get(3) << std::endl;

    return 0;
}
