#include <iostream>
#include <string>
using namespace std;

class Formatter {
public:
    virtual ~Formatter() = default;
    virtual string format(const string& message) const = 0;
};

class PlainFormatter : public Formatter {
public:
    string format(const string& message) const override {
        return message;
    }
};

class JsonFormatter : public Formatter {
public:
    string format(const string& message) const override {
        return "{\"log\": \"" + message + "\"}";
    }
};

class Logger {
private:
    Formatter* formatter;

public:
    Logger(Formatter* formatter) : formatter(formatter) {}

    void log(const string& message) const {
        cout << formatter->format(message) << endl;
    }
};

int main() {
    PlainFormatter plainFmt;
    JsonFormatter jsonFmt;

    Logger plainLogger(&plainFmt);
    Logger jsonLogger(&jsonFmt);

    plainLogger.log("Server started on port 8080");
    jsonLogger.log("Server started on port 8080");

    return 0;
}
