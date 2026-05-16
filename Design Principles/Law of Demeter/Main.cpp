#include <iostream>
#include <string>
using namespace std;

// Law of Demeter - Don't talk to strangers

class Address {
private:
    string city;

public:
    Address(const string& city) : city(city) {}
    string getCity() const { return city; }
};

class Customer {
private:
    Address* address;

public:
    Customer(Address* addr) : address(addr) {}
    Address* getAddress() const { return address; }
};

class CreditCard {
private:
    string last4Digits;

public:
    CreditCard(const string& digits) : last4Digits(digits) {}
    string getLast4Digits() const { return last4Digits; }
};

class Payment {
private:
    CreditCard* creditCard;

public:
    Payment(CreditCard* card) : creditCard(card) {}
    CreditCard* getCreditCard() const { return creditCard; }
};

class Order {
private:
    Customer* customer;
    Payment* payment;

public:
    Order(Customer* cust, Payment* pay) : customer(cust), payment(pay) {}

    // Delegation methods (Law of Demeter)
    string getCustomerCity() const {
        return customer->getAddress()->getCity();
    }

    string getPaymentLast4Digits() const {
        return payment->getCreditCard()->getLast4Digits();
    }

    Customer* getCustomer() const { return customer; }
    Payment* getPayment() const { return payment; }
};

class OrderSummaryPrinter {
public:
    void print(const Order& order) const {
        // Using delegation methods instead of chaining
        string city = order.getCustomerCity();
        string last4 = order.getPaymentLast4Digits();

        cout << "Ship to: " << city << endl;
        cout << "Paid with card ending in: " << last4 << endl;
    }
};

int main() {
    Address address("San Francisco");
    Customer customer(&address);

    CreditCard card("4242");
    Payment payment(&card);

    Order order(&customer, &payment);

    OrderSummaryPrinter printer;
    printer.print(order);

    return 0;
}
