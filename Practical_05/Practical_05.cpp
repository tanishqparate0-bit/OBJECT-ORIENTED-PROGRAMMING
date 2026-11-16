
#include <iostream>
#include <string>
using namespace std;

// Base class: stores common personal information.
class Person {
protected:
    string name;
    int age;

public:
    Person(const string& n, int a)
        : name(n), age(a) {}

    void displayPerson() const {
        cout << "Name: " << name << '\n';
        cout << "Age: " << age << '\n';
    }
};

// Student inherits from Person (single inheritance).
class Student : public Person {
protected:
    int studentId;
    string course;

public:
    Student(const string& n, int a,
            int id, const string& c)
        : Person(n, a), studentId(id), course(c) {}

    void displayStudent() const {
        displayPerson();
        cout << "Student ID: " << studentId << '\n';
        cout << "Course: " << course << '\n';
    }
};

// GraduateStudent inherits from Student.
// This creates multilevel inheritance.
class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    GraduateStudent(const string& n, int a,
                    int id, const string& c,
                    const string& topic)
        : Student(n, a, id, c),
          researchTopic(topic) {}

    void displayGraduateStudent() const {
        displayStudent();
        cout << "Research Topic: "
             << researchTopic << '\n';
    }
};

int main() {
    cout << "Name: TANISHQ PARATE\n";
    cout << "\n--- Single and Multilevel Inheritance ---\n";

    Student student(
        "Rahul Sharma", 20, 1001, "B.Tech CSE"
    );

    GraduateStudent graduate(
        "Priya Patil", 24, 2001,
        "M.Tech AI", "Machine Learning"
    );

    cout << "\n1. Single Inheritance Example:\n";
    student.displayStudent();

    cout << "\n2. Multilevel Inheritance Example:\n";
    graduate.displayGraduateStudent();

    return 0;
}
