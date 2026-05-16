#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// KISS - Keep It Simple, Stupid

class DisplayNameFormatter {
public:
    string formatDisplayName(const string& name) {
        string trimmed = name;

        // Trim left
        size_t start = trimmed.find_first_not_of(" \t\n\r");
        if (start == string::npos) return "";
        trimmed = trimmed.substr(start);

        // Trim right
        size_t end = trimmed.find_last_not_of(" \t\n\r");
        trimmed = trimmed.substr(0, end + 1);

        // Capitalize first letter
        if (!trimmed.empty()) {
            trimmed[0] = toupper(trimmed[0]);
        }

        return trimmed;
    }
};

int main() {
    DisplayNameFormatter formatter;

    cout << formatter.formatDisplayName("  john doe  ") << endl;
    cout << formatter.formatDisplayName("ALICE") << endl;
    cout << formatter.formatDisplayName("  bob  ") << endl;

    return 0;
}
