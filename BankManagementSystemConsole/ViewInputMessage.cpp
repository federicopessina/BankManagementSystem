#include <iostream>
#include "ViewInputMessage.h"

void ViewInputMessage::print_input_account_number()
{
	std::cout << "\n Enter the Account Number : ";
}

void ViewInputMessage::print_input_details_new_account()
{
	std::cout << "\n Enter the New Details Account : " << std::endl;
}

void ViewInputMessage::print_input_amount_to_deposit()
{
	std::cout << "\n Enter the amount to deposit : ";
}

void ViewInputMessage::print_input_amout_to_withdraw()
{
	std::cout << "\n Enter the amount to withdraw. ";
}

void ViewInputMessage::print_input_name_account_holder()
{
	std::cout << "\n Enter the Name of the Account Holder : ";
}

void ViewInputMessage::print_input_type_of_account()
{
	std::cout << "\n Enter the type of Account Current [C] or Savings [S] : ";
}

void ViewInputMessage::print_input_initial_amount()
{
	std::cout << "\n Enter the initial amount (must be >500 for Savings and >1000 for Current) : ";
}