
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

struct Student {
    int id;
    string name;
    int marks;
};

int main() {
    cout << "Name: TANISHQ PARATE\n";
    cout << "\n--- CSV Student Records and File Positions ---\n";

    const string csvFile = "students.csv";

    const vector<Student> students = {
        {1001, "Rahul Sharma", 85},
        {1002, "Priya Patil", 92},
        {1003, "Aman Joshi", 78}
    };

    // PART 1: Write student records into CSV.
    fstream writer(csvFile, ios::out | ios::trunc);

    if (!writer.is_open()) {
        cerr << "Error: Cannot create students.csv\n";
        return 1;
    }

    writer << "ID,Name,Marks\n";

    for (const Student& student : students) {
        writer << student.id << ','
               << student.name << ','
               << student.marks << '\n';
    }

    writer.flush();

    if (!writer) {
        cerr << "Error: Failed to write students.csv\n";
        return 1;
    }

    writer.close();

    if (writer.fail()) {
        cerr << "Error: Failed to close students.csv\n";
        return 1;
    }

    cout << "Wrote 3 students to students.csv\n";

    // PART 2: Read and validate the CSV records.
    fstream reader(csvFile, ios::in);

    if (!reader.is_open()) {
        cerr << "Error: Cannot open students.csv\n";
        return 1;
    }

    string line;

    if (!getline(reader, line) ||
        line != "ID,Name,Marks") {
        cerr << "Error: Missing or invalid CSV header\n";
        return 1;
    }

    cout << "\nRecords read from CSV:\n";
    cout << "ID | Name | Marks\n";

    int count = 0;

    while (getline(reader, line)) {
        if (line.empty()) {
            continue;
        }

        string idText, name, marksText, extra;
        stringstream row(line);

        if (!getline(row, idText, ',') ||
            !getline(row, name, ',') ||
            !getline(row, marksText, ',') ||
            getline(row, extra, ',')) {

            cerr << "Warning: Skipped malformed record\n";
            continue;
        }

        try {
            size_t idEnd = 0;
            size_t marksEnd = 0;

            int id = stoi(idText, &idEnd);
            int marks = stoi(marksText, &marksEnd);

            if (idEnd != idText.size() ||
                marksEnd != marksText.size() ||
                id <= 0 ||
                name.empty() ||
                marks < 0 || marks > 100) {

                throw invalid_argument("Invalid values");
            }

            cout << id << " | "
                 << name << " | "
                 << marks << '\n';

            ++count;
        }
        catch (const exception&) {
            cerr << "Warning: Skipped malformed record\n";
        }
    }

    if (reader.bad()) {
        cerr << "Error: Failed while reading students.csv\n";
        return 1;
    }

    reader.close();

    cout << "Total valid records: "
         << count << '\n';

    // PART 3: Demonstrate file-position functions.
    fstream positions(
        "positions.txt",
        ios::in | ios::out | ios::trunc
    );

    if (!positions.is_open()) {
        cerr << "Error: Cannot create positions.txt\n";
        return 1;
    }

    positions << "ABCDE";

    if (!positions) {
        cerr << "Error: Cannot write positions.txt\n";
        return 1;
    }

    cout << "\n--- File Position Demonstration ---\n";

    // tellp(): current writing position
    cout << "tellp() after writing ABCDE: "
         << positions.tellp() << '\n';

    // seekp(): move writing position
    positions.seekp(2, ios::beg);

    cout << "tellp() after seekp(2): "
         << positions.tellp() << '\n';

    // Overwrite C with Z
    positions.put('Z');
    positions.flush();

    if (!positions) {
        cerr << "Error: Failed to update positions.txt\n";
        return 1;
    }

    // seekg(): move reading position
    positions.seekg(0, ios::beg);

    cout << "tellg() after seekg(0): "
         << positions.tellg() << '\n';

    char first, second;
    positions.get(first);
    positions.get(second);

    cout << "tellg() after reading 2 characters: "
         << positions.tellg() << '\n';

    // Read the complete updated file
    positions.seekg(0, ios::beg);

    string result;
    getline(positions, result);

    cout << "File contents after overwrite: "
         << result << '\n';

    positions.close();

    cout << "\nFile operations completed successfully.\n";

    return 0;
}
