
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class Shape {
public:
    // Pure virtual function makes Shape abstract.
    virtual double area() const = 0;

    virtual string getName() const = 0;

    // Virtual destructor ensures correct cleanup.
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double r) : radius(r) {
        if (r <= 0) {
            throw invalid_argument("Invalid radius");
        }
    }

    double area() const override {
        const double PI = 3.141592653589793;
        return PI * radius * radius;
    }

    string getName() const override {
        return "Circle";
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w)
        : length(l), width(w) {
        if (l <= 0 || w <= 0) {
            throw invalid_argument("Invalid rectangle dimensions");
        }
    }

    double area() const override {
        return length * width;
    }

    string getName() const override {
        return "Rectangle";
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h)
        : base(b), height(h) {
        if (b <= 0 || h <= 0) {
            throw invalid_argument("Invalid triangle dimensions");
        }
    }

    double area() const override {
        return 0.5 * base * height;
    }

    string getName() const override {
        return "Triangle";
    }
};

int main() {
    cout << "Name: TANISHQ PARATE\n";
    cout << "\n--- Runtime Polymorphism ---\n";

    vector<unique_ptr<Shape>> shapes;

    shapes.push_back(make_unique<Circle>(5));
    shapes.push_back(make_unique<Rectangle>(4, 6));
    shapes.push_back(make_unique<Triangle>(8, 5));

    cout << fixed << setprecision(2);

    for (const auto& shape : shapes) {
        cout << shape->getName()
             << " Area: " << shape->area()
             << '\n';
    }

    cout << "\nArea calculated using Shape pointers.\n";

    return 0;
}
