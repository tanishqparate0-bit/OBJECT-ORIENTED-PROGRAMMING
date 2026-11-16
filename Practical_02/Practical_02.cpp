
#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
using namespace std;

class BankAccount {
private:
    // Private: protects account details from direct access.
    int accountNumber;
    string holderName;
    double balance;

public:
    // Public: allows controlled access to account operations.
    BankAccount(int number, string name, double initialBalance)
        : accountNumber(number),
          holderName(name),
          balance(initialBalance) {

        if (number <= 0 || initialBalance < 0) {
            throw invalid_argument("Invalid account details");
        }
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount.\n";
            return;
        }

        balance += amount;
        cout << "Deposited: " << amount << '\n';
    }

    void withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            cout << "Withdrawal failed: Invalid amount "
                 << "or insufficient balance.\n";
            return;
        }

        balance -= amount;
        cout << "Withdrawn: " << amount << '\n';
    }

    void display() const {
        cout << "\nAccount Number: " << accountNumber << '\n';
        cout << "Account Holder: " << holderName << '\n';
        cout << "Balance: " << fixed << setprecision(2)
             << balance << '\n';
    }
};

int main() {
    cout << "Name: TANISHQ PARATE\n";
    cout << "\n--- Bank Account Management ---\n";

    BankAccount account1(1001, "Rahul Sharma", 5000);
    BankAccount account2(1002, "Priya Patil", 3000);

    cout << "\nInitial Account Details:\n";
    account1.display();
    account2.display();

    cout << "\nTransactions for Account 1001:\n";
    account1.deposit(1500);
    account1.withdraw(2000);

    cout << "\nTransactions for Account 1002:\n";
    account2.deposit(500);
    account2.withdraw(4000);

    cout << "\nUpdated Account Details:\n";
    account1.display();
    account2.display();

    return 0;
}
