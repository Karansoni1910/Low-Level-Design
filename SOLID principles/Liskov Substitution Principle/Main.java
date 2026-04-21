// Before: Penguin extends Bird but can't fly
interface Bird {
    public void eat();
}

interface FlyingBird extends Bird {
    public void eat();
    public void fly();
}

class Sparrow implements FlyingBird {
    public void eat() {
        System.out.println("Sparrow is eating");
    }
    public void fly() {
        System.out.println("Sparrow is flying");
    }
}

class Penguin implements Bird {
    public void eat() {
        System.out.println("Penguin is eating");
    }
}

public class Main {
    public static void main(String[] args) {
        Sparrow sparrow = new Sparrow(); // Works fine
        sparrow.eat();
        sparrow.fly();

        Penguin penguin = new Penguin(); // UnsupportedOperationException!
        penguin.eat();
    }
}

// TODO: Split Bird into a Bird interface (eat) and a FlyingBird interface (fly).
// TODO: Sparrow implements FlyingBird, Penguin implements only Bird.