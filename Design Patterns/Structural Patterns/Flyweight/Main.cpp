#include <iostream>
#include <map>
#include <string>
using namespace std;

// Flyweight Pattern

class FontStyle {
public:
    virtual ~FontStyle() = default;
    virtual void format(int line, int column, char character) = 0;
};

class ConcreteFontStyle : public FontStyle {
private:
    string fontFamily;
    int fontSize;
    bool bold;
    bool italic;

public:
    ConcreteFontStyle(const string& fontFamily, int fontSize, bool bold, bool italic)
        : fontFamily(fontFamily), fontSize(fontSize), bold(bold), italic(italic) {}

    void format(int line, int column, char character) override {
        string style = bold ? "bold" : italic ? "italic" : "normal";
        cout << "[" << fontFamily << ", " << fontSize << ", " << style
             << "] '" << character << "' at " << line << ":" << column << endl;
    }
};

class FontStyleFactory {
private:
    map<string, FontStyle*> cache;

public:
    ~FontStyleFactory() {
        for (auto& pair : cache) {
            delete pair.second;
        }
    }

    FontStyle* getFontStyle(const string& fontFamily, int fontSize, bool bold, bool italic) {
        string key = fontFamily + to_string(fontSize) + (bold ? "1" : "0") + (italic ? "1" : "0");

        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        FontStyle* style = new ConcreteFontStyle(fontFamily, fontSize, bold, italic);
        cache[key] = style;
        return style;
    }

    int getStyleCount() const {
        return cache.size();
    }
};

int main() {
    FontStyleFactory factory;

    FontStyle* arial12 = factory.getFontStyle("Arial", 12, false, false);
    FontStyle* arial12Bold = factory.getFontStyle("Arial", 12, true, false);
    FontStyle* arial12Again = factory.getFontStyle("Arial", 12, false, false);

    arial12->format(1, 1, 'H');
    arial12Bold->format(1, 2, 'e');
    arial12Again->format(1, 3, 'l');

    cout << "Same instance? " << (arial12 == arial12Again ? "true" : "false") << endl;
    cout << "Total styles: " << factory.getStyleCount() << endl;

    return 0;
}
