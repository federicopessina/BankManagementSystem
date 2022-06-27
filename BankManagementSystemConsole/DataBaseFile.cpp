#include <fstream>
#include "DataBaseFile.h"
#include "Account.h"
#include "Account.h"
#include "File.h"

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
