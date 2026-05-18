import java.util.*;

interface OrderCommand {
    void execute();
    void undo();
}

class Kitchen {
    public void prepareDish(String dish) {
        // TODO: Print "Preparing: [dish]"
        System.out.println("Preparing: " + dish);
    }

    public void cancelDish(String dish) {
        // TODO: Print "Cancelling: [dish]"
        System.out.println("Cancelling: " + dish);
    }
}

class PlaceOrderCommand implements OrderCommand {
    // TODO: Add fields (kitchen, dish)
    private Kitchen kitchen;
    private String dish;

    public PlaceOrderCommand(Kitchen kitchen, String dish) {
        // TODO: Store receiver and dish
        this.kitchen = kitchen;
        this.dish = dish;
    }

    @Override
    public void execute() {
        // TODO: Call kitchen.prepareDish(dish)
        this.kitchen.prepareDish(this.dish);
    }

    @Override
    public void undo() {
        // TODO: Call kitchen.cancelDish(dish)
        this.kitchen.cancelDish(this.dish);
    }
}

class CancelOrderCommand implements OrderCommand {
    // TODO: Add fields (kitchen, dish)
    private Kitchen kitchen;
    private String dish;

    public CancelOrderCommand(Kitchen kitchen, String dish) {
        // TODO: Store receiver and dish
        this.kitchen = kitchen;
        this.dish = dish;
    }

    @Override
    public void execute() {
        // TODO: Call kitchen.cancelDish(dish)
        this.kitchen.cancelDish(this.dish);
    }

    @Override
    public void undo() {
        // TODO: Call kitchen.prepareDish(dish)
        this.kitchen.prepareDish(this.dish);
    }
}

class Waiter {
    // TODO: Add a pending queue and a history stack
    private List<OrderCommand> pending = new ArrayList<>();
    private Stack<OrderCommand> history = new Stack<>();

    public void takeOrder(OrderCommand command) {
        // TODO: Add command to pending queue
        pending.add(command);
    }

    public void submitOrders() {
        // TODO: Execute all pending commands, move them to history
        for(OrderCommand command : pending) {
            command.execute();
            history.push(command);
        }
        pending.clear();
    }

    public void undoLast() {
        // TODO: Pop the most recent command from history and call undo()
        if(!history.isEmpty()) {
            OrderCommand command = history.pop();
            command.undo();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Kitchen kitchen = new Kitchen();
        Waiter waiter = new Waiter();
        waiter.takeOrder(new PlaceOrderCommand(kitchen, "Pasta"));
        waiter.takeOrder(new PlaceOrderCommand(kitchen, "Salad"));
        waiter.submitOrders();
        waiter.takeOrder(new CancelOrderCommand(kitchen, "Salad"));
        waiter.submitOrders();
        waiter.undoLast(); // undo the cancellation
    }
}