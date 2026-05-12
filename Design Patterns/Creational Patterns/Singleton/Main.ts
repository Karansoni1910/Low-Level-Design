class Counter {
    private count: number = 0;
    private static instance: Counter;

    private constructor() {}

    public increment(): void {
        this.count++;
    }

    public getCount(): number {
        return this.count;
    }

    public static getInstance(): Counter {
        if (!Counter.instance) {
            Counter.instance = new Counter();
        }
        return Counter.instance;
    }
}

// Usage
const c1 = Counter.getInstance();
const c2 = Counter.getInstance();

console.log("Same instance:", c1 === c2);

for (let i = 0; i < 5; i++) {
    c1.increment();
}

console.log("Count after 5 increments:", c1.getCount());
