#include <iostream>
#include <iomanip>

#include "Account.h"
#include "ViewInputMessage.h"
#include "ViewOutputMessage.h"

/// <summary>
/// Create a new account with the specified name and balance
/// </summary>
void Account::create_account()
{
	ViewInputMessage::print_input_account_number();
	std::cin >> acno;
	ViewInputMessage::print_input_name_account_holder();
	std::cin.ignore();
	std::cin.getline(name, 50);
	ViewInputMessage::print_input_type_of_account();
	std::cin >> type;
	type = toupper(type);
	ViewInputMessage::print_input_initial_amount();
	std::cin >> deposit;
	ViewOutputMessage::print_output_account_created();
}

/// <summary>
/// Print list of registered accounts in Console
/// </summary>
void Account::print_account_list() const
{
	print_output_account_number();
	print_output_account_holder();
	print_output_account_type();
	print_output_balance_amount();
}

/// <summary>
/// Print balance amount of the account in Console
/// </summary>
void Account::print_output_balance_amount() const
{
	std::cout << "\n Balance Amount : " << deposit;
}

/// <summary>
/// Print account number of the account in Console
/// </summary>
void Account::print_output_account_type() const
{
	std::cout << "\n Type of Account : " << type;
}

/// <summary>
/// Print account holder name of the account in Console
/// </summary>
void Account::print_output_account_holder() const
{
	std::cout << "\n Account Holder Name : ";
	std::cout << name;
}

/// <summary>
/// Print account number of the account in Console
/// </summary>
void Account::print_output_account_number() const
{
	std::cout << "\n Account No. : ";
	std::cout << acno;
}

/// <summary>
/// Modify the account details
/// </summary>
void Account::modify()
{
	print_output_account_number();
	print_output_account_holder_name();
	std::cin.ignore();
	std::cin.getline(name, 50);
	print_input_modify_account_type();
	type = toupper(type);
	print_input_modify_balance_amount();
}

/// <summary>
/// Print modify type of account input message
/// </summary>
/// <returns></returns>
/// <remarks>Takes the tyoe of account as input</remarks>
void Account::print_input_modify_account_type()
{
	std::cout << "\n Modify Type of Account : ";
	std::cin >> type;
}

/// <summary>
/// Print modify balance amount input message
/// </summary>
/// <returns></returns>
/// <remarks>Takes the balance amount as input</remarks>
void Account::print_input_modify_balance_amount()
{
	std::cout << "\n Modify Balance Amount : ";
	std::cin >> deposit;
}

/// <summary>
/// Print account holder name of the account in Console
/// </summary>
/// <returns></returns>
/// <remarks>Takes the account holder name as input</remarks>
void Account::print_output_account_holder_name()
{
	std::cout << "\n Modify Account Holder Name : ";
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
