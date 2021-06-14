#include "libfileprocessor/chooseDir.h"
#include <iostream>
#include <stdlib.h>

void chooseDir(char* dir)
{
    system("clear");
    std::cout << std::endl
              << "Enter path to the directory, relatively start of program: ";
    std::cin >> dir;
}
