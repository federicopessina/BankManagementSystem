#include <fstream>
#include <iostream>
#include "DataBaseFile.h"
#include "Account.h"
#include "Account.h"
#include "File.h"
#include "ViewException.h"
#include "ViewInputMessage.h"
#include "ViewOutputMessage.h"
#include "AccountType.h"

void DataBaseFile::write_account()
{
	Account account;
	File filePath;
	std::ofstream outfile;

	//outfile.open("account.dat", std::ios::binary | std::ios::app);
	outfile.open(filePath.get_account_filename(), std::ios::binary | std::ios::app);
	account.create_account();
	outfile.write(reinterpret_cast<char*> (&account), sizeof(Account));
	outfile.close();
}

void DataBaseFile::display_sp(int)
{
	bool flag = false;
	File filePath;
	std::ifstream infile;

	infile.open(filePath.get_account_filename(), std::ios::binary);
	if (!infile)
	{
		ViewException::print_filenotfound_exception();
		return;
	}
}

void DataBaseFile::modify_account(int accountNumber)
{
	bool isFound = false;
	Account account;
	File filePath;
	std::fstream file;

	file.open(filePath.get_account_filename(), std::ios::binary | std::ios::in | std::ios::out);
	if (!file)
	{
		ViewException::print_filenotfound_exception();
		return;
	}

	while (!file.eof() && isFound == false)
	{
		file.read(reinterpret_cast<char*> (&account), sizeof(Account));
		if (account.get_account_number() == accountNumber)
		{
			account.print_account_list();
			ViewInputMessage::print_input_details_new_account();

			account.modify();
			int position = (-1) * static_cast<int> (sizeof(Account));
			file.seekp(position, std::ios::cur);
			file.write(reinterpret_cast<char*> (&account), sizeof(Account));

			ViewOutputMessage::print_output_record_updated();
			isFound = true;

		}
	}
	file.close();
	if (isFound == false)
	{
		ViewException::print_recordnotfound_exception();
	}

}

void DataBaseFile::delete_account(int accountNumber)
{
	Account account;
	std::ifstream infile;
	std::ofstream outfile;
	File filePath;

	infile.open(filePath.get_account_filename(), std::ios::binary);
	if (!infile)
	{
		ViewException::print_filenotfound_exception();
		return;
	}

	outfile.open(filePath.get_temporary_filename(), std::ios::binary);
	infile.seekg(0, std::ios::beg);

	while (infile.read(reinterpret_cast<char*> (&account), sizeof(Account)))
	{
		if (account.get_account_number() != accountNumber)
		{
			outfile.write(reinterpret_cast<char*> (&account), sizeof(Account));
		}
	}

	infile.close();
	outfile.close();

	remove(filePath.get_account_filename().c_str());
	rename(filePath.get_temporary_filename().c_str(), filePath.get_account_filename().c_str());

	ViewOutputMessage::print_output_record_deleted();

}

void DataBaseFile::display_all()
{

	Account ac;
	std::ifstream infile;
	File filePath;

	infile.open(filePath.get_account_filename(), std::ios::binary);
	if (!infile)
	{
		ViewException::print_filenotfound_exception();
		return;
	}

	ViewOutputMessage::print_account_list_title();
	ViewOutputMessage::print_account_list_menu();
	while (infile.read(reinterpret_cast<char*> (&ac), sizeof(Account)))
	{
		ac.report();
	}
	infile.close();

}

void DataBaseFile::deposit_withdraw(int accountNumber, int option)
{

	int amount;
	bool isFound = false;
	Account account;
	std::fstream file;
	File filePath;
	AccountType accountType;

	file.open(filePath.get_account_filename(), std::ios::binary | std::ios::in | std::ios::out);
	if (!file)
	{
		ViewException::print_filenotfound_exception();
		return;
	}
	while (!file.eof() && isFound == false)
	{
		file.read(reinterpret_cast<char*> (&account), sizeof(Account));
		if (account.get_account_number() == accountNumber)
		{
			account.print_account_list();
			if (option == 1)
			{
				ViewOutputMessage::print_output_deposit_title();
				ViewInputMessage::print_input_amount_to_deposit();
				std::cin >> amount;
				account.make_deposit(amount);
			}
			if (option == 2)
			{
				ViewOutputMessage::print_output_withdraw_title();
				ViewInputMessage::print_input_amout_to_withdraw();
				std::cin >> amount;

				int balance = account.get_deposit() - amount;
				if ((balance < SAVING_THRESHOLD && account.get_account_type() == accountType.get_saving()
					|| (balance < CURRENT_THRESHOLD && account.get_account_type() == accountType.get_current())))
				{
					ViewOutputMessage::print_output_insufficient_balance();
				}
				else
				{
					account.withdraw(amount);
				}
			}

			int pos = (-1) * static_cast<int>(sizeof(account));
			file.seekp(pos, std::ios::cur);
			file.write(reinterpret_cast<char*> (&account), sizeof(Account));
			ViewOutputMessage::print_output_record_updated();
			isFound = true;
		}
	}

	file.close();

	if (isFound == false)
	{
		ViewException::print_recordnotfound_exception();
	}
}
