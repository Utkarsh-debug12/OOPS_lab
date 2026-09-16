#include <iostream>
#include <string>
using namespace std;
class BankAccount {
private:
    // Instance variables: specific to each individual account
    string accountHolder;
    int accountNumber;
    double balance;
    // Static variables: shared across all BankAccount objects
    static int totalAccounts;
    static double totalBankReserves;
    static int nextAccountNumber;
public:
    // Constructor: Initializes the account and updates global bank totals
    BankAccount(const string& name, double initialDeposit) 
        : accountHolder(name), balance(initialDeposit) {
        accountNumber = ++nextAccountNumber; // Auto-increment account number
        totalAccounts++;
        totalBankReserves += balance;
        cout << "[Opened] Account #" << accountNumber << " for " 
             << accountHolder << " with Rs." << balance << "\n";
    }
    // Destructor: Cleans up the account and decreases global bank totals
    ~BankAccount() {
        totalAccounts--;
        totalBankReserves -= balance;
        cout << "Destructor is called.\n" 
             << "[Closed] Account #" << accountNumber << " (" 
             << accountHolder << ") closed. Withdrawn: Rs." << balance << "\n";
    }
    // Adds money to both the individual account and global reserves
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            totalBankReserves += amount;
            cout << accountHolder << " deposited Rs." << amount << "\n";
        }
    }
    // Removes money if the account has sufficient funds
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            totalBankReserves -= amount;
            cout << accountHolder << " withdrew Rs." << amount << "\n";
        } else {
            cout << "Transaction failed: Insufficient funds for " << accountHolder << "\n";
        }
    }
    // Static method: Can be called without an object to print overall bank stats
    static void displayBankSummary() {
        cout << "\n---------------- BANK SUMMARY ----------------\n";
        cout << "Active Accounts   : " << totalAccounts << "\n";
        cout.setf(ios::fixed);
        cout.precision(2); // Format output to 2 decimal places
        cout << "Total Cash Reserve: Rs." << totalBankReserves << "\n";
        cout << "----------------------------------------------\n\n";
    }
};
// Initialize static member variables outside the class definition
int BankAccount::totalAccounts = 0;
double BankAccount::totalBankReserves = 0.0;
int BankAccount::nextAccountNumber = 1000;
int main() {
    // Show initial bank summary (0 accounts)
    BankAccount::displayBankSummary();
    // Create standard accounts
    BankAccount acc1("Utkarsh Kumar", 25000.0);
    BankAccount acc2("Rahul Kumar", 54356.0);
    // Perform basic transactions
    acc1.deposit(7456.0);
    acc2.withdraw(1256.0);
    BankAccount::displayBankSummary();
    // Block scope demonstration
    {
        cout << "--- Opening temporary account ---\n";
        // tempAcc only exists within these curly braces
        BankAccount tempAcc("Pinkesh Mishra (Temporary)", 744210.0);
        BankAccount::displayBankSummary();
        cout << "--- Leaving temporary block scope ---\n";
    } // tempAcc's destructor is automatically triggered right here
    // Summary reflects the automatic closure of tempAcc
    BankAccount::displayBankSummary();
    // Explicitly calling a destructor (Note: This is generally bad practice in C++)
    acc1.~BankAccount(); 
    BankAccount::displayBankSummary();
    return 0; // The destructors for acc1 (again) and acc2 will be automatically called here
}
