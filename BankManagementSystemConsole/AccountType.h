#pragma once

constexpr auto SAVING_THRESHOLD = 500;
constexpr auto CURRENT_THRESHOLD = 1000;

const struct AccountType
{
private:
	char saving = 'S';
	char current = 'C';
public:
	char get_saving();
	char get_current();
};