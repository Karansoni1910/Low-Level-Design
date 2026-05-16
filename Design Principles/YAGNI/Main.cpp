#include <iostream>
#include <string>
using namespace std;

// YAGNI - You Aren't Gonna Need It

class PasswordValidator {
public:
    bool isValid(const string& password) {
        if (password.empty()) {
            return false;
        }
        return password.length() >= 8;
    }
};

int main() {
    PasswordValidator validator;

    cout << (validator.isValid("short") ? "true" : "false") << endl;            // false
    cout << (validator.isValid("longenough") ? "true" : "false") << endl;        // true
    cout << (validator.isValid("12345678") ? "true" : "false") << endl;          // true
    cout << (validator.isValid("") ? "true" : "false") << endl;                  // false

    return 0;
}
