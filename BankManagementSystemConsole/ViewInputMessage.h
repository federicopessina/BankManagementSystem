#pragma once
#include "View.h"
class ViewInputMessage :
    public View
{
public:
    static void print_input_account_number();
    static void print_input_details_new_account();
    static void print_input_amount_to_deposit();
    static void print_input_amout_to_withdraw();
    static void print_input_name_account_holder();
    static void print_input_type_of_account();
    static void print_input_initial_amount();
};

