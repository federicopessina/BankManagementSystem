#include <iostream>

#include "Model.h"
#include "View.h"
#include "DataBaseFile.h"
#include "ViewInputMessage.h"

/// <summary>
/// Main function
/// </summary>
/// <returns>0</returns>
/// <remarks>Starts the program and handles the possible inputs</remarks>
/// <author>Federico Pessina</author>
/// <exception cref="std::exception">Throws exception if something goes wrong</exception>
/// <exception cref="std::bad_alloc">Throws exception if something goes wrong</exception>
void Model::main_loop()
{
	try
	{
		char userInputOption;
		int accountNumber;

		View::print_intro();
		std::cin.get();

		do
		{
			View::print_menu();

			std::cin >> userInputOption;

			View::clear_console();

			switch (userInputOption)
			{
				// New Account
			case '1':
				DataBaseFile::write_account();
				break;
				// Deposit Amount
			case '2':
				ViewInputMessage::print_input_account_number();
				std::cin >> accountNumber;
				DataBaseFile::deposit_withdraw(accountNumber, 1);
				break;
				// Withdraw Amount
			case '3':
				ViewInputMessage::print_input_account_number();
				std::cin >> accountNumber;
				DataBaseFile::deposit_withdraw(accountNumber, 2);
				break;
				// Balance Enquiry
			case '4':
				ViewInputMessage::print_input_account_number();
				std::cin >> accountNumber;
				DataBaseFile::display_sp(accountNumber);
				break;
				// All Account Holder List
			case '5':
				DataBaseFile::display_all();
				break;
				// Close an Account
			case '6':
				ViewInputMessage::print_input_account_number();
				std::cin >> accountNumber;
				DataBaseFile::delete_account(accountNumber);
				break;
				// Modify an Account
			case '7':
				ViewInputMessage::print_input_account_number();
				std::cin >> accountNumber;
				DataBaseFile::modify_account(accountNumber);
				break;
				// Exit
			case '8':
				View::print_greetings();
				break;
			default:
				std::cout << "\a";
			}
			std::cin.ignore();
			std::cin.get();

		} while (userInputOption != '8');
	}
	catch (const std::exception&)
	{
		throw std::exception("Something went wrong");
	}
}
