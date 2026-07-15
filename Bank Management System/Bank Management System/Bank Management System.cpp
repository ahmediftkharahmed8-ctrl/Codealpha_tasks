#include <iostream>
#include<fstream>
#include <string>
using namespace std;

class Transaction
{
private:
    string type;
    double amount;

public:
    Transaction()
    {
        type = "";
        amount = 0;
    }

    void setTransaction(string t, double a)
    {
        type = t;
        amount = a;
    }

    void display()
    {
        cout << type << " : Rs. " << amount << endl;
    }
};

class Customer
{
private:
    int customerID;
    string name;
    string phone;

public:
    Customer()
    {
        customerID = 0;
        name = "";
        phone = "";
    }

    void createCustomer()
    {
        cout << "Enter Customer ID: ";
        cin >> customerID;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Phone: ";
        getline(cin, phone);
    }

    void displayCustomer()
    {
        cout << "\nCustomer ID : " << customerID << endl;
        cout << "Name        : " << name << endl;
        cout << "Phone       : " << phone << endl;
    }
};

class Account
{
private:
    int accountNumber;
    double balance;

    Customer customer;

    Transaction transactions[100];
    int transactionCount;

public:
    Account()
    {
        accountNumber = 0;
        balance = 0;
        transactionCount = 0;
    }

    void createAccount()
    {
        customer.createCustomer();

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Opening Balance: ";
        cin >> balance;

        transactions[transactionCount].setTransaction("Opening Balance", balance);
        transactionCount++;
    }

    void deposit()
    {
        double amount;

        cout << "Enter Deposit Amount: ";
        cin >> amount;

        balance += amount;

        transactions[transactionCount].setTransaction("Deposit", amount);
        transactionCount++;

        cout << "Deposit Successful.\n";
    }

    void withdraw()
    {
        double amount;

        cout << "Enter Withdraw Amount: ";
        cin >> amount;

        if (amount > balance)
        {
            cout << "Insufficient Balance.\n";
            return;
        }

        balance -= amount;

        transactions[transactionCount].setTransaction("Withdraw", amount);
        transactionCount++;

        cout << "Withdrawal Successful.\n";
    }

    void transfer(Account& receiver)
    {
        double amount;

        cout << "Enter Transfer Amount: ";
        cin >> amount;

        if (amount > balance)
        {
            cout << "Insufficient Balance.\n";
            return;
        }

        balance -= amount;
        receiver.balance += amount;

        transactions[transactionCount].setTransaction("Transfer Sent", amount);
        transactionCount++;

        receiver.transactions[receiver.transactionCount].setTransaction("Transfer Received", amount);
        receiver.transactionCount++;

        cout << "Transfer Successful.\n";
    }

    void showTransactions()
    {
        cout << "\nTransaction History\n";

        for (int i = 0; i < transactionCount; i++)
        {
            transactions[i].display();
        }
    }

    void displayAccount()
    {
        cout << "\n========== ACCOUNT DETAILS ==========\n";

        customer.displayCustomer();

        cout << "Account Number : " << accountNumber << endl;
        cout << "Current Balance: Rs. " << balance << endl;
    }
};

int main()
{
    Account acc1, acc2;
    int choice;

    do
    {
        cout << "\n========== BANK MANAGEMENT SYSTEM ==========\n";
        cout << "1. Create Account 1\n";
        cout << "2. Create Account 2\n";
        cout << "3. Deposit in Account 1\n";
        cout << "4. Withdraw from Account 1\n";
        cout << "5. Transfer from Account 1 to Account 2\n";
        cout << "6. Show Account 1 Transactions\n";
        cout << "7. Show Account 2 Transactions\n";
        cout << "8. Display Account 1 Details\n";
        cout << "9. Display Account 2 Details\n";
        cout << "10. Exit\n";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            acc1.createAccount();
            break;

        case 2:
            acc2.createAccount();
            break;

        case 3:
            acc1.deposit();
            break;

        case 4:
            acc1.withdraw();
            break;

        case 5:
            acc1.transfer(acc2);
            break;

        case 6:
            acc1.showTransactions();
            break;

        case 7:
            acc2.showTransactions();
            break;

        case 8:
            acc1.displayAccount();
            break;

        case 9:
            acc2.displayAccount();
            break;

        case 10:
            cout << "\nThank you for using the Bank Management System.\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 10);

    return 0;
}

