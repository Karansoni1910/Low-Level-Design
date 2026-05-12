// Liskov Substitution Principle: Derived classes must be substitutable for base classes

interface Bird {
    eat(): void;
}

interface FlyingBird extends Bird {
    fly(): void;
}

class Sparrow implements FlyingBird {
    eat(): void {
        console.log("Sparrow is eating");
    }

    fly(): void {
        console.log("Sparrow is flying");
    }
}

class Penguin implements Bird {
    eat(): void {
        console.log("Penguin is eating");
    }
}

// Usage
const sparrow: FlyingBird = new Sparrow();
sparrow.eat();
sparrow.fly();

const penguin: Bird = new Penguin();
penguin.eat();

// Both can be used where Bird is expected
const birds: Bird[] = [sparrow, penguin];
birds.forEach(bird => bird.eat());
