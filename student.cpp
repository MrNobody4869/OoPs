#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string className;
    char division;
    string dob;
    string bloodGroup;
    string contactAddress;
    string phoneNumber;
    string drivingLicense;

    static int studentCount; // Static member to count students

public:
    // Default constructor
    Student() {
        name = "Unknown";
        rollNumber = 0;
        className = "N/A";
        division = 'X';
        dob = "01-01-2000";
        bloodGroup = "N/A";
        contactAddress = "N/A";
        phoneNumber = "N/A";
        drivingLicense = "N/A";
        studentCount++;
    }

    // Parameterized constructor
    Student(string n, int r, string c, char d, string date, string bg, string addr, string phone, string dl)
        : name(n), rollNumber(r), className(c), division(d), dob(date), bloodGroup(bg), contactAddress(addr), phoneNumber(phone), drivingLicense(dl) {
        studentCount++;
    }

    // Copy constructor
    Student(const Student& other) {
        name = other.name;
        rollNumber = other.rollNumber;
        className = other.className;
        division = other.division;
        dob = other.dob;
        bloodGroup = other.bloodGroup;
        contactAddress = other.contactAddress;
        phoneNumber = other.phoneNumber;
        drivingLicense = other.drivingLicense;
        studentCount++;
    }

    // Destructor
    ~Student() {
        studentCount--;
    }

    // Friend class
    friend class Display;

    // Static member function
    static int getStudentCount() {
        return studentCount;
    }

    // Inline function
    inline void setContactAddress(string addr) {
        contactAddress = addr;
    }

    // Display student details
    void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << className << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Driving License: " << drivingLicense << endl;
    }

    // Dynamic memory allocation
    static Student* createStudent(string n, int r, string c, char d, string date, string bg, string addr, string phone, string dl) {
        try {
            return new Student(n, r, c, d, date, bg, addr, phone, dl);
        } catch (bad_alloc& e) {
            cerr << "Memory allocation failed: " << e.what() << endl;
            return nullptr;
        }
    }

    // Deallocate memory
    static void deleteStudent(Student* student) {
        delete student;
    }
};

// Initialize static member
int Student::studentCount = 0;

// Friend class to display student data
class Display {
public:
    void displayStudent(const Student& student) {
        cout << "Displaying student details using friend class:" << endl;
        student.displayDetails();
    }
};

int main() {
    // Create a student using parameterized constructor
    Student* s1 = Student::createStudent("John Doe", 101, "BE-Comp", 'A', "15-08-2003", "O+", "123 Main St", "9876543210", "DL12345678");

    if (s1) {
        cout << "\nStudent 1 Details:" << endl;
        s1->displayDetails();
    }

    // Create another student using default constructor
    Student s2;

    // Set contact address using inline function
    s2.setContactAddress("456 Park Ave");

    cout << "\nStudent 2 Details:" << endl;
    s2.displayDetails();

    // Use friend class to display student details
    Display display;
    display.displayStudent(s2);

    // Display student count
    cout << "\nTotal Students: " << Student::getStudentCount() << endl;

    // Clean up memory
    Student::deleteStudent(s1);

    cout << "\nTotal Students After Deletion: " << Student::getStudentCount() << endl;

    return 0;
}
