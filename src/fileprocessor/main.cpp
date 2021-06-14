#include <stdio.h>
#include <stdlib.h>
#include "libfileprocessor/chooseDir.h"
#include "libfileprocessor/chooseLay.h"
#include "libfileprocessor/fileRename.h"

int main()
{
	int check, lay;
	char dir[200], key[50];
	lay = 0;
	
	while(1)
	{
	system("clear");
		printf("\n1. Rename files");
		printf("\n2. Choose directiry");
		printf("\n3. Choose layout");
		printf("\n4. Exit program");
		
		if (dir == 0) printf("\n\nCurrent directory: None");
		else printf("\n\nCurrent directory: %s", dir);
		
		if (lay == 0) printf("Current layout: None");
		else if (lay == 1) printf("Current layout: numerical");
		else if (lay == 2) printf("Current layout: symbolic");
		else if (lay == 3) printf("Current layout: symbolic(big)");
		
		if (key == 0) printf("Current keyword: None");
		else printf("Current keyword: %s", key);
		
		printf("\n\nType option(1-4): ");
		scanf("%d", &check);
		
		switch(check)
		{
			case 1:
				fileRename(key, dir, lay); 
				break;
			case 2:
				chooseDir(dir);
				break;
			case 3:
				lay = chooseLay(key);
				break;
			case 4:
				printf("\nExiting program");
				return 0;
			default:
				printf("\nWrong input");
		}
		
	}
}
