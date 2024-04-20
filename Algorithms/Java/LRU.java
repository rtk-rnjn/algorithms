import java.util.ArrayDeque;
import java.util.HashMap;

class LRU {
    private final int capacity;
    private final HashMap<Integer, Integer> cache;
    private final ArrayDeque<Integer> queue;

    LRU(final int size) {
        this.capacity = size;
        this.cache = new HashMap<>();
        this.queue = new ArrayDeque<Integer>();
    }

    public int get(final int key) {
        if (!cache.containsKey(key)) {
            return -1;
        }
        this.queue.remove(key);
        this.queue.addFirst(key);

        return cache.get(key);
    }

    public void put(final int key, final int value) {
        if (cache.containsKey(key)) {
            this.queue.remove(key);
        } else if (this.queue.size() >= this.capacity) {
            this.cache.remove(this.queue.removeLast());
        }
        this.cache.put(key, value);
        this.queue.addFirst(key);
    }

    public static void main(final String[] args) {
        final LRU lru = new LRU(2);
        lru.put(1, 1);
        lru.put(2, 2);
        System.out.println(lru.get(1));
        lru.put(3, 3);
        System.out.println(lru.get(2));
        lru.put(4, 4);
        System.out.println(lru.get(1));
        System.out.println(lru.get(3));
        System.out.println(lru.get(4));
    }
}
