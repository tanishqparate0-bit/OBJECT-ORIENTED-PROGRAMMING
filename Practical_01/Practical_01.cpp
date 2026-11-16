
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "Name: TANISHQ PARATE\n";
    cout << "\n--- C++ Fundamentals ---\n";

    const double DISCOUNT_RATE = 0.10;

    int quantity;
    double price;
    bool member;

    cout << "Enter quantity: ";
    cin >> quantity;

    cout << "Enter unit price: ";
    cin >> price;

    cout << "Are you a member? (1 = Yes, 0 = No): ";
    cin >> member;

    if (!cin || quantity <= 0 || price < 0) {
        cout << "Invalid input.\n";
        return 1;
    }

    double subtotal = quantity * price;
    bool eligible = member && (subtotal >= 300);
    double discount = eligible
        ? subtotal * DISCOUNT_RATE : 0.0;
    double total = subtotal - discount;

    cout << fixed << setprecision(2);
    cout << "\n--- BILL SUMMARY ---\n";
    cout << "Quantity: " << quantity << '\n';
    cout << "Unit Price: " << price << '\n';
    cout << "Subtotal: " << subtotal << '\n';
    cout << "Eligible for discount: "
         << (eligible ? "Yes" : "No") << '\n';
    cout << "Discount: " << discount << '\n';
    cout << "Final Total: " << total << '\n';

    return 0;
}
