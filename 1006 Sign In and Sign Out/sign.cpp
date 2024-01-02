#include <iostream>
#include <string>
using namespace std;

typedef struct Time
{
    int hour;
    int minute;
    int second;
} mytime;

mytime totime(string str)
{
    mytime t;
    t.hour = (str[0] - '0') * 10 + (str[1] - '0');
    t.minute = (str[3] - '0') * 10 + (str[4] - '0');
    t.second = (str[6] - '0') * 10 + (str[7] - '0');
    return t;
}

bool largethan(mytime t1, mytime t2)
{
    if (t1.hour > t2.hour)
        return true;
    if (t1.minute > t2.minute)
        return true;
    if (t1.second > t2.second)
        return true;
    return false;
}

int main()
{
    int M;
    cin >> M;
    mytime earliest;
    earliest.hour = 23;
    earliest.minute = 59;
    earliest.second = 59;
    string e = "";

    mytime lastest;
    lastest.hour = 0;
    lastest.minute = 0;
    lastest.second = 0;
    string l = "";
    for (int i = 0; i < M; i++)
    {
        string ID;
        cin >> ID;
        string str1;
        cin >> str1;
        mytime time1 = totime(str1);
        if (!largethan(time1, earliest))
        {
            earliest = time1;
            e = ID;
        }
        string str2;
        cin >> str2;
        mytime time2 = totime(str2);
        if (largethan(time2, lastest))
        {
            lastest = time2;
            l = ID;
        }
    }

    cout << e << ' ' << l;
    return 0;
}