class LRUCache {
    constructor(capacity) {
        this.capacity = capacity;
        this.cache = new Map();
    }

    get(key) {
        if (!this.cache.has(key)) return -1;

        const value = this.cache.get(key);

        this.cache.delete(key);
        this.cache.set(key, value);

        return value;
    }

    put(key, value) {
        if (this.cache.has(key)) {
            this.cache.delete(key);
        }

        this.cache.set(key, value);

        if (this.cache.size > this.capacity) {
            const lruKey = this.cache.keys().next().value;
            this.cache.delete(lruKey);
        }
    }

    display() {
        const arr = [];
        for (const [key, value] of this.cache.entries()) {
            arr.push(`[key=${key} value=${value}]`);
        }
        console.log(`[${arr.join(', ')}]`);
    }
}

const cache = new LRUCache(5);

for (let i = 1; i <= 5; i++) {
    cache.put(i, i * 2 + 3);
}

cache.display();

console.log('Getting key 3:', cache.get(3));
