
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
using namespace std;

// Common interface for all notification types.
class Notification {
public:
    virtual void send(const string& message) const = 0;
    virtual string type() const = 0;
    virtual ~Notification() = default;
};

// Concrete notification type 1.
class EmailNotification : public Notification {
public:
    void send(const string& message) const override {
        cout << "Email sent: " << message << '\n';
    }

    string type() const override {
        return "Email";
    }
};

// Concrete notification type 2.
class SMSNotification : public Notification {
public:
    void send(const string& message) const override {
        cout << "SMS sent: " << message << '\n';
    }

    string type() const override {
        return "SMS";
    }
};

// Factory centralizes notification object creation.
class NotificationFactory {
public:
    static unique_ptr<Notification> create(
        const string& choice
    ) {
        if (choice == "email") {
            return make_unique<EmailNotification>();
        }

        if (choice == "sms") {
            return make_unique<SMSNotification>();
        }

        throw invalid_argument(
            "Unknown notification type: " + choice
        );
    }
};

int main() {
    cout << "Name: TANISHQ PARATE\n";
    cout << "\n--- Factory Design Pattern ---\n";

    // Factory call 1: create an email notification.
    auto email = NotificationFactory::create("email");

    cout << "Created: " << email->type() << '\n';
    email->send("Practical 08 completed");

    // Factory call 2: create an SMS notification.
    auto sms = NotificationFactory::create("sms");

    cout << "Created: " << sms->type() << '\n';
    sms->send("Assignment reminder");

    // Demonstrate an invalid notification type.
    try {
        auto invalid =
            NotificationFactory::create("push");

        invalid->send("Not delivered");
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << '\n';
    }

    return 0;
}
