#include <iostream>
using namespace std;

// Interface Segregation Principle: Clients should not depend on interfaces they don't use

class Printable {
public:
    virtual ~Printable() = default;
    virtual void print(const string& document) = 0;
};

class Scannable {
public:
    virtual ~Scannable() = default;
    virtual void scan(const string& document) = 0;
};

class Faxable {
public:
    virtual ~Faxable() = default;
    virtual void fax(const string& document, const string& number) = 0;
};

class Stapleable {
public:
    virtual ~Stapleable() = default;
    virtual void staple(const string& document) = 0;
};

class BasicPrinter : public Printable {
public:
    void print(const string& document) override {
        cout << "BasicPrinter -> Printing: " << document << endl;
    }
};

class OfficePrinter : public Printable, public Scannable, public Faxable {
public:
    void print(const string& document) override {
        cout << "OfficePrinter -> Printing: " << document << endl;
    }

    void scan(const string& document) override {
        cout << "OfficePrinter -> Scanning: " << document << endl;
    }

    void fax(const string& document, const string& number) override {
        cout << "OfficePrinter -> Faxing: " << document << " to " << number << endl;
    }
};

class FullDevice : public Printable, public Scannable, public Faxable, public Stapleable {
public:
    void print(const string& document) override {
        cout << "FullDevice -> Printing: " << document << endl;
    }

    void scan(const string& document) override {
        cout << "FullDevice -> Scanning: " << document << endl;
    }

    void fax(const string& document, const string& number) override {
        cout << "FullDevice -> Faxing: " << document << " to " << number << endl;
    }

    void staple(const string& document) override {
        cout << "FullDevice -> Stapling: " << document << endl;
    }
};

int main() {
    BasicPrinter basicPrinter;
    basicPrinter.print("report.pdf");

    OfficePrinter officePrinter;
    officePrinter.print("memo.pdf");
    officePrinter.scan("memo.pdf");
    officePrinter.fax("memo.pdf", "555-1234");

    FullDevice fullDevice;
    fullDevice.print("contract.pdf");
    fullDevice.scan("contract.pdf");
    fullDevice.fax("contract.pdf", "555-5678");
    fullDevice.staple("contract.pdf");

    return 0;
}
