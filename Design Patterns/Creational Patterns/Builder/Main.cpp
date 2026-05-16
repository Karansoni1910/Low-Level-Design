#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Builder Pattern

class Email {
private:
    string to;
    string subject;
    vector<string> cc;
    vector<string> bcc;
    string body;
    string priority;
    vector<string> attachments;

    // Private constructor - only accessible via Builder
    Email(const string& to, const string& subject, const vector<string>& cc,
          const vector<string>& bcc, const string& body, const string& priority,
          const vector<string>& attachments)
        : to(to), subject(subject), cc(cc), bcc(bcc), body(body),
          priority(priority), attachments(attachments) {}

public:
    class Builder {
    private:
        string to;
        string subject;
        vector<string> cc;
        vector<string> bcc;
        string body;
        string priority;
        vector<string> attachments;

    public:
        Builder(const string& to, const string& subject)
            : to(to), subject(subject), priority("normal") {}

        Builder& cc(const string& cc_addr) {
            cc.push_back(cc_addr);
            return *this;
        }

        Builder& bcc(const string& bcc_addr) {
            bcc.push_back(bcc_addr);
            return *this;
        }

        Builder& body(const string& b) {
            body = b;
            return *this;
        }

        Builder& priority(const string& p) {
            priority = p;
            return *this;
        }

        Builder& attachment(const string& att) {
            attachments.push_back(att);
            return *this;
        }

        Email build() {
            return Email(to, subject, cc, bcc, body, priority, attachments);
        }
    };

    string toString() const {
        stringstream ss;
        ss << "Email{to='" << to << "', subject='" << subject << "', cc=[";
        for (size_t i = 0; i < cc.size(); i++) {
            if (i > 0) ss << ", ";
            ss << cc[i];
        }
        ss << "], bcc=[";
        for (size_t i = 0; i < bcc.size(); i++) {
            if (i > 0) ss << ", ";
            ss << bcc[i];
        }
        ss << "], body='" << body << "', priority='" << priority << "', attachments=[";
        for (size_t i = 0; i < attachments.size(); i++) {
            if (i > 0) ss << ", ";
            ss << attachments[i];
        }
        ss << "]}";
        return ss.str();
    }

    friend ostream& operator<<(ostream& os, const Email& email) {
        os << email.toString();
        return os;
    }
};

int main() {
    Email email1 = Email::Builder("alice@example.com", "Meeting Tomorrow")
        .body("Let's meet at 10am in conference room B.")
        .build();

    Email email2 = Email::Builder("bob@example.com", "Project Update")
        .cc("carol@example.com")
        .cc("dave@example.com")
        .bcc("manager@example.com")
        .body("Attached is the Q4 report.")
        .priority("high")
        .attachment("q4-report.pdf")
        .attachment("summary.xlsx")
        .build();

    cout << email1 << endl << endl;
    cout << email2 << endl;

    return 0;
}
