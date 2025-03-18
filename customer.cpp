#include<iostream>
#include<cstring>
using namespace std;

class Account {
protected:
    string acc_holder_name;
    int acc_holder_contactno = 0;

public:
    void get(string acc_holder_name, int acc_holder_contactno) {
        this->acc_holder_name = acc_holder_name;
        this->acc_holder_contactno = acc_holder_contactno;
    }

    void display() {
        cout << "\n\tAccount Holder Name: " << acc_holder_name << "\t Account Holder Contact Number: " << acc_holder_contactno << endl;
    }
};

class saving_accout : public Account {
private:
    float saving_acc, balance, total;

public:
    saving_accout() : total(0) {}

    void set(float saving_acc) {
        this->saving_acc = saving_acc;
    }

    float add(float balance) {
        this->balance = balance;
        total = balance + (balance * 0.5);  // Assuming 50% addition
        return total;
    }

    void display() {
        Account::display();
        cout << "\n\tSaving Account Number: " << saving_acc << "\t Total Balance: " << total << endl;
    }
};

class current_acc : public Account {
private:
    float current_acc, balance, total;

public:
    void set(float current_acc) {
        this->current_acc = current_acc;
    }

    float add(float balance) {
        this->balance = balance;
        total = balance + (balance * 0.15);  // Assuming 15% addition
        return total;
    }

    void display_curr() {
        Account::display();
        cout << "\n\tCurrent Account Number: " << current_acc << "\t Total Balance: " << total << endl;
    }
};

int main() {
    int n;
    cout << "How many accounts to add: ";
    cin >> n;

    saving_accout s1[n];

    for (int i = 0; i < n; i++) {
        string name;
        int contact;
        float accountNum, salary;

        cout << "\nEnter account holder name: ";
        cin >> name;
        cout << "Enter contact number: ";
        cin >> contact;

        s1[i].get(name, contact);

        cout << "Enter saving account number: ";
        cin >> accountNum;
        cout << "Enter initial balance (salary): ";
        cin >> salary;

        s1[i].set(accountNum);
        s1[i].add(salary);
    }

    for (int i = 0; i < n; i++) {
        s1[i].display();
    }

    return 0;
}
