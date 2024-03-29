#pragma once

class Account
{
private:
	int acno, deposit;
	char name[50], type;
public:
	void create_account();
	void print_account_list() const;
	void print_output_balance_amount() const;
	void print_output_account_type() const;
	void print_output_account_holder() const;
	void print_output_account_number() const;
	void modify();
	void print_input_modify_account_type();
	void print_input_modify_balance_amount();
	void print_output_account_holder_name();
	void make_deposit(int);
	void withdraw(int);
	void report() const;
	int get_account_number() const;
	int get_deposit() const;
	char get_account_type() const;

};

