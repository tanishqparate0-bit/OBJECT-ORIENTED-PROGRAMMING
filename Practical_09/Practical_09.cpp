
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

// Generic Stack class template
template <typename T>
class Stack {
private:
    vector<T> items;

public:
    // Push an element onto the stack
    void push(const T& value) {
        items.push_back(value);
    }

    // Remove the top element
    void pop() {
        if (empty()) {
            throw out_of_range(
                "Cannot pop: stack is empty"
            );
        }
        items.pop_back();
    }

    // Safely access the top element
    const T& top() const {
        if (empty()) {
            throw out_of_range(
                "Cannot access top: stack is empty"
            );
        }
        return items.back();
    }

    // Check whether the stack is empty
    bool empty() const {
        return items.empty();
    }
};

int main() {
    cout << "Name: TANISHQ PARATE\n";
    cout << "\n--- Generic Stack Using Templates ---\n";

    // Test 1: Integer stack
    Stack<int> numbers;

    numbers.push(10);
    numbers.push(20);
    numbers.push(30);

    cout << "\nInteger stack top: "
         << numbers.top() << '\n';

    numbers.pop();

    cout << "After pop: "
         << numbers.top() << '\n';

    // Test 2: Float stack
    Stack<float> decimals;

    decimals.push(1.5f);
    decimals.push(2.75f);

    cout << "\nFloat stack top: "
         << decimals.top() << '\n';

    decimals.pop();

    cout << "After pop: "
         << decimals.top() << '\n';

    // Test 3: String stack
    Stack<string> words;

    words.push("C++");
    words.push("Templates");

    cout << "\nString stack top: "
         << words.top() << '\n';

    words.pop();

    cout << "After pop: "
         << words.top() << '\n';

    // Test 4: Empty stack error handling
    Stack<int> emptyStack;

    cout << "\nEmpty stack check: "
         << (emptyStack.empty() ? "Yes" : "No")
         << '\n';

    try {
        emptyStack.pop();
    }
    catch (const out_of_range& e) {
        cout << "Handled error: "
             << e.what() << '\n';
    }

    try {
        cout << emptyStack.top() << '\n';
    }
    catch (const out_of_range& e) {
        cout << "Handled error: "
             << e.what() << '\n';
    }

    return 0;
}
