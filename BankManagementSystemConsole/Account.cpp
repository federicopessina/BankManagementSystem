#include <iostream>
#include <iomanip>

#include "Account.h"

void Account::create_account()
{
	std::cout << "\n Enter the Account No. : ";
	std::cin >> acno;
	std::cout << "\n Enter the Name of the Account Holder : ";
	std::cin.ignore();
	std::cin.getline(name, 50);
	std::cout << "\n Enter the type of Account Current [C] / Savings [S] : ";
	std::cin >> type;
	type = toupper(type);
	std::cout << "\n Enter the initial amount (>500 for Savings and >1000 for Current) : ";
	std::cin >> deposit;
	std::cout << "Account Created";
}

void Account::show_account() const
{
	std::cout << "\n Account No. : " << acno;
	std::cout << "\n Account Holder Name : ";
	std::cout << name;
	std::cout << "\n Type of Account : " << type;
	std::cout << "\n Balance Amount : " << deposit;
}

void Account::modify()
{
	std::cout << "\n Account No. : " << acno;
	std::cout << "\n Modify Account Holder Name : ";
	std::cin.ignore();
	std::cin.getline(name, 50);
	std::cout << "\n Modify Type of Account : ";
	std::cin >> type;
	type = toupper(type);
	std::cout << "\n Modify Balance Amount : ";
	std::cin >> deposit;
}

void Account::make_deposit(int amount)
{
	deposit += amount;
}

void Account::withdraw(int amount)
{
	deposit -= amount;
}

void Account::report() const
{
	std::cout << acno << std::setw(10) << " " << type << std::setw(6) << deposit << std::endl;
}

int Account::get_acno() const
{
	return acno;
}

int Account::get_deposit() const
{
	return deposit;
}

char Account::get_account_type() const
{
	return type;
}
