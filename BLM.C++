#include <iostream>
#include <string>
using namespace std;

class Loan {
public:
    string loanID;
    string borrowerName;
    double loanAmount;
    double interestRate;
    int loanTerm;

    // Constructor
    Loan(string id, string name, double amount, double rate, int term) {
        loanID = id;
        borrowerName = name;
        loanAmount = amount;
        interestRate = rate;
        loanTerm = term;
    }

    // Method to calculate total loan amount with interest
    double calculateTotalAmount() {
        return loanAmount + (loanAmount * interestRate * loanTerm / 100);
    }

    // Display loan details
    void displayLoanDetails() {
        cout << "Loan ID: " << loanID << "\n";
        cout << "Borrower Name: " << borrowerName << "\n";
        cout << "Loan Amount: " << loanAmount << "\n";
        cout << "Interest Rate: " << interestRate << "%\n";
        cout << "Loan Term: " << loanTerm << " years\n";
        cout << "Total Loan Amount (with interest): " << calculateTotalAmount() << "\n";
    }
};
#include <vector>
#include <fstream>

class LoanManager {
private:
    vector<Loan> loans;
    
public:
    // Add a new loan
    void addLoan(Loan loan) {
        loans.push_back(loan);
    }

    // Display all loans
    void displayAllLoans() {
        for (const auto& loan : loans) {
            loan.displayLoanDetails();
            cout << "------------------------------\n";
        }
    }

    // Save loans to a file
    void saveLoansToFile() {
        ofstream file("loans.txt");
        for (const auto& loan : loans) {
            file << loan.loanID << "," << loan.borrowerName << ","
                 << loan.loanAmount << "," << loan.interestRate << ","
                 << loan.loanTerm << "\n";
        }
        file.close();
    }

    // Load loans from a file
    void loadLoansFromFile() {
        ifstream file("loans.txt");
        string id, name;
        double amount, rate;
        int term;
        while (file >> id >> name >> amount >> rate >> term) {
            loans.push_back(Loan(id, name, amount, rate, term));
        }
        file.close();
    }
};
#include <vector>
#include <fstream>

class LoanManager {
private:
    vector<Loan> loans;
    
public:
    // Add a new loan
    void addLoan(Loan loan) {
        loans.push_back(loan);
    }

    // Display all loans
    void displayAllLoans() {
        for (const auto& loan : loans) {
            loan.displayLoanDetails();
            cout << "------------------------------\n";
        }
    }

    // Save loans to a file
    void saveLoansToFile() {
        ofstream file("loans.txt");
        for (const auto& loan : loans) {
            file << loan.loanID << "," << loan.borrowerName << ","
                 << loan.loanAmount << "," << loan.interestRate << ","
                 << loan.loanTerm << "\n";
        }
        file.close();
    }

    // Load loans from a file
    void loadLoansFromFile() {
        ifstream file("loans.txt");
        string id, name;
        double amount, rate;
        int term;
        while (file >> id >> name >> amount >> rate >> term) {
            loans.push_back(Loan(id, name, amount, rate, term));
        }
        file.close();
    }
};
void showMenu() {
    cout << "Welcome to Bank Loan Management System\n";
    cout << "1. Add New Loan\n";
    cout << "2. View All Loans\n";
    cout << "3. Save Loans\n";
    cout << "4. Load Loans\n";
    cout << "5. Exit\n";
}

int main() {
    LoanManager manager;
    manager.loadLoansFromFile();  // Load existing loans at the start

    while (true) {
        showMenu();
        int choice;
        cin >> choice;

        if (choice == 1) {
            string id, name;
            double amount, rate;
            int term;
            cout << "Enter Loan ID: ";
            cin >> id;
            cout << "Enter Borrower Name: ";
            cin >> name;
            cout << "Enter Loan Amount: ";
            cin >> amount;
            cout << "Enter Interest Rate: ";
            cin >> rate;
            cout << "Enter Loan Term (years): ";
            cin >> term;

            Loan newLoan(id, name, amount, rate, term);
            manager.addLoan(newLoan);
        } else if (choice == 2) {
            manager.displayAllLoans();
        } else if (choice == 3) {
            manager.saveLoansToFile();
            cout << "Loans saved successfully.\n";
        } else if (choice == 4) {
            manager.loadLoansFromFile();
            cout << "Loans loaded successfully.\n";
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

