#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;

public:
    BankAccount(const string& accountNumber, const string& ownerName)
        : accountNumber(accountNumber), ownerName(ownerName), balance(0.0) {}

    void deposit(double amount) {
        if (amount >= 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account("123456", "John Doe");
    account.deposit(1000);
    cout << account.getBalance() << endl;  // Should print 1000

    bool success = account.withdraw(500);
    cout << (success ? "true" : "false") << endl;  // Should print true
    cout << account.getBalance() << endl;  // Should print 500

    success = account.withdraw(1000);
    cout << (success ? "true" : "false") << endl;  // Should print false

    return 0;
}
