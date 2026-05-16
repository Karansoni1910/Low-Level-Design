#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Message {
private:
    string sender;
    string text;
    long timestamp;

public:
    Message(const string& sender, const string& text)
        : sender(sender), text(text), timestamp(time(nullptr)) {}

    void display() const {
        cout << "[" << sender << "]: " << text << endl;
    }

    string getSender() const { return sender; }
    string getText() const { return text; }
};

class Conversation {
private:
    string title;
    vector<Message> messages;

public:
    Conversation(const string& title) : title(title) {}

    void sendMessage(const string& sender, const string& text) {
        messages.emplace_back(sender, text);
    }

    void printHistory() const {
        cout << "--- " << title << " ---" << endl;
        for (const auto& m : messages) {
            m.display();
        }
    }

    void deleteAll() {
        messages.clear();
    }

    void forwardMessage(Conversation& target, int messageIndex) const {
        if (messageIndex >= 0 && messageIndex < messages.size()) {
            target.sendMessage(messages[messageIndex].getSender(),
                               messages[messageIndex].getText());
        }
    }

    int getMessageCount() const { return messages.size(); }
    string getTitle() const { return title; }
};

int main() {
    Conversation teamChat("Team Discussion");
    Conversation projectChat("Project Alpha");

    teamChat.sendMessage("Alice", "Hey team, standup in 5 minutes");
    teamChat.sendMessage("Bob", "Got it, joining now");
    teamChat.sendMessage("Alice", "Don't forget to update your tasks");

    projectChat.sendMessage("Charlie", "Deployment is scheduled for Friday");

    cout << "Before deletion:" << endl;
    teamChat.printHistory();
    cout << "Project chat has " << projectChat.getMessageCount() << " messages\n" << endl;

    teamChat.forwardMessage(projectChat, 2);
    cout << "After forwarding:" << endl;
    projectChat.printHistory();

    teamChat.deleteAll();
    cout << "\nAfter deleting team chat:" << endl;
    cout << "Team chat has " << teamChat.getMessageCount() << " messages" << endl;
    cout << "Project chat still has " << projectChat.getMessageCount() << " messages" << endl;

    return 0;
}
