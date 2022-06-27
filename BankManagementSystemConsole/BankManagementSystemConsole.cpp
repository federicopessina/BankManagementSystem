#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

#include "Account.h"

using namespace std;

void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
void intro();


int main()
{
    char ch;
    int num;
    intro();
    do
    {
        system("cls");
        std::cout << "\n Main Menu";
        std::cout << "\n 1. New Account";
        std::cout << "\n 2. Deposit Amount";
        std::cout << "\n 3. Withdraw Amount";
        std::cout << "\n 4. Balance Enquiry";
        std::cout << "\n 5. All Account Order list";
        std::cout << "\n 6. Close an Account";
        std::cout << "\n 7. Modify an Account";
        std::cout << "\n 8. Exit";
        std::cout << "\n Select your Option";

        std::cin >> ch;
        system("cls");
        switch (ch)
        {
        case '1':
            write_account();
            break;
        case '2':
            std::cout << "\n Enter the Account No.";
            std::cin >> num;
            deposit_withdraw(num, 1);
            break;
        case '3':
            std::cout << "\n Enter the Account No.";
            std::cin >> num;
            deposit_withdraw(num, 2);
            break;
        case '4':
            std::cout << "\n Enter the Account No.";
            std::cin >> num;
            display_sp(num);
            break;
        case '5':
            display_all();
            break;
        case '6':
            std::cout << "\n Enter the Account No.";
            std::cin >> num;
            delete_account(num);
            break;
        case '7':
            std::cout << "\n Enter the Account No.";
            std::cin >> num;
            modify_account(num);
            break;
        case '8':
            std::cout << "\n Thanks for using BankingSystem App";
            break;
        default:
            std::cout << "\a";
        }
        std::cin.ignore();
        std::cin.get();

    } while (ch != '8');

    return 0;
}

void write_account()
{
    Account ac;
    ofstream outfile;
    outfile.open("account.dat", ios::binary | ios::app);
    ac.create_account();
    outfile.write(reinterpret_cast<char*> (&ac), sizeof(Account));
    outfile.close();
}

void display_sp(int)
{
    Account ac;
    bool flag = false;
    ifstream infile;
    infile.open("account.dat", ios::binary);
    if (!infile)
    {
        std::cout << "File could not be open. Press any key.";
        return;
    }
}

void modify_account(int n)
{
    bool found = false;
    Account ac;
    std::fstream file;
    file.open("account.dat", ios::binary | ios::in | ios::out);
    if (!file)
    {
        std::cout << "File could not be open. Press Any key. ";
        return;
    }

    while (!file.eof() && found == false)
    {
        file.read(reinterpret_cast<char*> (&ac), sizeof(Account));
        if (ac.get_acno() == n)
        {
            ac.show_account();
            std::cout << "\n Enter the New Details Account " << std::endl;
            ac.modify();
            int pos = (-1) * static_cast<int> (sizeof(Account));
            file.seekp(pos, ios::cur);
            file.write(reinterpret_cast<char*> (&ac), sizeof(Account));
            std::cout << "\n Record Updated";
            found = true;

        }
    }
    file.close();
    if (found == false)
    {
        std::cout << "\n Record Not Found";
    }

}

void delete_account(int n)
{
    Account ac;
    ifstream infile;
    ofstream outfile;
    infile.open("account.dat", ios::binary);
    if (!infile)
    {
        std::cout << "File could not be open. Press any key.";
        return;
    }
    outfile.open("Temp.dat", ios::binary);
    infile.seekg(0, ios::beg);
    while (infile.read(reinterpret_cast<char*> (&ac), sizeof(Account)))
    {
        if (ac.get_acno() != n)
        {
            outfile.write(reinterpret_cast<char*> (&ac), sizeof(Account));
        }
    }
    infile.close();
    outfile.close();
    remove("account.dat");
    rename("Temp.dat", "account.dat");
    std::cout << "\n Record Deleted.";
}

void display_all()
{
    Account ac;
    ifstream infile;
    infile.open("account.dat", ios::binary);
    if (!infile)
    {
        std::cout << "file could not be open. Press any key.";
        return;
    }

    std::cout << "\n Account Holder list. \n";
    std::cout << "\n A/C No.    Name    Type    Balance \n";
    while (infile.read(reinterpret_cast<char*> (&ac), sizeof(Account)))
    {
        ac.report();
    }
    infile.close();
}

void deposit_withdraw(int n, int option)
{
    int amt;
    bool found = false;
    Account ac;
    fstream file;
    file.open("account.dat", ios::binary | ios::in | ios::out);
    if (!file)
    {
        std::cout << "File could not be open. Press any key.";
        return;
    }
    while (!file.eof() && found == false)
    {
        file.read(reinterpret_cast<char*> (&ac), sizeof(Account));
        if (ac.get_acno() == n)
        {
            ac.show_account();
            if (option == 1)
            {
                std::cout << "\n To deposit amount. ";
                std::cout << "\n Enter the amount to deposit. ";
                std::cin >> amt;
                ac.make_deposit(amt);
            }
            if (option == 2)
            {
                std::cout << "\n To withdraw amount";
                std::cout << "\n Enter the amount to withdraw. ";
                std::cin >> amt;
                int bal = ac.get_deposit() - amt;
                if ((bal < 500 && ac.get_account_type() == 'S' || (bal < 1000 && ac.get_account_type() == 'C')))
                {
                    std::cout << "insufficient balance";
                }
                else
                {
                    ac.withdraw(amt);
                }
            }

            int pos = (-1) * static_cast<int>(sizeof(ac));
            file.seekp(pos, ios::cur);
            file.write(reinterpret_cast<char*> (&ac), sizeof(Account));
            std::cout << "\n Record Updated";
            found = true;
        }
    }
    file.close();
    if (found == false)
    {
        std::cout << "\n Record Not Found ";
    }
}

void intro()
{
    std::cout << "Banking System";
    cin.get();
}
