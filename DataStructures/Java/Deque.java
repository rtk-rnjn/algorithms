
import java.util.ArrayList;

class Deque {
    private ArrayList<Integer> deque;

    Deque() {
        deque = new ArrayList<>();
    }

    public void pushFront(final int x) {
        deque.add(0, x);
    }

    public void pushBack(final int x) {
        deque.add(x);
    }

    public int popFront() {
        if (deque.isEmpty()) {
            return -1;
        }
        return deque.remove(0);
    }

    public int popBack() {
        if (deque.isEmpty()) {
            return -1;
        }
        return deque.remove(deque.size() - 1);
    }

    public int front() {
        if (deque.isEmpty()) {
            return -1;
        }
        return deque.get(0);
    }

    public int back() {
        if (deque.isEmpty()) {
            return -1;
        }
        return deque.get(deque.size() - 1);
    }

    public int size() {
        return deque.size();
    }

    public boolean isEmpty() {
        return deque.isEmpty();
    }
}
