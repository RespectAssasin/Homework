#include <iostream>
#include "BankAccount.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
    cout << "Банк1: " << endl;

    BankAccount acc1("1", 1000);
    acc1.displayInfo();

    acc1.deposit(500);
    acc1.displayInfo();

    acc1.withdraw(1000);
    acc1.displayInfo();

    cout << endl << "Банк2: " << endl;
    BankAccount acc2("2", 2000);
    acc2.displayInfo();

    acc1.transfer(acc2, 1000);
    acc2.transfer(acc1, 2000);
    acc1.displayInfo();
    acc2.displayInfo();

	return 0;
}