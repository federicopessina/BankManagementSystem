#pragma once
class DataBaseFile
{
public:
	static void write_account();
	static void display_sp(int);
	static void modify_account(int accountNumber);
	static void delete_account(int accountNumber);
	static void display_all();
	static void deposit_withdraw(int accountNumber, int option);
};

