#include <iostream>

using namespace std;

int chooseLay(char *key)
{
	cout << endl << "Choose Layout:\n1 - numerical\n2 - symbolic\n3 - symbolic (big)";
	int chose = 0;
	cin >> chose;
	
	cout << endl << "Enter key word: ";
	cin >> key;

	return chose;
}
