#include <iostream>
#include <string>
using namespace std;
// Base class representing a generic employee
class Employee {
protected:
    // 'protected' allows these variables to be accessed directly by derived classes (Developer, Manager)
    string name;
    int employeeID;
public:
    // Constructor to initialize common employee attributes
    Employee(string n, int id) {
        name = n;
        employeeID = id;
    }
    // A standard behavior shared by all employees
    void clockIn() {
        cout << name << " (ID: " << employeeID << ") has clocked in for the day." << endl;
    }
};
// Derived class representing a Developer, inheriting publicly from Employee
class Developer : public Employee {
private:
    // Attribute specific to Developers
    string favoriteLanguage;
public:
    // Constructor uses a member initializer list to pass arguments up to the base class constructor
    Developer(string n, int id, string lang) : Employee(n, id) {
        favoriteLanguage = lang;
    }
    // Behavior specific to Developers
    void writeCode() {
        // Can access 'name' directly because it was marked 'protected' in the base class
        cout << name << " is currently writing code in " << favoriteLanguage << "." << endl;
    }
};
// Derived class representing a Manager, inheriting publicly from Employee
class Manager : public Employee {
private:
    // Attribute specific to Managers
    int teamSize;
public:
    // Constructor passes 'n' and 'id' to the base Employee class, handles 'team' locally
    Manager(string n, int id, int team) : Employee(n, id) {
        teamSize = team;
    }
    // Behavior specific to Managers
    void holdMeeting() {
        cout << name << " is holding a meeting with their team of " << teamSize << " people." << endl;
    }
};
// Main execution block
int main() {
    // Instantiate derived class objects with their specific parameters
    Developer dev("Rahul", 101, "C++");
    Manager mgr("Utkarsh", 102, 5);
    cout << "--- Morning Routine ---" << endl;
    // Both objects use the clockIn() method inherited from the generic Employee class
    dev.clockIn(); 
    mgr.clockIn();
    cout << "\n--- Daily Tasks ---" << endl;
    // Each object calls its own specialized class method
    dev.writeCode();
    mgr.holdMeeting();
    return 0; // Return success status to the operating system
}
