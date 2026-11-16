# OBJECT-ORIENTED-PROGRAMMING

# C++ Practical Programs

**Student:** TANISHQ PARATE  
**Roll Number:** 46  
**Department:** Artificial Intelligence & Data Science  
**Academic Year:** 2026–2027

## Practical 01 — GitHub Setup and C++ Fundamentals

### Aim

To practise basic C++ syntax and learn how to track code changes using Git and GitHub.

### Concepts Demonstrated

- Variables and data types
- Constants
- Arithmetic, relational and logical operators
- User input using `cin`
- Output using `cout`
- Conditional statements

### Compilation

```powershell
g++ -std=c++17 Practical_01/Practical_01.cpp -o Practical_01/practical01.exe
```

### Execution (Windows)

```powershell
.\Practical_01\practical01.exe
```

### Sample Input

Quantity: 3  
Unit Price: 120  
Membership: 1

### Expected Result

The final amount after a 10% discount is ₹324.00 when the eligible purchase subtotal is ₹360.00.


## Practical 02 — Classes, Access Specifiers and Member Functions

**Aim:** To understand how classes combine data and behaviour, and how access specifiers protect data.

**Program:** Bank Account Management System

**Concepts demonstrated:**
- Classes and objects
- Private and public access specifiers
- Parameterized constructors
- Encapsulation
- Member functions
- Input validation

**Compilation:**
`g++ -std=c++17 Practical_02/Practical_02.cpp -o Practical_02/practical02.exe`

**Execution:**
`.\Practical_02\practical02.exe`

**Result:** Successfully demonstrated two bank account objects with valid deposit and withdrawal operations and protection against invalid transactions.

## Practical 03 — Constructors and Rule of Five

**Aim:** To understand object creation, copying, moving, and safe management of dynamically allocated memory.

**Program:** Dynamic Integer Array Using the Rule of Five

**Concepts demonstrated:**
- Default and parameterized constructors
- Copy constructor and deep copying
- Copy assignment operator
- Move constructor
- Move assignment operator
- Destructor and dynamic memory management

**Compilation:**

`g++ -std=c++17 -Wall -Wextra Practical_03/Practical_03.cpp -o Practical_03/practical03.exe`

**Execution (Windows):**

`.\Practical_03\practical03.exe`

**Result:** The program demonstrates deep copying, ownership transfer through move operations, and automatic resource cleanup using a destructor.

## Practical 04 — RAII and Smart Pointers

**Aim:** To learn how RAII ties resource lifetime to object lifetime and reduces manual memory-management errors.

**Program:** Student Object Memory Management Using Smart Pointers

**Concepts demonstrated:**
- Raw pointers and manual memory management
- `std::unique_ptr` and exclusive ownership
- `std::shared_ptr` and reference counting
- RAII and scope-based resource cleanup
- Object constructors and destructors

**Compilation:**

`g++ -std=c++17 -Wall -Wextra Practical_04/Practical_04.cpp -o Practical_04/practical04.exe`

**Execution:**

`.\Practical_04\practical04.exe`

**Result:** The program demonstrates that smart pointers automatically manage object lifetime and reduce the need for manual `delete` operations.

## Practical 05 — Single and Multilevel Inheritance

**Aim:** To understand base and derived classes and how data and behaviour can be reused.

**Program:** University Student Management Using Inheritance

**Concepts Demonstrated:**
- Base and derived classes
- Single inheritance
- Multilevel inheritance
- Protected data members
- Constructor chaining
- Reusing inherited member functions

**Class Hierarchy:** Person → Student → GraduateStudent

**Compilation:**

`g++ -std=c++17 -Wall -Wextra Practical_05/Practical_05.cpp -o Practical_05/practical05.exe`

**Execution:**

`.\Practical_05\practical05.exe`

**Result:** The program demonstrates single and multilevel inheritance by displaying Student and GraduateStudent information through inherited member functions.

## Practical 06 — Runtime Polymorphism and Abstract Classes

**Aim:** To demonstrate how a base-class interface can be used to call the correct derived-class function at runtime.

