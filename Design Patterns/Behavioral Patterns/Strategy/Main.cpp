#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

// Behavioral Pattern: Strategy

class TextFormatter {
public:
    virtual ~TextFormatter() = default;
    virtual string format(const string& text) = 0;
};

class UpperCaseFormatter : public TextFormatter {
public:
    string format(const string& text) override {
        string result = text;
        transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }
};

class LowerCaseFormatter : public TextFormatter {
public:
    string format(const string& text) override {
        string result = text;
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }
};

class TitleCaseFormatter : public TextFormatter {
public:
    string format(const string& text) override {
        stringstream ss(text);
        string word;
        string result;

        while (ss >> word) {
            if (!result.empty()) result += " ";

            if (!word.empty()) {
                word[0] = toupper(word[0]);
                for (size_t i = 1; i < word.length(); ++i) {
                    word[i] = tolower(word[i]);
                }
            }
            result += word;
        }

        return result;
    }
};

class TextEditor {
private:
    TextFormatter* formatter;

public:
    TextEditor(TextFormatter* fmt) : formatter(fmt) {}

    void setFormatter(TextFormatter* fmt) {
        formatter = fmt;
    }

    void publishText(const string& text) {
        cout << formatter->format(text) << endl;
    }
};

int main() {
    UpperCaseFormatter upperFmt;
    LowerCaseFormatter lowerFmt;
    TitleCaseFormatter titleFmt;

    TextEditor editor(&upperFmt);
    editor.publishText("hello world from strategy pattern");

    editor.setFormatter(&lowerFmt);
    editor.publishText("Hello World From Strategy Pattern");

    editor.setFormatter(&titleFmt);
    editor.publishText("hello world from strategy pattern");

    return 0;
}
