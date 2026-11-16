
#include <iostream>
#include <iomanip>
using namespace std;

// Function overloading: integer addition
int add(int a, int b) {
    return a + b;
}

// Function overloading: double addition
double add(double a, double b) {
    return a + b;
}

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    // Parameterized constructor
    ComplexNumber(double r = 0, double i = 0)
        : real(r), imaginary(i) {}

    // Operator overloading for adding complex numbers
    ComplexNumber operator+(
        const ComplexNumber& other
    ) const {
        return ComplexNumber(
            real + other.real,
            imaginary + other.imaginary
        );
    }

    void display() const {
        cout << real
             << (imaginary < 0 ? " - " : " + ")
             << (imaginary < 0 ? -imaginary : imaginary)
             << "i";
    }
};

int main() {
    cout << "Name: TANISHQ PARATE\n";
    cout << "\n--- Compile-Time Polymorphism ---\n";

    // Function overloading
    cout << "Integer addition: "
         << add(10, 20) << '\n';

    cout << fixed << setprecision(2);

    cout << "Double addition: "
         << add(2.5, 3.75) << '\n';

    // Operator overloading
    ComplexNumber c1(3, 4);
    ComplexNumber c2(2, -1);

    ComplexNumber sum = c1 + c2;

    cout << "\nFirst complex number: ";
    c1.display();

    cout << "\nSecond complex number: ";
    c2.display();

    cout << "\nSum: ";
    sum.display();

    cout << '\n';

    return 0;
}
