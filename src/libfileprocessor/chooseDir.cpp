#include <iostream>
#include "libfileprocessor/chooseDir.h"

void chooseDir(char *dir)
{
	std::cout << std::endl << "Enter path to the directory: ";
	std::cin >> dir;
}
