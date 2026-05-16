#include <iostream>
using namespace std;

// Abstract Factory Pattern

class ThemeColor {
public:
    virtual ~ThemeColor() = default;
    virtual void apply() = 0;
};

class ThemeFont {
public:
    virtual ~ThemeFont() = default;
    virtual void render() = 0;
};

class LightColor : public ThemeColor {
public:
    void apply() override {
        cout << "Applying light color: #FFFFFF background, #000000 text" << endl;
    }
};

class DarkColor : public ThemeColor {
public:
    void apply() override {
        cout << "Applying dark color: #1E1E1E background, #FFFFFF text" << endl;
    }
};

class LightFont : public ThemeFont {
public:
    void render() override {
        cout << "Rendering light theme font: Arial, 14px" << endl;
    }
};

class DarkFont : public ThemeFont {
public:
    void render() override {
        cout << "Rendering dark theme font: Consolas, 14px" << endl;
    }
};

class ThemeFactory {
public:
    virtual ~ThemeFactory() = default;
    virtual ThemeColor* createColor() = 0;
    virtual ThemeFont* createFont() = 0;
};

class LightThemeFactory : public ThemeFactory {
public:
    ThemeColor* createColor() override {
        return new LightColor();
    }

    ThemeFont* createFont() override {
        return new LightFont();
    }
};

class DarkThemeFactory : public ThemeFactory {
public:
    ThemeColor* createColor() override {
        return new DarkColor();
    }

    ThemeFont* createFont() override {
        return new DarkFont();
    }
};

class ThemeClient {
private:
    ThemeColor* color;
    ThemeFont* font;

public:
    ThemeClient(ThemeFactory* factory) {
        color = factory->createColor();
        font = factory->createFont();
    }

    ~ThemeClient() {
        delete color;
        delete font;
    }

    void applyTheme() {
        color->apply();
        font->render();
    }
};

int main() {
    cout << "=== Light Theme ===" << endl;
    LightThemeFactory lightFactory;
    ThemeClient lightClient(&lightFactory);
    lightClient.applyTheme();

    cout << endl;

    cout << "=== Dark Theme ===" << endl;
    DarkThemeFactory darkFactory;
    ThemeClient darkClient(&darkFactory);
    darkClient.applyTheme();

    return 0;
}
