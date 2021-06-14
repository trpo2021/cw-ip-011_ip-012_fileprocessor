#include <iostream>
#include "libfileprocessor/chooseLay.h"

using namespace std;

int chooseLay(char *key)
{
	system("clear");
	cout << endl << "Choose Layout \n1 - numerical\n2 - symbolic\n3 - symbolic (big)\n(1-3): ";
	int chose = 0;
	cin >> chose;
	
	cout << endl << "Enter key word: ";
	cin >> key;

	return chose;
}
