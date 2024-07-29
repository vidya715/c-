#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(int number, string name, double initialBalance)
        : accountNumber(number), accountHolderName(name), balance(initialBalance) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Invalid or insufficient funds for withdrawal!" << endl;
        }
    }

    void displayAccountDetails() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
    }
};

class Bank {
private:
    vector<Account> accounts;

    Account* findAccount(int accountNumber) {
        for (auto& acc : accounts) {
            if (acc.getAccountNumber() == accountNumber) {
                return &acc;
            }
        }
        return nullptr;
    }

public:
    void createAccount(int number, string name, double initialBalance) {
        accounts.emplace_back(number, name, initialBalance);
        cout << "Account created successfully!" << endl;
    }

    void deposit(int accountNumber, double amount) {
        Account* acc = findAccount(accountNumber);
        if (acc) {
            acc->deposit(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void withdraw(int accountNumber, double amount) {
        Account* acc = findAccount(accountNumber);
        if (acc) {
            acc->withdraw(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void viewAccountDetails(int accountNumber) {
        Account* acc = findAccount(accountNumber);
        if (acc) {
            acc->displayAccountDetails();
        } else {
            cout << "Account not found!" << endl;
        }
    }
};

int main() {
    Bank bank;
    int choice;
    int accountNumber;
    string name;
    double amount;

    while (true) {
        cout << "\nBank Management System" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. View Account Details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cin.ignore();
                cout << "Enter account holder name: ";
                getline(cin, name);
                cout << "Enter initial balance: ";
                cin >> amount;
                bank.createAccount(accountNumber, name, amount);
                break;
            case 2:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                bank.deposit(accountNumber, amount);
                break;
            case 3:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                bank.withdraw(accountNumber, amount);
                break;
            case 4:
                cout << "Enter account number: ";
                cin >> accountNumber;
                bank.viewAccountDetails(accountNumber);
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
