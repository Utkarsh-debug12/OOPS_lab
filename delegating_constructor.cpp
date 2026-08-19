#include<iostream>
#include<string>
using namespace std;
class Club {
private:
    // Private data members representing the club member's profile
    string name, role, club_name;
public:
    // 1. The Main Constructor
    // This is the only constructor that actually assigns values to the variables.
    // The 'explicit' keyword prevents the compiler from using this constructor 
    // for implicit type conversions.
    explicit Club(string memb_name, string memb_role, string memb_club) {
        name = memb_name;
        role = memb_role;
        club_name = memb_club;
    }
    // 2. Delegating Constructor (2 parameters)
    // When we get only member name and club name:
    // This constructor passes the known values to the Target Constructor (above)
    // and fills in the missing 'role' parameter with the default string "Unassigned".
    Club(string memb_name, string memb_club) : Club(memb_name, "Unassigned", memb_club) {}
    // 3. Delegating Constructor (1 parameter)
    // When we get only the member name:
    // This passes the name to the Target Constructor and defaults both the 
    // 'role' and 'club_name' parameters to "Unassigned".
    Club(string memb_name) : Club(memb_name, "Unassigned", "Unassigned") {}
    // Function to display the stored data to the console
    void display() {
        cout << "Member Details: " << endl;
        cout << "Name: " << name << endl;
        cout << "Role: " << role << endl;
        cout << "Club Name: " << club_name << endl;
    }
};
int main() {
    // We are passing two arguments here. 
    // 1. The compiler finds the 2-parameter constructor.
    // 2. The 2-parameter constructor immediately delegates to the 3-parameter constructor.
    // 3. The 3-parameter constructor does the actual assignment.
    Club member1{"Utkarsh Kumar", "Debate Club"};
    // Print the results
    member1.display();
    return 0;
}
