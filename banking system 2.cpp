#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNum, string accName, double bal) : accountNumber(accNum), accountHolderName(accName), balance(bal) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << "\n";
        }
        else {
            cout << "Invalid deposit amount\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << "\n";
        }
        else {
            cout << "Invalid withdraw amount\n";
        }
    }

    void checkBalance() const {
        cout << "Balance: " << balance << "\n";
    }

    void saveToFile() const {
        ofstream file("accounts.txt", ios::out);
        if (file.is_open()) {
            file << accountNumber << " " << accountHolderName << " " << balance << "\n";
            file.close();
        }
        else {
            cout << "Unable to open file\n";
        }
    }
};

int main() {
    int accNum;
    string accName;
    double bal;

    cout << "Enter account number: ";
    cin >> accNum;
    cin.ignore(); // To ignore the newline character left in the buffer
    cout << "Enter account holder name: ";
    getline(cin, accName);
    cout << "Enter initial balance: ";
    cin >> bal;

    BankAccount account(accNum, accName, bal);

    int choice;
    double amount;

    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Save to File\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            account.deposit(amount);
            break;
        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            account.withdraw(amount);
            break;
        case 3:
            account.checkBalance();
            break;
        case 4:
            account.saveToFile();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
