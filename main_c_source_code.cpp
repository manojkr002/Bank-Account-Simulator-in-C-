#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;
    vector<string> transactionHistory;

public:
    BankAccount() {
        accountHolder = "";
        accountNumber = 0;
        balance = 0.0;
    }

    void createAccount() {
        cout << "\nEnter Account Holder Name: ";
        cin.ignore();
        getline(cin, accountHolder);

        cout << "Enter Account Number: ";
        while (!(cin >> accountNumber) || accountNumber <= 0) {
            cout << "Invalid account number. Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter Initial Deposit: $";
        while (!(cin >> balance) || balance < 0) {
            cout << "Invalid amount. Enter again: $";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        transactionHistory.push_back("Account created with initial balance: $" + to_string(balance));
        cout << "\nAccount created successfully!\n";
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    void deposit() {
        double amount;
        cout << "\nEnter Deposit Amount: $";

        while (!(cin >> amount) || amount <= 0) {
            cout << "Invalid amount. Enter again: $";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        balance += amount;
        transactionHistory.push_back("Deposited: $" + to_string(amount));

        cout << "Deposit successful.\n";
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
    }

    void withdraw() {
        double amount;
        cout << "\nEnter Withdrawal Amount: $";

        while (!(cin >> amount) || amount <= 0) {
            cout << "Invalid amount. Enter again: $";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (amount > balance) {
            cout << "Insufficient Balance!\n";
        } else {
            balance -= amount;
            transactionHistory.push_back("Withdrew: $" + to_string(amount));
            cout << "Withdrawal successful.\n";
            cout << "Remaining Balance: $" << fixed << setprecision(2) << balance << endl;
        }
    }

    void checkBalance() const {
        cout << "\nCurrent Balance: $" << fixed << setprecision(2) << balance << endl;
    }

    void displayAccountDetails() const {
        cout << "\n========== ACCOUNT DETAILS ==========\n";
        cout << "Account Holder : " << accountHolder << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Balance        : $" << fixed << setprecision(2) << balance << endl;
        cout << "=====================================\n";
    }

    void displayTransactionHistory() const {
        cout << "\n======== TRANSACTION HISTORY ========\n";
        if (transactionHistory.empty()) {
            cout << "No transactions yet.\n";
        } else {
            for (size_t i = 0; i < transactionHistory.size(); ++i) {
                cout << i + 1 << ". " << transactionHistory[i] << endl;
            }
        }
        cout << "=====================================\n";
    }
};

int main() {
    vector<BankAccount> accounts;
    int choice;

    cout << "=================================\n";
    cout << "      BANK ACCOUNT SIMULATOR     \n";
    cout << "=================================\n";

    do {
        cout << "\n============= MAIN MENU =============" << endl;
        cout << "1. Create New Account" << endl;
        cout << "2. Access Existing Account" << endl;
        cout << "3. Exit" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Enter Choice: ";

        while (!(cin >> choice)) {
            cout << "Invalid choice. Enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (choice == 1) {
            BankAccount newAcc;
            newAcc.createAccount();
            accounts.push_back(newAcc);
        } 
        else if (choice == 2) {
            if (accounts.empty()) {
                cout << "\nNo accounts found! Please create an account first.\n";
                continue;
            }

            int targetAccNum;
            cout << "\nEnter Account Number to Access: ";
            while (!(cin >> targetAccNum)) {
                cout << "Invalid input. Enter again: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            BankAccount* selectedAccount = nullptr;
            for (auto& acc : accounts) {
                if (acc.getAccountNumber() == targetAccNum) {
                    selectedAccount = &acc;
                    break;
                }
            }

            if (selectedAccount == nullptr) {
                cout << "Account not found!\n";
                continue;
            }

            int subChoice;
            do {
                cout << "\n---------- ACCOUNT MENU ----------\n";
                cout << "1. Deposit Money\n";
                cout << "2. Withdraw Money\n";
                cout << "3. Check Balance\n";
                cout << "4. View Account Details\n";
                cout << "5. View Transaction History\n";
                cout << "6. Back to Main Menu\n";
                cout << "----------------------------------\n";
                cout << "Enter Choice: ";

                while (!(cin >> subChoice)) {
                    cout << "Invalid choice. Enter again: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                switch (subChoice) {
                    case 1: selectedAccount->deposit(); break;
                    case 2: selectedAccount->withdraw(); break;
                    case 3: selectedAccount->checkBalance(); break;
                    case 4: selectedAccount->displayAccountDetails(); break;
                    case 5: selectedAccount->displayTransactionHistory(); break;
                    case 6: cout << "Returning to Main Menu...\n"; break;
                    default: cout << "\nInvalid Choice!\n";
                }
            } while (subChoice != 6);

        } 
        else if (choice == 3) {
            cout << "\nThank you for using Bank Account Simulator. Goodbye!\n";
        } 
        else {
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}