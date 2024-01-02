#include <iostream>
#include <string>

using namespace std;

string numsToString[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void outputstr(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (i != 0)
            cout << ' ';
        cout << numsToString[str[i] - '0'];
    }
}

int main()
{
    string str;
    cin >> str;
    int sum = 0;
    for (char c : str)
    {
        sum += (c - '0');
    }
    string res = to_string(sum);
    outputstr(res);
    return 0;
}
