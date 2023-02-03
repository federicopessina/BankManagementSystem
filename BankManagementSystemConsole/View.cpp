#include <stdlib.h>
#include <iostream>

#include "View.h"

void View::clear_console()
{
	system("cls");
}

void View::print_intro()
{
	std::cout << "\n [Welcome to BankManagementSystem]";
	std::cout << "\n Press Enter to go on";
}

void View::print_menu()
{
    View::clear_console();
    std::cout << "\n [Main Menu]";
    std::cout << "\n [1] New Account";
    std::cout << "\n [2] Deposit Amount";
    std::cout << "\n [3] Withdraw Amount";
    std::cout << "\n [4] Balance Enquiry";
    std::cout << "\n [5] All Account Order list";
    std::cout << "\n [6] Close an Account";
    std::cout << "\n [7] Modify an Account";
    std::cout << "\n [8] Exit";
    std::cout << "\n Select your option : ";
}

void View::print_greetings()
{
    std::cout << "\n Thanks for using the BankManagementSystem App";
}
