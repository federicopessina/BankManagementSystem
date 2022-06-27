#include <iostream>

#include "ViewException.h"

void ViewException::print_filenotfound_exception()
{
	std::cout << "File could not be open. Press Any key to go on. ";
}

void ViewException::print_recordnotfound_exception()
{
	std::cout << "\n Record Not Found ";
}
