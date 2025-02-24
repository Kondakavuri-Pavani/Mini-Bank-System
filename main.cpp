#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountHolder;
    double balance;

public:
    BankAccount(std::string holder) : accountHolder(holder), balance(0.0) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << "\n";
        } else {
            std::cout << "Invalid deposit amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount << "\n";
        } else {
            std::cout << "Invalid withdrawal amount!\n";
        }
    }

    void checkBalance() const {
        std::cout << "Current balance: $" << balance << "\n";
    }

    void displayAccountInfo() const {
        std::cout << "Account Holder: " << accountHolder << "\n";
        checkBalance();
    }
};

int main() {
    std::string name;
    std::cout << "Enter account holder name: ";
    std::getline(std::cin, name);

    BankAccount account(name);
    int choice;

    do {
        std::cout << "\nMini Banking System\n";
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Check Balance\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double amount;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                account.deposit(amount);
                break;
            }
            case 2: {
                double amount;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                account.withdraw(amount);
                break;
            }
            case 3:
                account.checkBalance();
                break;
            case 4:
                std::cout << "Exiting the system. Thank you for using our banking services. Have a wonderful day ahead!\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}