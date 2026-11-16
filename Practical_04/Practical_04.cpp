
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Student {
private:
    string name;

public:
    explicit Student(const string& studentName)
        : name(studentName) {
        cout << "Student object created: " << name << '\n';
    }

    ~Student() {
        cout << "Student object destroyed: " << name << '\n';
    }

    void display() const {
        cout << "Student Name: " << name << '\n';
    }
};

int main() {
    cout << "Name: TANISHQ PARATE\n";
    cout << "\n--- RAII and Smart Pointers ---\n";

    // 1. Raw pointer: requires manual cleanup.
    cout << "\n1. Raw Pointer Example\n";
    {
        Student* rawStudent = new Student("Rahul");
        rawStudent->display();

        delete rawStudent;
        rawStudent = nullptr;
    }

    // 2. unique_ptr: one exclusive owner.
    cout << "\n2. unique_ptr Example\n";
    {
        unique_ptr<Student> student =
            make_unique<Student>("Priya");

        student->display();

        cout << "unique_ptr owns the object.\n";
    }
    cout << "unique_ptr scope ended.\n";

    // 3. shared_ptr: multiple owners.
    cout << "\n3. shared_ptr Example\n";
    {
        // Two classroom services share the same student.
        shared_ptr<Student> student =
            make_shared<Student>("Aman");

        cout << "Owner count initially: "
             << student.use_count() << '\n';

        {
            shared_ptr<Student> attendanceService = student;
            shared_ptr<Student> gradeService = student;

            cout << "Owner count after sharing: "
                 << student.use_count() << '\n';

            attendanceService->display();
            gradeService->display();
        }

        cout << "Owner count after services end: "
             << student.use_count() << '\n';
    }

    cout << "\nEnd of program.\n";

    return 0;
}
