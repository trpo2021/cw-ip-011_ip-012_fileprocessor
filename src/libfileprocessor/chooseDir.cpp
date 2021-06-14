#include <iostream>
#include <stdlib.h>
#include "libfileprocessor/chooseDir.h"

void chooseDir(char *dir)
{
	system("clear");
	std::cout << std::endl << "Enter path to the directory: ";
	std::cin >> dir;
}
