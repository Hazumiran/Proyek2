#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()

{
	string userString;
	double userStringLength;
	int rightBound;
	int leftBound;
	bool wrapNeeded;
	cout << "Enter string." << endl;
	getline (cin, userString);
	userStringLength = userString.length() - 1;
	leftBound = 0;
	
	while (leftBound <= userStringLength)
	{
		while (userString[leftBound] == ' ')
			{
				leftBound++;
			}
		if (leftBound + 79 > userStringLength)
			rightBound = userStringLength;
		else
			rightBound = leftBound + 79;
		wrapNeeded = true;
		if (leftBound + 80 <= userStringLength)
		{
			if (userString[leftBound + 80] == ' ')
				wrapNeeded = false;
		}
		if (userString[rightBound] == ' ')
			wrapNeeded = false;				
		if (rightBound - leftBound == 79 && wrapNeeded == true)
		{
			for (int i = rightBound; i >= leftBound; i--)
			{
				if (userString[i] == ' ')
				{
					rightBound = i;
					break;
				}
			}
		}		
		for (int i = leftBound; i <= rightBound; i++)
		{
			cout<< userString[i];
		}		
		if (wrapNeeded == true)
			cout << endl;

		leftBound = rightBound + 1;	
	}
	cout << endl;
	cout << "End";
	_getch();
	return 0;
}
