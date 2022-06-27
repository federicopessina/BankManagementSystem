#pragma once

class Account
{
private:
	int acno, deposit;
	char name[50], type;
public:
	void create_account();
	void show_account() const;
	void modify();
	void make_deposit(int);
	void withdraw(int);
	void report() const;
	int get_acno() const;
	int get_deposit() const;
	char get_account_type() const;

};

