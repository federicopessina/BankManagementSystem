#pragma once

class Account
{
private:
	int acno, deposit;
	char name[50], type;
public:
	void create_account();
	void print_account_list() const;
	void modify();
	void make_deposit(int);
	void withdraw(int);
	void report() const;
	int get_account_number() const;
	int get_deposit() const;
	char get_account_type() const;

};