**Program:** Area Calculation Using Abstract Shape Class

**Concepts Demonstrated:**
- Abstract base classes
- Pure virtual functions
- Virtual destructors
- Method overriding
- Runtime polymorphism
- Base-class pointers and smart pointers

**Compilation:**

`g++ -std=c++17 -Wall -Wextra Practical_06/Practical_06.cpp -o Practical_06/practical06.exe`

**Execution:**

`.\Practical_06\practical06.exe`

**Result:** Successfully demonstrated runtime polymorphism by calculating the areas of Circle, Rectangle, and Triangle objects using the common Shape interface.

## Practical 07 — Compile-Time Polymorphism: Overloading

**Aim:** To understand how C++ selects functions at compile time based on parameters and operator definitions.

**Program:** Function Overloading and Complex Number Addition

**Concepts Demonstrated:**
- Function overloading
- Operator overloading
- Compile-time polymorphism
- Classes and constructors
- Addition of complex numbers

**Compilation:**

`g++ -std=c++17 -Wall -Wextra -pedantic Practical_07/Practical_07.cpp -o Practical_07/practical07.exe`

**Execution (Windows):**

`.\Practical_07\practical07.exe`

**Result:** The program demonstrates function overloading using integer and double addition, and operator overloading using the addition of two ComplexNumber objects.

## Practical 08 — Factory Design Pattern

**Aim:** To practise applying a common object-creation design pattern.

**Program:** Notification System Using the Factory Pattern

**Concepts Demonstrated:**
- Factory design pattern
- Abstract classes and interfaces
- Object creation through a factory
- Runtime polymorphism
- Smart pointers
- Exception handling

**Implementation:** The NotificationFactory class creates either an EmailNotification or SMSNotification object based on the requested type.

**Compilation:**

`g++ -std=c++17 -Wall -Wextra -pedantic Practical_08/Practical_08.cpp -o Practical_08/practical08.exe`

**Execution (Windows):**

`.\Practical_08\practical08.exe`

**Benefit:** Centralizes object creation and reduces direct dependencies on concrete notification classes.

**Trade-off:** Adds extra classes and conditional factory logic.

**Result:** Successfully demonstrated the Factory design pattern by creating and using two notification types through a common interface.

## Practical 09 — Generic Stack Using Templates

**Aim:** To understand generic programming and how one class can work with multiple data types.

**Program:** Generic Stack Implementation Using Templates and STL Vector

**Concepts Demonstrated:**
- Class templates
- Generic programming
- Stack data structure
- LIFO (Last In, First Out)
- STL vector
- Exception handling
- Testing integer, float, and string values

**Compilation:**

`g++ -std=c++17 -Wall -Wextra -pedantic Practical_09/Practical_09.cpp -o Practical_09/practical09.exe`

**Execution (Windows):**

`.\Practical_09\practical09.exe`

**Result:** The program successfully demonstrated a reusable Stack template with integer, float, and string values. Empty-stack operations were handled using exceptions.

## Practical 10 — Custom Exceptions: Banking Transaction

**Aim:** To practise reporting application-specific failures and handling different errors in a controlled way.

**Program:** Bank Account Withdrawal Using Custom Exceptions

**Concepts Demonstrated:**
- Custom exception classes
- Exception inheritance hierarchy
- `try`, `throw`, and `catch`
- Separate exception handlers
- Banking transaction validation
- Maintaining account balance after failed transactions

**Compilation:**

`g++ -std=c++17 -Wall -Wextra -pedantic Practical_10/Practical_10.cpp -o Practical_10/practical10.exe`

**Execution (Windows):**

`.\Practical_10\practical10.exe`

**Test Results:**
- Withdrawal of 1500: Successful
- Withdrawal of -200: InvalidAmount exception
- Withdrawal of 6000: InsufficientFunds exception
- Withdrawal of 0: InvalidAmount exception
- Final balance: 3500.00

**Result:** The program demonstrates custom exception handling and ensures failed withdrawals do not modify the account balance.