#include <iostream>
#include <vector>
#include <stack>
#include <memory>

using namespace std;

// --- Command Interface ---
class OrderCommand {
public:
    virtual ~OrderCommand() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// --- Receiver: Kitchen ---
class Kitchen {
public:
    void prepareDish(const string& dish) {
        cout << "Preparing: " << dish << endl;
    }

    void cancelDish(const string& dish) {
        cout << "Cancelling: " << dish << endl;
    }
};

// --- Concrete Command 1: PlaceOrderCommand ---
class PlaceOrderCommand : public OrderCommand {
private:
    Kitchen* kitchen;
    string dish;

public:
    PlaceOrderCommand(Kitchen* kitchen, const string& dish)
        : kitchen(kitchen), dish(dish) {}

    void execute() override {
        kitchen->prepareDish(dish);
    }

    void undo() override {
        kitchen->cancelDish(dish);
    }
};

// --- Concrete Command 2: CancelOrderCommand ---
class CancelOrderCommand : public OrderCommand {
private:
    Kitchen* kitchen;
    string dish;

public:
    CancelOrderCommand(Kitchen* kitchen, const string& dish)
        : kitchen(kitchen), dish(dish) {}

    void execute() override {
        kitchen->cancelDish(dish);
    }

    void undo() override {
        kitchen->prepareDish(dish);
    }
};

// --- Invoker: Waiter ---
class Waiter {
private:
    vector<shared_ptr<OrderCommand>> pending;
    stack<shared_ptr<OrderCommand>> history;

public:
    void takeOrder(shared_ptr<OrderCommand> command) {
        pending.push_back(command);
    }

    void submitOrders() {
        for (auto& command : pending) {
            command->execute();
            history.push(command);
        }
        pending.clear();
    }

    void undoLast() {
        if (!history.empty()) {
            auto command = history.top();
            history.pop();
            command->undo();
        }
    }
};

// --- Main ---
int main() {
    Kitchen kitchen;
    Waiter waiter;

    // Queue orders
    waiter.takeOrder(make_shared<PlaceOrderCommand>(&kitchen, "Pasta"));
    waiter.takeOrder(make_shared<PlaceOrderCommand>(&kitchen, "Pizza"));
    waiter.takeOrder(make_shared<PlaceOrderCommand>(&kitchen, "Burger"));

    cout << "--- Submitting Orders ---" << endl;
    waiter.submitOrders();

    cout << "\n--- Undoing Last Order ---" << endl;
    waiter.undoLast();

    cout << "\n--- Undoing Another Order ---" << endl;
    waiter.undoLast();

    return 0;
}
