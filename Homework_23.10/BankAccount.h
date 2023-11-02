#pragma once
#include <iostream>
#include <string>
using namespace std;


class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(string accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {};

    void deposit(double sum) {
        balance += sum;
    }

    void withdraw(double sum) {
        if (balance >= sum) {
            balance -= sum;
        }
        else {
            cout << "��� �� ������� �����!" << endl;
        }
    }

    void displayInfo() const {
        cout << "����� �����: " << accountNumber << endl;
        cout << "������: " << balance << endl;
    }

    void transfer(BankAccount& other, double sum) {
        if (balance >= sum) {
            withdraw(sum);
            other.deposit(sum);
        }
        else {
            cout << "��� �� ������� �����!!!" << endl;
        }
    }

    BankAccount(BankAccount& other) : accountNumber(other.accountNumber), balance(other.balance) {};
};