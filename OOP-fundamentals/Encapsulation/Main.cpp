#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

class ShoppingCart {
private:
    map<string, double> items;
    bool discountApplied;
    bool isCheckedOut;

public:
    ShoppingCart() : discountApplied(false), isCheckedOut(false) {}

    void addItem(const string& name, double price) {
        if (!isCheckedOut) {
            items[name] = price;
        } else {
            cout << "Cannot modify a checked-out cart" << endl;
        }
    }

    bool applyDiscount(const string& code) {
        if (!discountApplied && code == "SAVE10") {
            discountApplied = true;
            return true;
        }
        return false;
    }

    double getTotal() const {
        double total = 0;
        for (const auto& item : items) {
            total += item.second;
        }

        if (discountApplied) {
            total -= total / 10;
        }
        return total;
    }

    void checkout() {
        if (!items.empty() && !isCheckedOut) {
            isCheckedOut = true;
        }
    }
};

int main() {
    ShoppingCart cart;
    cart.addItem("Laptop", 999.99);
    cart.addItem("Mouse", 29.99);

    cout << fixed << setprecision(2);
    cout << "Total: $" << cart.getTotal() << endl;  // 1029.98

    cout << "Discount: " << (cart.applyDiscount("SAVE10") ? "true" : "false") << endl;  // true
    cout << "Total: $" << cart.getTotal() << endl;  // 926.98

    cout << "Discount: " << (cart.applyDiscount("SAVE10") ? "true" : "false") << endl;  // false

    cart.checkout();
    cart.addItem("Keyboard", 79.99);  // Should be rejected
    cout << "Total: $" << cart.getTotal() << endl;  // 926.98 (unchanged)

    return 0;
}
