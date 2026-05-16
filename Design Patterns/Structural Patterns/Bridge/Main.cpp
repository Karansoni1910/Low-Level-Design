#include <iostream>
#include <string>
using namespace std;

// Bridge Pattern

class MessageSender {
public:
    virtual ~MessageSender() = default;
    virtual void sendMessage(const string& content) = 0;
};

class EmailSender : public MessageSender {
public:
    void sendMessage(const string& content) override {
        cout << "Email: " << content << endl;
    }
};

class SmsSender : public MessageSender {
public:
    void sendMessage(const string& content) override {
        cout << "SMS: " << content << endl;
    }
};

class Message {
protected:
    MessageSender* sender;
    string content;

public:
    Message(MessageSender* sender, const string& content)
        : sender(sender), content(content) {}

    virtual ~Message() = default;
    virtual void send() = 0;
};

class TextMessage : public Message {
public:
    TextMessage(MessageSender* sender, const string& content)
        : Message(sender, content) {}

    void send() override {
        sender->sendMessage(content);
    }
};

class UrgentMessage : public Message {
public:
    UrgentMessage(MessageSender* sender, const string& content)
        : Message(sender, content) {}

    void send() override {
        sender->sendMessage("[URGENT] " + content);
    }
};

int main() {
    EmailSender email;
    SmsSender sms;

    TextMessage m1(&email, "Hello there");
    UrgentMessage m2(&sms, "Server is down");

    m1.send();
    m2.send();

    return 0;
}
