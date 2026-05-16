#include <iostream>
using namespace std;

// Singleton Pattern - Meyer's Singleton (thread-safe in C++11)

class Counter {
private:
    int count;

    // Private constructor
    Counter() : count(0) {}

public:
    // Delete copy constructor and assignment operator
    Counter(const Counter&) = delete;
    Counter& operator=(const Counter&) = delete;

    static Counter& getInstance() {
        static Counter instance;
        return instance;
    }

    void increment() {
        count++;
    }

    int getCount() const {
        return count;
    }
};

int main() {
    Counter& c1 = Counter::getInstance();
    Counter& c2 = Counter::getInstance();

    cout << "Same instance: " << (&c1 == &c2 ? "true" : "false") << endl;

    for (int i = 0; i < 5; i++) {
        c1.increment();
    }

    cout << "Count after 5 increments: " << c1.getCount() << endl;

    return 0;
}
