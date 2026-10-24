#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <iomanip>
using namespace std;

const int MAX_STUDENTS = 100;
const string FILE_NAME = "students.txt";

// Structure for storing student information
struct Student {
    int id;
    string name;
    float marks;
};

Student students[MAX_STUDENTS];
int studentCount = 0;

// Read an integer safely
int readInt(string prompt) {
    int value;

    while (true) {
        cout << prompt;

        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cout << "Invalid input. Please enter a whole number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Read marks safely
float readMarks() {
    float marks;

    while (true) {
        cout << "Enter marks (0-100): ";

        if (cin >> marks) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (marks >= 0 && marks <= 100) {
                return marks;
            }

            cout << "Marks must be between 0 and 100.\n";
        } else {
            cout << "Invalid input. Enter numeric marks.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// Find a student by ID; return -1 if not found
int findStudent(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            return i;
        }
    }

    return -1;
}

// Display the menu
void showMenu() {
    cout << "\n====================================\n";
    cout << "   STUDENT RECORD MANAGEMENT SYSTEM\n";
    cout << "====================================\n";
    cout << "1. Add Student\n";
    cout << "2. View Students\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Save Records to File\n";
    cout << "7. Exit\n";
    cout << "====================================\n";
}

// Save all student records to a text file
bool saveRecords() {
    ofstream file(FILE_NAME.c_str());

    if (!file) {
        cout << "Error: Could not open the file for saving.\n";
        return false;
    }

    for (int i = 0; i < studentCount; i++) {
        file << students[i].id << '|'
             << students[i].marks << '|'
             << students[i].name << '\n';
    }

    file.close();

    if (!file) {
        cout << "Error occurred while writing the file.\n";
        return false;
    }

    cout << "Records saved successfully to "
         << FILE_NAME << ".\n";
    return true;
}

// Load previously saved records
void loadRecords() {
    ifstream file(FILE_NAME.c_str());

    if (!file) {
        cout << "No existing record file found. Starting fresh.\n";
        return;
    }

    string line;

    while (getline(file, line) &&
           studentCount < MAX_STUDENTS) {
        stringstream row(line);

        int id;
        float marks;
        char separator1, separator2;
        string name;

        if (row >> id >> separator1 >> marks >> separator2
            && separator1 == '|' && separator2 == '|'
            && getline(row, name)) {

            if (id > 0 && marks >= 0 && marks <= 100
                && !name.empty() && findStudent(id) == -1) {
                students[studentCount].id = id;
                students[studentCount].marks = marks;
                students[studentCount].name = name;
                studentCount++;
            }
        }
    }

    file.close();

    cout << studentCount
         << " student record(s) loaded.\n";
}

// Add a student
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Student storage is full.\n";
        return;
    }

    int id = readInt("Enter student ID: ");

    if (id <= 0) {
        cout << "Student ID must be positive.\n";
        return;
    }

    if (findStudent(id) != -1) {
        cout << "A student with this ID already exists.\n";
        return;
    }

    string name;
    cout << "Enter student name: ";
    getline(cin >> ws, name);

    if (name.empty()) {
        cout << "Name cannot be empty.\n";
        return;
    }

    float marks = readMarks();

    students[studentCount].id = id;
    students[studentCount].name = name;
    students[studentCount].marks = marks;
    studentCount++;

    cout << "Student added successfully!\n";

    // Save changes immediately
    saveRecords();
}

// View all students
void viewStudents() {
    if (studentCount == 0) {
        cout << "No student records available.\n";
        return;
    }

    cout << "\n-------------- STUDENT RECORDS --------------\n";
    cout << left << setw(12) << "ID"
         << setw(28) << "Name"
         << "Marks\n";
    cout << "----------------------------------------------\n";

    for (int i = 0; i < studentCount; i++) {
        cout << left << setw(12) << students[i].id
             << setw(28) << students[i].name
             << fixed << setprecision(2)
             << students[i].marks << '\n';
    }

    cout << "----------------------------------------------\n";
    cout << "Total students: " << studentCount << '\n';
}

// Search for a student
void searchStudent() {
    if (studentCount == 0) {
        cout << "No student records available to search.\n";
        return;
    }

    int id = readInt("Enter student ID to search: ");
    int index = findStudent(id);

    if (index == -1) {
        cout << "Student with ID " << id << " not found.\n";
        return;
    }

    cout << "\nStudent Found!\n";
    cout << "ID: " << students[index].id << '\n';
    cout << "Name: " << students[index].name << '\n';
    cout << "Marks: " << students[index].marks << '\n';
}

// Update a student's name and marks
void updateStudent() {
    if (studentCount == 0) {
        cout << "No student records available to update.\n";
        return;
    }

    int id = readInt("Enter student ID to update: ");
    int index = findStudent(id);

    if (index == -1) {
        cout << "Student with ID " << id << " not found.\n";
        return;
    }

    cout << "Current name: " << students[index].name << '\n';
    cout << "Current marks: " << students[index].marks << '\n';

    string newName;
    cout << "Enter new name: ";
    getline(cin >> ws, newName);

    if (newName.empty()) {
        cout << "Name cannot be empty. Update cancelled.\n";
        return;
    }

    float newMarks = readMarks();

    students[index].name = newName;
    students[index].marks = newMarks;

    cout << "Student record updated successfully!\n";
    saveRecords();
}

// Delete a student
void deleteStudent() {
    if (studentCount == 0) {
        cout << "No student records available to delete.\n";
        return;
    }

    int id = readInt("Enter student ID to delete: ");
    int index = findStudent(id);

    if (index == -1) {
        cout << "Student with ID " << id << " not found.\n";
        return;
    }

    cout << "Deleting student: "
         << students[index].name << '\n';

    for (int i = index; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }

    studentCount--;

    cout << "Student deleted successfully!\n";
    saveRecords();
}

int main() {
    loadRecords();

    int choice;

    do {
        showMenu();
        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                saveRecords();
                break;

            case 7:
                cout << "Saving records before exit...\n";
                saveRecords();
                cout << "Thank you for using the system. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please enter a number from 1 to 7.\n";
        }

    } while (choice != 7);

    return 0;
}