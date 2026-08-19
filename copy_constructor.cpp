#include<iostream>
#include<string>
using namespace std;
class Bank {
private:
    // Private data members to store the bank account details
    string name, account_type;
    double interest_rate;
public:
    // Parameterized Constructor
    // The 'explicit' keyword ensures this constructor can only be called 
    // intentionally. It prevents C++ from doing accidental, behind-the-scenes type conversions.
    explicit Bank(string acc_name, string acc_type, double acc_interest) {
        name = acc_name;
        account_type = acc_type;
        interest_rate = acc_interest;
    }
    // Function to print the stored data to the console
    void display() {
        cout << "Account Details: " << endl;
        cout << "Bank Name: " << name << endl;
        cout << "Account Type: " << account_type << endl;
        cout << "Interest Rate: " << interest_rate << "%" << endl;
    }
};
int main() {
    // 1. Initialize the first object
    // This directly calls the parameterized constructor we defined above.
    Bank account1{"SBI", "Savings", 2.25}; 
    // 2. Initialize the second object using the first object
    // This uses the implicitly generated "Default Copy Constructor".
    // C++ automatically copies the 'name', 'account_type', and 'interest_rate' 
    // from account1 directly into account2.
    Bank account2{account1};
    // Display the details of the first account
    account1.display();
    cout << endl; 
    // Display the details of the copied account (it will be identical to account1)
    account2.display();
    return 0;
}
