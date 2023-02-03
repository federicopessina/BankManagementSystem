#include <iostream>
#include "ViewOutputMessage.h"

void ViewOutputMessage::print_output_deposit_title()
{
	std::cout << "\n [To deposit amount]";
}

void ViewOutputMessage::print_output_withdraw_title()
{
	std::cout << "\n [To withdraw amount]";
}

void ViewOutputMessage::print_account_list_title()
{
	std::cout << "\n [Account Holders List] \n";
}


void ViewOutputMessage::print_account_list_menu()
{
	std::cout << "\n AccountNumber    Name    Type    Balance \n";
}

void ViewOutputMessage::print_output_record_updated()
{
	std::cout << "\n Record Updated";
}

void ViewOutputMessage::print_output_record_deleted()
{
	std::cout << "\n Record Deleted";
}

void ViewOutputMessage::print_output_insufficient_balance()
{
	std::cout << "Insufficient Balance";
}
