#include <iostream>
#include <iomanip>

#include "Account.h"

/// <summary>
/// Create a new account with the specified name and balance
/// </summary>
void Account::create_account()
{
	std::cout << "\n Enter the Account No. : ";
	std::cin >> acno;
	std::cout << "\n Enter the Name of the Account Holder : ";
	std::cin.ignore();
	std::cin.getline(name, 50);
	std::cout << "\n Enter the type of Account Current [C] or Savings [S] : ";
	std::cin >> type;
	type = toupper(type);
	std::cout << "\n Enter the initial amount (must be >500 for Savings and >1000 for Current) : ";
	std::cin >> deposit;
	std::cout << "Account Created";
}

/// <summary>
/// Print list of registered accounts in Console
/// </summary>
void Account::print_account_list() const
{
	std::cout << "\n Account No. : " << acno;
	std::cout << "\n Account Holder Name : ";
	std::cout << name;
	std::cout << "\n Type of Account : " << type;
	std::cout << "\n Balance Amount : " << deposit;
}

/// <summary>
/// Modify the account details
/// </summary>
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

/// <summary>
/// Increase the deposited amount
/// </summary>
/// <param name="amount">Amount of the increase</param>
void Account::make_deposit(int amount)
{
	deposit += amount;
}

/// <summary>
/// Reduce the deposited amount.
/// </summary>
/// <param name="amount">Amount of the decrease</param>
void Account::withdraw(int amount)
{
	deposit -= amount;
}

/// <summary>
/// Print a report of the deposit in Console
/// </summary>
void Account::report() const
{
	std::cout << acno << std::setw(10) << " " << type << std::setw(6) << deposit << std::endl;
}

/// <summary>
/// Get the account number
/// </summary>
/// <returns>Account number</returns>
int Account::get_account_number() const
{
	return acno;
}

/// <summary>
/// Get the account holder name
/// </summary>
/// <returns>Deposited amount.</returns>
int Account::get_deposit() const
{
	return deposit;
}

/// <summary>
/// Get the account type
/// </summary>
/// <returns>Account type</returns>
/// <remarks>Account type can be 'C' or 'S'</remarks>
char Account::get_account_type() const
{
	return type;
}
