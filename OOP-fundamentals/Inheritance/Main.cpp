#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class BankAccount {
protected:
    string ownerName;
    string accountNumber;
    double balance;

public:
    BankAccount(const string& ownerName, const string& accountNumber, double balance)
        : ownerName(ownerName), accountNumber(accountNumber), balance(balance) {}

    virtual ~BankAccount() = default;

    virtual bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            return true;
        }
        return false;
    }

    virtual bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    virtual void displayAccount() const {
        cout << ownerName << " (" << accountNumber << ") | Balance: $"
             << fixed << setprecision(2) << balance << endl;
    }

    double getBalance() const { return balance; }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(const string& ownerName, const string& accountNumber,
                   double balance, double interestRate)
        : BankAccount(ownerName, accountNumber, balance), interestRate(interestRate) {}

    bool withdraw(double amount) override {
        if (amount > 0 && balance - amount >= 100) {
            balance -= amount;
            return true;
        }
        return false;
    }

    void applyInterest() {
        balance += (balance * interestRate / 100);
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(const string& ownerName, const string& accountNumber,
                    double balance, double overdraftLimit)
        : BankAccount(ownerName, accountNumber, balance), overdraftLimit(overdraftLimit) {}

    bool withdraw(double amount) override {
        if (amount > 0 && balance + overdraftLimit >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }
};

int main() {
    SavingsAccount savings("Alice", "SA001", 1000, 5);
    CheckingAccount checking("Bob", "CA001", 500, 1000);

    cout << "=== Initial State ===" << endl;
    savings.displayAccount();
    checking.displayAccount();

    cout << "\n=== After Transactions ===" << endl;
    savings.deposit(500);
    checking.withdraw(2000);  // Uses overdraft

    savings.displayAccount();
    checking.displayAccount();

    cout << "\n=== After Interest ===" << endl;
    savings.applyInterest();
    savings.displayAccount();

    return 0;
}
