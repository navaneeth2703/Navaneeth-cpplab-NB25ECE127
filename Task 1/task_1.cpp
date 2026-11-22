#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student {
private:
    int rollNo;
    string name;
    int numSubjects;
    double* marks;          // Dynamically allocated array of marks
    static int studentCount;

    double computeTotal() const {
        if (!marks || numSubjects <= 0) return 0.0;
        double sum = 0.0;
        for (int i = 0; i < numSubjects; ++i) {
            sum += marks[i];
        }
        return sum;
    }

public:
    // Parameterized constructor (with defaults so it can also act as default constructor)
    Student(int roll = 0, const string& studentName = "Unknown",
            const double* subjectMarks = nullptr, int count = 0)
        : rollNo(roll), name(studentName), numSubjects(count), marks(nullptr) {
        if (numSubjects > 0 && subjectMarks != nullptr) {
            marks = new double[numSubjects];
            for (int i = 0; i < numSubjects; ++i) {
                marks[i] = subjectMarks[i];
            }
        } else {
            numSubjects = 0;
        }
        ++studentCount;
    }

    // Copy constructor (deep copy for dynamic memory)
    Student(const Student& other)
        : rollNo(other.rollNo), name(other.name), numSubjects(other.numSubjects), marks(nullptr) {
        if (numSubjects > 0 && other.marks != nullptr) {
            marks = new double[numSubjects];
            for (int i = 0; i < numSubjects; ++i) {
                marks[i] = other.marks[i];
            }
        }
        ++studentCount;
    }

    // Copy assignment operator (deep copy + self-assignment guard)
    Student& operator=(const Student& other) {
        if (this == &other) return *this;

        delete[] marks;
        marks = nullptr;

        rollNo = other.rollNo;
        name = other.name;
        numSubjects = other.numSubjects;

        if (numSubjects > 0 && other.marks != nullptr) {
            marks = new double[numSubjects];
            for (int i = 0; i < numSubjects; ++i) {
                marks[i] = other.marks[i];
            }
        }
        return *this;
    }

    // Destructor to release dynamically allocated memory
    ~Student() {
        delete[] marks;
        marks = nullptr;
        --studentCount;
    }

    // Getters & setters (encapsulation)
    int getRollNo() const { return rollNo; }
    string getName() const { return name; }
    int getNumSubjects() const { return numSubjects; }

    void setName(const string& newName) { name = newName; }

    void setMarks(const double* subjectMarks, int count) {
        delete[] marks;
        marks = nullptr;
        numSubjects = 0;

        if (count > 0 && subjectMarks != nullptr) {
            numSubjects = count;
            marks = new double[numSubjects];
            for (int i = 0; i < numSubjects; ++i) {
                marks[i] = subjectMarks[i];
            }
        }
    }

    // Overloaded function 1: average across all subjects
    double getAverage() const {
        if (numSubjects <= 0) return 0.0;
        return computeTotal() / numSubjects;
    }

    // Overloaded function 2: average across a custom total out of a specified max total
    double getAverage(double customTotal, double customMaxTotal) const {
        if (customMaxTotal <= 0.0) return 0.0;
        return (customTotal / customMaxTotal) * 100.0;
    }

    // Overloaded function 3: display summary or detailed marks
    void display() const {
        cout << "Roll No: " << rollNo
             << " | Name: " << name
             << " | Total: " << fixed << setprecision(1) << computeTotal()
             << " | Avg: " << setprecision(2) << getAverage() << "%\n";
    }

    void display(bool showIndividualMarks) const {
        display();
        if (showIndividualMarks && marks && numSubjects > 0) {
            cout << "   Subject Marks: ";
            for (int i = 0; i < numSubjects; ++i) {
                cout << marks[i];
                if (i + 1 < numSubjects) cout << ", ";
            }
            cout << "\n";
        }
    }

    // Static member function to access student count
    static int getStudentCount() {
        return studentCount;
    }

    // Overloaded > operator to compare students based on total marks
    bool operator>(const Student& other) const {
        return this->computeTotal() > other.computeTotal();
    }

    // Friend function to inspect private fields and print a formatted report card
    friend void printReportCard(const Student& s);
};

// Initialize static member outside the class
int Student::studentCount = 0;

// Friend function definition
void printReportCard(const Student& s) {
    cout << "=== Report Card ===\n"
         << "Student : " << s.name << " (Roll #" << s.rollNo << ")\n"
         << "Subjects: " << s.numSubjects << "\n";
    for (int i = 0; i < s.numSubjects; ++i) {
        cout << "  Sub " << (i + 1) << ": " << fixed << setprecision(1) << s.marks[i] << "\n";
    }
    cout << "Total   : " << s.computeTotal() << "\n"
         << "Average : " << fixed << setprecision(2) << s.getAverage() << "%\n"
         << "===================\n";
}

int main() {
    double m1[] = {85.0, 90.0, 78.0};
    double m2[] = {92.0, 88.0, 95.0};

    Student s1(1, "Aarav", m1, 3);
    Student s2(2, "Diya", m2, 3);

    cout << "Active students: " << Student::getStudentCount() << "\n\n";

    // Overloaded display()
    s1.display();
    s2.display(true);

    // Overloaded getAverage()
    cout << "\nCustom percentage (275 / 300): " << s2.getAverage(275.0, 300.0) << "%\n\n";

    // Friend function
    printReportCard(s1);

    // Overloaded > operator
    cout << "\nComparison:\n";
    if (s2 > s1) {
        cout << s2.getName() << " has higher total marks than " << s1.getName() << ".\n";
    } else {
        cout << s1.getName() << " has higher or equal total marks compared to " << s2.getName() << ".\n";
    }

    // Dynamic allocation of a Student object and cleanup
    double m3[] = {70.0, 75.0, 80.0};
    Student* s3Ptr = new Student(3, "Rohan", m3, 3);
    cout << "\nActive students after dynamic allocation: " << Student::getStudentCount() << "\n";
    s3Ptr->display();

    delete s3Ptr;
    s3Ptr = nullptr;
    cout << "Active students after delete: " << Student::getStudentCount() << "\n";

    return 0;
}