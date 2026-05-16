#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Plugin {
public:
    virtual ~Plugin() = default;
    virtual string execute(const string& text) = 0;
    virtual string getName() const = 0;
};

class SpellCheckPlugin : public Plugin {
public:
    string execute(const string& text) override {
        string result = text;
        size_t pos = 0;
        while ((pos = result.find("teh", pos)) != string::npos) {
            result.replace(pos, 3, "the");
            pos += 3;
        }
        pos = 0;
        while ((pos = result.find("adn", pos)) != string::npos) {
            result.replace(pos, 3, "and");
            pos += 3;
        }
        return result;
    }

    string getName() const override {
        return "Spell Check";
    }
};

class WordCountPlugin : public Plugin {
public:
    string execute(const string& text) override {
        int count = 0;
        bool inWord = false;
        for (char c : text) {
            if (isspace(c)) {
                inWord = false;
            } else if (!inWord) {
                count++;
                inWord = true;
            }
        }
        return text + "\n[Word count: " + to_string(count) + "]";
    }

    string getName() const override {
        return "Word Count";
    }
};

class UpperCasePlugin : public Plugin {
public:
    string execute(const string& text) override {
        string result = text;
        for (char& c : result) {
            c = toupper(c);
        }
        return result;
    }

    string getName() const override {
        return "Upper Case";
    }
};

class TextEditor {
private:
    vector<shared_ptr<Plugin>> plugins;

public:
    void registerPlugin(shared_ptr<Plugin> plugin) {
        plugins.push_back(plugin);
        cout << "Registered: " << plugin->getName() << endl;
    }

    string runPlugins(const string& text) const {
        string result = text;
        for (const auto& p : plugins) {
            cout << "Running: " << p->getName() << endl;
            result = p->execute(result);
        }
        return result;
    }
};

int main() {
    TextEditor editor;
    editor.registerPlugin(make_shared<SpellCheckPlugin>());
    editor.registerPlugin(make_shared<WordCountPlugin>());

    string result = editor.runPlugins("teh quick brown fox adn teh lazy dog");
    cout << "\nFinal output:\n" << result << endl;

    return 0;
}
