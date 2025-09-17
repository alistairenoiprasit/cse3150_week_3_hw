
#include <iostream>
#include <string>
#include <cstring>   // for strlen, strcpy

namespace GPAUtils {
    void addStudent(char* name, double gpa, char* names[], double
    gpas[], int& size, int capacity);
    void updateGPA(double* gpaPtr, double newGpa);
    void printStudent(const char* name, const double& gpa);
    double averageGPA(const double gpas[], int size);
}
char* getName();
// ASSUMPTIONS
// Throughout this code, id will be referenced:
// id = Index in the table.
// Using
using std::cout, std::endl, std::getline, std::string, std::cin;
// ////////////////////////// //
//         CONSTANTS          //
// ////////////////////////// //
// Const values # defines,
const int defaultGPA = 0;
const char* errorPrefix = "Error: ";
// ////////////////////////// //
//           Helpers          //
// ////////////////////////// //
char* getName() {
    cout << "Enter name: ";

    string temp;
    std::cin >> temp;

    char* name = new char[temp.size() + 1];
    strcpy(name, temp.c_str());
    return name;
}

double getGPA() {
    cout << "Enter GPA: ";
    double gpa;
    std::cin >> gpa;
    return gpa;
}

void validateAdditionalCapacity(int &size, int capacity) {
    if (!((size + 1) <= capacity)) {
        throw "List full";
    }
}

void setGPA(double gpa, double
    gpas[], int id) {
    gpas[id] = gpa;
}

void setName(char* name, char* names[], int id) {
    names[id] = (char*)malloc(strlen(name) + 1);
    strcpy(names[id], name);
}

void printErrorMsg(const char* msg) {
    std::cout << errorPrefix << msg << std::endl;
}

void printStudentIds(char* names[], int& size) {
    cout << "Student IDs: " << endl;
    for (int i = 0; i < size; i++) {
        std::cout << "[" << i << "] = " << names[i] << std::endl;
    }
}

double* getGPAPointerFromId(double gpas[], int& id) {
    return &gpas[id];
}

// ////////////////////////// //
//        CLI Facade          //
// ////////////////////////// //
void addStudentFacade(char* names[], double gpas[], int& size, int capacity) {
    validateAdditionalCapacity(size, capacity);
    char* name = getName();
    double GPA = getGPA();
    GPAUtils::addStudent(name, GPA, names, gpas, size, capacity);
    free(name);
}

void updateGPAFacade(char* names[], double gpas[], int& size) {
    printStudentIds(names, size);
    int studentId;
    cout << "Select Student ID: ";
    cin >> studentId;
    if (!(studentId >= 0 && studentId < size)) {
        throw "Student does not exist";
    }
    double* gpaPtr = getGPAPointerFromId(gpas, studentId);
    double newGPA = getGPA();
    GPAUtils::updateGPA(gpaPtr, newGPA);
    cout << "Success! Updated GPA." << std::endl;
}

void printAllStudentsFacade(char* names[], double gpas[], int& size) {
    if (size <= 0) {
        throw "No students";
    }
    cout << "--- LIST OF ALL STUDENTS" << endl;
    for (int i = 0; i < size; i++) {
        GPAUtils::printStudent(names[i], gpas[i]);
    }
    cout << "--- LIST OF ALL STUDENTS" << endl;
}

void avgStudentsGPAFacade(const double gpas[], int& size) {
    if (size <= 0) {
        throw "No students";
    }
    int sum = static_cast<int>(GPAUtils::averageGPA(gpas, size));
    cout << "Cumulative Students Average GPA: " << sum << std::endl;
}
// ////////////////////////// //
//         GPA Utils          //
// ////////////////////////// //
using namespace GPAUtils;
void GPAUtils::addStudent(char* name, double gpa, char* names[], double
    gpas[], int& size, int capacity) {
    setName(name, names, size);
    setGPA(gpa, gpas, size);
    size++;
}

void GPAUtils::updateGPA(double* gpaPtr, double newGpa) {
    *gpaPtr = newGpa;
}

void GPAUtils::printStudent(const char* name, const double& gpa) {
    cout << "Student: \"" << name << "\" GPA: " << gpa << std::endl;
}

double GPAUtils::averageGPA(const double gpas[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += gpas[i];
    }
    return sum/static_cast<double>(size);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;
    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";

        //std::cin >> choice;

        // I know we don't need to handle this... but I was getting annoyed so:
        // I wanted CTRL+D to end the program so I implemented this here
        // This doesn't handle all cases, but stops several infinite loops.
        if (!(std::cin >> choice)) {
            if (std::cin.eof()) {
                break;
            } else {
                std::cout << "Program terminating to prevent infinite looping. Something went wrong!" << std::endl;
                printErrorMsg("Menu input was not an integer.");
                return 1;
            }
        }

        switch (choice) {
            case 1: {
                try {
                    addStudentFacade(names, gpas, size, capacity);
                } catch (const char* msg) {
                    printErrorMsg(msg);
                }
                break;
            }
            case 2: {
                try {
                    updateGPAFacade(names, gpas, size);
                } catch (const char* msg) {
                    printErrorMsg(msg);
                }
                break;
            }
            case 3: {
                try {
                    printAllStudentsFacade(names, gpas, size);
                } catch (const char* msg) {
                    printErrorMsg(msg);
                }
                break;
            }
            case 4: {
                try {
                    avgStudentsGPAFacade(gpas, size);
                } catch (const char* msg) {
                    printErrorMsg(msg);
                }
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    for (int i = 0; i < size; i++) {
        free(names[i]);
    }

    return 0;
}
