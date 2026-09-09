#include <iostream>
#include <string>
using namespace std;

class BankAccount; 
bool transferFunds(BankAccount& from, BankAccount& to, double amount);

class BankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;

public:
    BankAccount(string accNum, string name, double initialDeposit)
        : accountNumber(accNum), ownerName(name), balance(initialDeposit) {}

    void displayPublicInfo() const {
        cout << "Account: " << accountNumber 
             << " | Owner: " << ownerName << "\n";
    }

    // Grants access to private members
    friend bool transferFunds(BankAccount& from, BankAccount& to, double amount);
    friend class BankAuditor;
};

// Friend function to transfer money between accounts
bool transferFunds(BankAccount& from, BankAccount& to, double amount) {
    if (amount <= 0 || from.balance < amount) {
        cout << "[Transfer Failed] Insufficient balance or invalid amount.\n";
        return false;
    }
    from.balance -= amount;
    to.balance += amount;
    cout << "[Transfer Success] $" << amount
         << " transferred from " << from.accountNumber 
         << " to " << to.accountNumber << "\n";
    return true;
}

// Friend class for inspecting private account data
class BankAuditor {
public:
    void generateAuditReport(const BankAccount& account) const {
        cout << "\n--- AUDIT REPORT ---\n"
             << "Account ID : " << account.accountNumber << "\n"
             << "Owner      : " << account.ownerName << "\n"
             << "Ledger Bal : $" << account.balance << "\n"
             << "--------------------\n";
    }

    void flagSuspiciousAccount(const BankAccount& account, double threshold) const {
        if (account.balance > threshold) {
            cout << "[FLAG] Account " << account.accountNumber 
                 << " exceeds reporting threshold of $" << threshold << "!\n";
        }
    }
};

int main() {
    // Setup sample accounts
    BankAccount palakAcc("ACC-101", "Palak Sharma", 5000.0);
    BankAccount radhaAcc("ACC-202", "Radha", 1200.0);

    cout << "Initial Public Info:\n";
    palakAcc.displayPublicInfo();
    radhaAcc.displayPublicInfo();
    cout << "\n";

    // Perform transaction and audit
    transferFunds(palakAcc, radhaAcc, 1500.0);

    BankAuditor auditor;
    auditor.generateAuditReport(palakAcc);
    auditor.generateAuditReport(radhaAcc);
    auditor.flagSuspiciousAccount(palakAcc, 2000.0);

    return 0;
}
