#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

struct Student {
    int id;
    string name;
    string course;
    int marks;
};

class PortalBase {
public:
    virtual void listStudents() const = 0;
    virtual ~PortalBase() = default;
};

class StudentPortal : public PortalBase {
private:
    vector<Student> students;
    string filename;

    static void validate(const Student& s) {
        if (s.id <= 0 || s.name.empty() || s.course.empty() ||
            s.name.find(',') != string::npos ||
            s.course.find(',') != string::npos ||
            s.marks < 0 || s.marks > 100) {
            throw invalid_argument("Invalid student details");
        }
    }

public:
    explicit StudentPortal(string file) : filename(file) {}

    void addStudent(const Student& s) {
        validate(s);
        for (const auto& existing : students) {
            if (existing.id == s.id) {
                throw invalid_argument("Student ID already exists");
            }
        }
        students.push_back(s);
    }

    void searchStudent(int id) const {
        for (const auto& s : students) {
            if (s.id == id) {
                cout << "Found: " << s.id << " | " << s.name << " | "
                     << s.course << " | " << s.marks << " | "
                     << (s.marks >= 40 ? "Pass" : "Fail") << '\n';
                return;
            }
        }
        throw out_of_range("Student ID not found");
    }

    void listStudents() const override {
        if (students.empty()) {
            cout << "No student records available.\n";
            return;
        }
        cout << "ID | Name | Course | Marks | Result\n";
        for (const auto& s : students) {
            cout << s.id << " | " << s.name << " | " << s.course
                 << " | " << s.marks << " | "
                 << (s.marks >= 40 ? "Pass" : "Fail") << '\n';
        }
    }

    void save() const {
        ofstream out(filename, ios::trunc);
        if (!out) throw runtime_error("Could not open CSV for writing");
        out << "ID,Name,Course,Marks\n";
        for (const auto& s : students) {
            out << s.id << ',' << s.name << ',' << s.course << ','
                << s.marks << '\n';
        }
        out.flush();
        if (!out) throw runtime_error("Could not save CSV data");
    }

    void load() {
        ifstream in(filename);
        if (!in) {
            cout << "No existing CSV found; starting with empty records.\n";
            return;
        }
        string line;
        if (!getline(in, line) || line != "ID,Name,Course,Marks") {
            throw runtime_error("CSV header is invalid");
        }
        vector<Student> loaded;
        while (getline(in, line)) {
            if (line.empty()) continue;
            string idText, name, course, marksText, extra;
            stringstream row(line);
            if (!getline(row, idText, ',') || !getline(row, name, ',') ||
                !getline(row, course, ',') || !getline(row, marksText, ',') ||
                getline(row, extra, ',')) {
                throw runtime_error("Malformed CSV row");
            }
            try {
                size_t p1 = 0, p2 = 0;
                int id = stoi(idText, &p1), marks = stoi(marksText, &p2);
                if (p1 != idText.size() || p2 != marksText.size())
                    throw invalid_argument("Bad number");
                Student s{id, name, course, marks};
                validate(s);
                for (const auto& existing : loaded)
                    if (existing.id == s.id)
                        throw invalid_argument("Duplicate ID");
                loaded.push_back(s);
            } catch (const exception&) {
                throw runtime_error("Invalid data in CSV row");
            }
        }
        if (in.bad()) throw runtime_error("CSV read failed");
        students = move(loaded);
        cout << "Loaded " << students.size() << " student(s) from CSV.\n";
    }
};

int main() {
    cout << "Name: TANISHQ PARATE\n";
    cout << "\n--- Student Portal Mini Project ---\n";
    StudentPortal portal("portal_students.csv");
    try { portal.load(); }
    catch (const exception& e) {
        cerr << "Load error: " << e.what() << '\n';
        return 1;
    }

    PortalBase& view = portal; // Runtime polymorphism
    while (true) {
        cout << "\n1. Add Student\n2. List Students\n3. Search Student\n4. Save and Exit\nChoice: ";
        int choice;
        if (!(cin >> choice)) {
            cout << "Invalid menu input.\n";
            return 1;
        }
        try {
            if (choice == 1) {
                Student s;
                cout << "Student ID: ";
                if (!(cin >> s.id)) throw invalid_argument("Invalid ID input");
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Name: ";
                getline(cin, s.name);
                cout << "Course: ";
                getline(cin, s.course);
                cout << "Marks (0-100): ";
                if (!(cin >> s.marks)) throw invalid_argument("Invalid marks input");
                portal.addStudent(s);
                portal.save();
                cout << "Student added and saved.\n";
            } else if (choice == 2) {
                view.listStudents();
            } else if (choice == 3) {
                int id;
                cout << "Enter Student ID: ";
                if (!(cin >> id)) throw invalid_argument("Invalid ID input");
                portal.searchStudent(id);
            } else if (choice == 4) {
                portal.save();
                cout << "Records saved. Goodbye!\n";
                break;
            } else {
                cout << "Invalid menu choice.\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << '\n';
            if (!cin) return 1;
        }
    }
}
