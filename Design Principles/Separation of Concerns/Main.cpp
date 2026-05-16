#include <iostream>
#include <string>
using namespace std;

// Separation of Concerns Principle

// Database Concern
class UserRepository {
public:
    void saveUser(const string& name, const string& email) {
        cout << "Database: Executing query - INSERT INTO users VALUES ('" 
             << name << "', '" << email << "')" << endl;
    }
};

// Email Concern
class EmailService {
public:
    void sendWelcomeEmail(const string& email) {
        cout << "Email: Sending welcome email to " << email << endl;
    }
};

// Logging Concern
class Logger {
public:
    void log(const string& message) {
        cout << "[LOG] " << message << endl;
    }
};

// User Model
class User {
private:
    string name;
    string email;

public:
    User(const string& name, const string& email) : name(name), email(email) {}

    string getName() const { return name; }
    string getEmail() const { return email; }
};

// Orchestrator (Coordinates all concerns)
class UserService {
private:
    UserRepository* repository;
    EmailService* emailService;
    Logger* logger;

public:
    UserService(UserRepository* repo, EmailService* email, Logger* log)
        : repository(repo), emailService(email), logger(log) {}

    void registerUser(const string& name, const string& email) {
        logger->log("Starting user registration for " + email);

        User user(name, email);
        repository->saveUser(user.getName(), user.getEmail());

        emailService->sendWelcomeEmail(email);

        logger->log("User registration completed for " + email);
    }
};

int main() {
    UserRepository repository;
    EmailService emailService;
    Logger logger;

    UserService userService(&repository, &emailService, &logger);

    userService.registerUser("John Doe", "john@example.com");

    return 0;
}
