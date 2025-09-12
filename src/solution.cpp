
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

// Using
using std::cout, std::endl, std::getline, std::string, std::cin;
// Const values # defines,
const int defaultGPA = 0;
const char* errorPrefix = "Error: ";
//
// Helpers
char* getName() {
    cout << "Enter name: ";

    string temp;
    std::cin >> temp;

    char* name = new char[temp.size() + 1];
    strcpy(name, temp.c_str());
    return name;
}

double* getGPA() {
    cout << "Enter GPA: ";
    double* gpa = new double;
    std::cin >> *gpa;
    return gpa;
}

void validateAdditionalCapacity(int &size, int capacity) {
    if (!((size + 1) <= capacity)) {
        throw "List full";
    }
}

// TODO: implement addStudent
using namespace GPAUtils;
void GPAUtils::addStudent(char* name, double gpa, char* names[], double
    gpas[], int& size, int capacity) {
    names[size] = name;
    gpas[size] = gpa;

    size++;
    cout << "Success! Added \"" << name << "\" with GPA \"" << gpa << "\".\n";
}

// TODO: implement updateGPA

// TODO: implement printStudent

// TODO: implement averageGPA


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
        // This doesn't capture other input conditions
        if (!(std::cin >> choice)) {
            if (std::cin.eof()) {
                break;
            }
        }

        switch (choice) {
            case 1: {
                try {
                    validateAdditionalCapacity(size, capacity);
                    char* name = getName();
                    double* GPA = getGPA();
                    GPAUtils::addStudent(name, *GPA, names, gpas, size, capacity);
                    free(name);
                    free(GPA);

                } catch (const char* msg) {
                    std::cout << errorPrefix << msg << std::endl;
                }
                break;
            }
            case 2: {
                // TODO: implement menu logic
                break;
            }
            case 3: {
                // TODO: implement menu logic
                break;
            }
            case 4: {
                // TODO: implement menu logic
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

    // TODO: free memory

    return 0;
}
