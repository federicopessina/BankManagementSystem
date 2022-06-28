#include <iostream>
#include "Model.h"
#include "View.h"
#include "DataBaseFile.h"
#include "ViewInputMessage.h"

void Model::main_loop()
{
	char userInput;
	int number;

	View::print_intro();
	std::cin.get();

	do
	{
		View::print_menu();

		std::cin >> userInput;

		View::clear_console();

		switch (userInput)
		{
		case '1':
			DataBaseFile::write_account();
			break;
		case '2':
			ViewInputMessage::print_input_account_number();
			std::cin >> number;
			DataBaseFile::deposit_withdraw(number, 1);
			break;
		case '3':
			ViewInputMessage::print_input_account_number();
			std::cin >> number;
			DataBaseFile::deposit_withdraw(number, 2);
			break;
		case '4':
			ViewInputMessage::print_input_account_number();
			std::cin >> number;
			DataBaseFile::display_sp(number);
			break;
		case '5':
			DataBaseFile::display_all();
			break;
		case '6':
			ViewInputMessage::print_input_account_number();
			std::cin >> number;
			DataBaseFile::delete_account(number);
			break;
		case '7':
			ViewInputMessage::print_input_account_number();
			std::cin >> number;
			DataBaseFile::modify_account(number);
			break;
		case '8':
			View::print_greetings();
			break;
		default:
			std::cout << "\a";
		}
		std::cin.ignore();
		std::cin.get();

	} while (userInput != '8');
}
