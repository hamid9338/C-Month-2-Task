#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;
public:
    BankAccount(double initialBalance = 0) {
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << " Deposit amount must be greater than zero.\n";
        } else {
            balance += amount;
            cout << " Deposited $" << amount << ". New balance: $" << balance << "\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << " Withdrawal amount must be greater than zero.\n";
        } else if (amount > balance) {
            cout << " Insufficient balance.\n";
        } else {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << "\n";
        }
    }

    void checkBalance() const {
        cout << " Current balance: $" << balance << "\n";
    }
};

class ATM {
private:
    BankAccount account;
public:
    ATM(BankAccount acc) : account(acc) {}

    void menu() {
        int choice;
        do {
            cout << "\n===== ATM Menu =====\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit\n";
            cout << "3. Withdraw\n";
            cout << "4. Exit\n";
            cout << "Enter your choice (1-4): ";
            cin >> choice;

            switch (choice) {
                case 1:
                    account.checkBalance();
                    break;
                case 2: {
                    double amount;
                    cout << "Enter deposit amount: ";
                    cin >> amount;
                    account.deposit(amount);
                    break;
                }
                case 3: {
                    double amount;
                    cout << "Enter withdrawal amount: ";
                    cin >> amount;
                    account.withdraw(amount);
                    break;
                }
                case 4:
                    cout << " Thank you for using the ATM!\n";
                    break;
                default:
                    cout << " Invalid choice. Please select 1-4.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    BankAccount userAccount(1000); // Initial balance
    ATM atm(userAccount);
    atm.menu();
    return 0;
}
