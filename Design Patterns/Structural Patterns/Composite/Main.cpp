#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
using namespace std;

// Composite Pattern

class Menu {
public:
    virtual ~Menu() = default;
    virtual void display(const string& indent) = 0;
    virtual int getItemCount() const = 0;
};

class MenuItem : public Menu {
private:
    string name;
    double price;

public:
    MenuItem(const string& name, double price) : name(name), price(price) {}

    void display(const string& indent) override {
        cout << indent << name << " - $" << fixed << setprecision(2) << price << endl;
    }

    int getItemCount() const override {
        return 1;
    }
};

class SubMenu : public Menu {
private:
    string name;
    vector<shared_ptr<Menu>> children;

public:
    SubMenu(const string& name) : name(name) {}

    void addItem(shared_ptr<Menu> item) {
        children.push_back(item);
    }

    void display(const string& indent) override {
        cout << indent << name << ":" << endl;
        for (const auto& child : children) {
            child->display(indent + "  ");
        }
    }

    int getItemCount() const override {
        int total = 0;
        for (const auto& child : children) {
            total += child->getItemCount();
        }
        return total;
    }
};

int main() {
    auto burger = make_shared<MenuItem>("Burger", 8.99);
    auto fries = make_shared<MenuItem>("Fries", 3.99);
    auto cola = make_shared<MenuItem>("Cola", 1.99);
    auto water = make_shared<MenuItem>("Water", 0.99);

    auto drinks = make_shared<SubMenu>("Drinks");
    drinks->addItem(cola);
    drinks->addItem(water);

    auto mainMenu = make_shared<SubMenu>("Main Menu");
    mainMenu->addItem(burger);
    mainMenu->addItem(fries);
    mainMenu->addItem(drinks);

    mainMenu->display("");
    cout << "\nTotal items: " << mainMenu->getItemCount() << endl;

    return 0;
}
