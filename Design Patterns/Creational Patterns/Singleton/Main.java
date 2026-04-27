class Counter {
    // TODO: Implement as singleton
    // Hint: Use enum or Bill Pugh pattern

    private int count = 0;

    public void increment() {
        // TODO: Make thread-safe
        this.count++;
    }

    public int getCount() {
        // TODO: Return current count
        return this.count;
    }

    private static class Holder {
        private static final Counter INSTANCE = new Counter();
    }

    public static Counter getInstance() {
        return Holder.INSTANCE;
    }
}

public class Main {
    public static void main(String[] args) {
        // After implementing, usage should look like:
        Counter c1 = Counter.getInstance();
        Counter c2 = Counter.getInstance();
        System.out.println("Same instance: " + (c1 == c2));
        for (int i = 0; i < 5; i++) {
            c1.increment();
        }
        System.out.println("Count after 5 increments: " + c1.getCount());
    }
}