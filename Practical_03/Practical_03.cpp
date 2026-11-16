
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstddef>
using namespace std;

class DynamicArray {
private:
    int* data;
    size_t size;

public:
    // Default constructor
    DynamicArray() : data(nullptr), size(0) {
        cout << "Default constructor called\n";
    }

    // Parameterized constructor
    explicit DynamicArray(size_t n)
        : data(n ? new int[n]{} : nullptr), size(n) {
        cout << "Parameterized constructor called\n";
    }

    // 1. Destructor: releases owned memory
    ~DynamicArray() {
        delete[] data;
    }

    // 2. Copy constructor: performs a deep copy
    DynamicArray(const DynamicArray& other)
        : data(other.size ? new int[other.size] : nullptr),
          size(other.size) {
        if (size > 0) {
            copy(other.data, other.data + size, data);
        }
        cout << "Copy constructor called\n";
    }

    // 3. Copy assignment: copy-and-swap technique
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            DynamicArray temp(other);
            swap(data, temp.data);
            swap(size, temp.size);
        }

        cout << "Copy assignment called\n";
        return *this;
    }

    // 4. Move constructor: transfers ownership
    DynamicArray(DynamicArray&& other) noexcept
        : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        cout << "Move constructor called\n";
    }

    // 5. Move assignment: releases old memory,
    // then transfers ownership
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] data;

            data = other.data;
            size = other.size;

            other.data = nullptr;
            other.size = 0;
        }

        cout << "Move assignment called\n";
        return *this;
    }

    void set(size_t index, int value) {
        if (index < size) {
            data[index] = value;
        }
    }

    void display() const {
        cout << "Array: ";

        if (size == 0) {
            cout << "(empty)";
        }

        for (size_t i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }

        cout << '\n';
    }
};

int main() {
    cout << "Name: TANISHQ PARATE\n";
    cout << "\n--- Constructors and Rule of Five ---\n";

    // Default constructor
    DynamicArray empty;
    empty.display();

    // Parameterized constructor
    DynamicArray original(3);
    original.set(0, 10);
    original.set(1, 20);
    original.set(2, 30);

    cout << "\nOriginal ";
    original.display();

    // Copy constructor
    DynamicArray copied(original);

    // Modify the copy to demonstrate deep copying
    copied.set(0, 99);

    cout << "After modifying copied array:\n";
    cout << "Original ";
    original.display();
    cout << "Copied ";
    copied.display();

    // Copy assignment
    DynamicArray assigned;
    assigned = original;

    cout << "\nCopy assigned ";
    assigned.display();

    // Move constructor
    DynamicArray moved(std::move(copied));

    cout << "\nMove constructed ";
    moved.display();
    cout << "Moved-from copied ";
    copied.display();

    // Move assignment
    DynamicArray moveAssigned;
    moveAssigned = std::move(assigned);

    cout << "\nMove assigned ";
    moveAssigned.display();
    cout << "Moved-from assigned ";
    assigned.display();

    cout << "\nEnd of program. Destructors release memory.\n";

    return 0;
}
