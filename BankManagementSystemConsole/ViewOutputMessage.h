#pragma once
#include "View.h"
class ViewOutputMessage :
    public View
{
public:
    static void print_output_deposit_title();
    static void print_output_withdraw_title();
    static void print_account_list_title();
    static void print_account_list_menu();
    static void print_output_record_updated();
    static void print_output_record_deleted();
    static void print_output_insufficient_balance();
};

