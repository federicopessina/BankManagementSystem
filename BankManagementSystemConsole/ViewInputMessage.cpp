#include <iostream>
#include "ViewInputMessage.h"

void ViewInputMessage::print_input_account_number()
{
	std::cout << "\n Enter the Account No. : ";
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
