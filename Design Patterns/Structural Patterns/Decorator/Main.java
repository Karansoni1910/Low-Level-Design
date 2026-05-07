interface Pizza {
    double getCost();
    String getDescription();
}

class PlainPizza implements Pizza {
    @Override
    public double getCost() {
        return 5.00;
    }

    @Override
    public String getDescription() {
        return "Plain pizza";
    }
}

abstract class PizzaDecorator implements Pizza {
    // TODO: Add a protected field to store the wrapped Pizza reference
    protected Pizza pizza;

    public PizzaDecorator(Pizza pizza) {
        // TODO: Store the wrapped pizza
        this.pizza = pizza;
    }

    @Override
    public double getCost() {
        // TODO: Delegate to the wrapped pizza's getCost()
        return pizza.getCost();
    }

    @Override
    public String getDescription() {
        // TODO: Delegate to the wrapped pizza's getDescription()
        return pizza.getDescription();
    }
}

class CheeseDecorator extends PizzaDecorator {
    public CheeseDecorator(Pizza pizza) {
        super(pizza);
    }

    @Override
    public double getCost() {
        // TODO: Return the wrapped pizza's cost + 1.50
        return pizza.getCost() + 1.50;
    }

    @Override
    public String getDescription() {
        // TODO: Return the wrapped pizza's description + ", cheese"
        return pizza.getDescription() + ", cheese";
    }
}

class OliveDecorator extends PizzaDecorator {
    public OliveDecorator(Pizza pizza) {
        super(pizza);
    }

    @Override
    public double getCost() {
        // TODO: Return the wrapped pizza's cost + 2.00
        return pizza.getCost() + 2.00;
    }

    @Override
    public String getDescription() {
        // TODO: Return the wrapped pizza's description + ", olives"
        return pizza.getDescription() + ", olives";
    }
}

class MushroomDecorator extends PizzaDecorator {
    public MushroomDecorator(Pizza pizza) {
        super(pizza);
    }

    @Override
    public double getCost() {
        // TODO: Return the wrapped pizza's cost + 1.00
        return pizza.getCost() + 1.00;
    }

    @Override
    public String getDescription() {
        // TODO: Return the wrapped pizza's description + ", mushrooms"
        return pizza.getDescription() + ", mushrooms";
    }
}

public class Main {
    public static void main(String[] args) {
        Pizza plain = new PlainPizza();
        System.out.printf("%s | $%.2f%n", plain.getDescription(), plain.getCost());

        Pizza cheeseOlive = new OliveDecorator(new CheeseDecorator(new PlainPizza()));
        System.out.printf("%s | $%.2f%n", cheeseOlive.getDescription(), cheeseOlive.getCost());

        Pizza loaded = new MushroomDecorator(
            new OliveDecorator(new CheeseDecorator(new PlainPizza())));
        System.out.printf("%s | $%.2f%n", loaded.getDescription(), loaded.getCost());
    }
}