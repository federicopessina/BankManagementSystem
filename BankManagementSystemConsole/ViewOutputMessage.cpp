#include <iostream>
#include "ViewOutputMessage.h"

/// <summary>
/// Prints title message deposit amount to the console.
/// </summary>
void ViewOutputMessage::print_output_deposit_title()
{
	std::cout << "\n [To deposit amount]";
}

/// <summary>
/// Prints title message withdraw amount to the console
/// </summary>
void ViewOutputMessage::print_output_withdraw_title()
{
	std::cout << "\n [To withdraw amount]";
}

/// <summary>
/// Prints title message transfer amount to the console
/// </summary>
void ViewOutputMessage::print_account_list_title()
{
	std::cout << "\n [Account Holders List] \n";
}

/// <summary>
/// Print header account list to the console
/// </summary>
void ViewOutputMessage::print_account_list_menu()
{
	std::cout << "\n AccountNumber    Name    Type    Balance \n";
}

/// <summary>
/// Print ok message record updated to the console
/// </summary>
void ViewOutputMessage::print_output_record_updated()
{
	std::cout << "\n Record Updated ";
}

/// <summary>
/// Print ok message record deleted to the console
/// </summary>
void ViewOutputMessage::print_output_record_deleted()
{
	std::cout << "\n Record Deleted ";
}

/// <summary>
/// Print message insufficient balance in account
/// </summary>
void ViewOutputMessage::print_output_insufficient_balance()
{
	std::cout << "\n Insufficient Balance ";
}

/// <summary>
/// Print ok message record added to the console
/// </summary>
void ViewOutputMessage::print_output_account_created()
{
	std::cout << "\n Account Created ";
}