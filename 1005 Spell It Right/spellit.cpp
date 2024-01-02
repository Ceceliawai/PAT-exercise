#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void outputstr(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (i != 0)
			cout << ' ';
		switch (str[i])
		{
		case '0':
			cout << "zero";
			break;
		case '1':
			cout << "one";
			break;
		case '2':
			cout << "two";
			break;
		case '3':
			cout << "three";
			break;
		case '4':
			cout << "four";
			break;
		case '5':
			cout << "five";
			break;
		case '6':
			cout << "six";
			break;
		case '7':
			cout << "seven";
			break;
		case '8':
			cout << "eight";
			break;
		case '9':
			cout << "nine";
			break;
		} // end swtich
	}	  // end for
	return;
}
int mytoi(char c)
{
	switch (c)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	}
}

int main()
{
	string str;
	cin >> str;
	int sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		sum += mytoi(str[i]);
	}
	string res;
	res = to_string(sum);
	outputstr(res);
	return 0;
}