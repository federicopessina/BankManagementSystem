#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include "Account.h"
#include "View.h"
#include "ViewException.h"
#include "ViewInputMessage.h"
#include "ViewOutputMessage.h"
#include "File.h"
#include "AccountType.h"
#include "DataBaseFile.h"
#include "BankManagementSystemConsole.h"
#include "Model.h"

int main()
{
	Model::main_loop();
	return 0;
}

