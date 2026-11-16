
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
using namespace std;

// Base class for custom banking exceptions
class BankingException : public runtime_error {
public:
    explicit BankingException(const string& message)
        : runtime_error(message) {}
};

// Exception for zero or negative amounts
class InvalidAmount : public BankingException {
public:
    InvalidAmount()
        : BankingException(
            "Amount must be greater than zero") {}
};

// Exception for insufficient account balance
class InsufficientFunds : public BankingException {
public:
    InsufficientFunds()
        : BankingException(
            "Insufficient funds for withdrawal") {}
};

class BankAccount {
private:
    double balance;

public:
    explicit BankAccount(double initialBalance)
        : balance(initialBalance) {
        if (initialBalance < 0) {
            throw InvalidAmount();
        }
    }

    void withdraw(double amount) {
        // Validate the amount first.
        if (amount <= 0) {
            throw InvalidAmount();
        }

        // Check balance before changing it.
        if (amount > balance) {
            throw InsufficientFunds();
        }

        balance -= amount;

        cout << "Withdrawal successful: "
             << amount << '\n';
    }

    double getBalance() const {
        return balance;
    }
};

// Performs a transaction and handles specific errors.
void attemptWithdrawal(
    BankAccount& account, double amount
) {
    cout << "\nAttempting withdrawal: "
         << amount << '\n';

    try {
        account.withdraw(amount);
    }
    catch (const InvalidAmount& e) {
        cout << "InvalidAmount caught: "
             << e.what() << '\n';
    }
    catch (const InsufficientFunds& e) {
        cout << "InsufficientFunds caught: "
             << e.what() << '\n';
    }

    cout << "Current balance: "
         << account.getBalance() << '\n';
}

int main() {
    cout << "Name: TANISHQ PARATE\n";
    cout << "\n--- Custom Exceptions: Banking Transaction ---\n";

    cout << fixed << setprecision(2);

    BankAccount account(5000.0);

    cout << "Initial balance: "
         << account.getBalance() << '\n';

    // Test 1: Successful withdrawal
    attemptWithdrawal(account, 1500.0);

    // Test 2: Negative amount
    attemptWithdrawal(account, -200.0);

    // Test 3: Insufficient funds
    attemptWithdrawal(account, 6000.0);

    // Test 4: Zero amount
    attemptWithdrawal(account, 0.0);

    cout << "\nFinal balance: "
         << account.getBalance() << '\n';

    return 0;
}
