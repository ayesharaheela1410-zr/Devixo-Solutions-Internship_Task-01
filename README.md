# Devixo-Solutions-Internship_Task-01
Devixo-Solutions - C++ Internship Task-01


## Project Overview

The Student Record Management System is a menu-driven C++ application developed for **Devixo Solutions Internship — Task 01**. It allows users to manage student records through a console interface and store records in a text file.

## Objectives

- Develop a console-based student record management application.
- Apply C++ structures, arrays, functions, loops, and conditional statements.
- Implement file handling to save and load student records.
- Validate user input and handle common errors.

## Features

- **Add Student:** Add a student using an ID, name, and marks.
- **View Students:** Display all available student records in a formatted table.
- **Search Student:** Find a student by ID.
- **Update Student:** Modify a student's name and marks.
- **Delete Student:** Remove a student record by ID.
- **Save Records:** Store student records in a text file.
- **Load Records:** Load previously saved records when the program starts.
- **Input Validation:** Reject invalid menu input, duplicate IDs, non-positive IDs, and marks outside the range of 0–100.
- **Error Handling:** Handle searches and deletion attempts for IDs that do not exist.

## Technologies Used

- **Language:** C++
- **Compiler/Development Environment:** CodeUtility online C++ compiler
- **Libraries:** `iostream`, `string`, `fstream`, `sstream`, `limits`, and `iomanip`

## Project Files

| File | Description |
|---|---|
| `main.cpp` | Main C++ source code |
| `students.txt` | Text file used to store student records |
| `README.md` | Project description and instructions |
| `screenshots/` | Program output and implementation evidence |
| `Devixo_Task01_Report.pdf` | Project documentation report |

## How to Compile and Run

Make sure a C++ compiler such as GCC is installed on your computer.

**Compile using GCC:**

```bash
g++ main.cpp -o student_records
```

**Run on Windows:**

```bash
student_records.exe
```

**Run on Linux/macOS:**

```bash
./student_records
```

Alternatively, open `main.cpp` in a compatible online C++ compiler and run the program there.

## How to Use

1. Run the program.
2. Choose an operation from the menu.
3. Enter the requested student information or ID.
4. Follow the on-screen prompts.
5. Choose the save or exit option to finish.

## File Handling

The application uses `students.txt` to store student records. Saved records can be loaded when the program starts, provided the file remains available in the program's working environment.

Each record is stored as text using a delimiter-based format. The program uses file input and output operations to read and write the records.

## Input Validation and Testing

The program has been tested for the following operations:

- Adding and viewing student records.
- Searching for an existing student.
- Updating and deleting a student record.
- Rejecting duplicate student IDs.
- Rejecting zero and negative student IDs.
- Rejecting marks outside the 0–100 range.
- Handling invalid menu input.
- Handling searches and deletion attempts for nonexistent IDs.
- Saving and loading records across executions in the persistent workspace.

## Learning Outcomes

This project demonstrates the practical application of fundamental C++ concepts, including structures, arrays, functions, input validation, and file handling. It also develops problem-solving skills through implementing common student record operations.

## Screenshots

Project screenshots showing source code, program outputs, file handling, and input-validation tests are available in the [`screenshots`](./screenshots/) folder.

## Conclusion

The Student Record Management System provides a simple way to manage student information through a console-based interface. The project applies core C++ programming concepts to a practical problem and demonstrates record creation, retrieval, modification, deletion, and persistent storage.

---

**Internship Organization:** Devixo Solutions  
**Task:** Task 01 — Student Record Management System  
**Submitted by:** Ayesha Raheela
