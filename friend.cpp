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
    friend bool transferFunds(BankAccount& from, BankAccount& to, double amount);
    friend class BankAuditor;
};
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
    BankAccount aliceAcc("ACC-101", "Alice Smith", 5000.0);
    BankAccount bobAcc("ACC-202", "Bob Jones", 1200.0);
    cout << "Initial Public Info:\n";
    aliceAcc.displayPublicInfo();
    bobAcc.displayPublicInfo();
    cout << "\n";
    transferFunds(aliceAcc, bobAcc, 1500.0);
    BankAuditor auditor;
    auditor.generateAuditReport(aliceAcc);
    auditor.generateAuditReport(bobAcc);
    auditor.flagSuspiciousAccount(bobAcc, 2000.0);
    return 0;
}
