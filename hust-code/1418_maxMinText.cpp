#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1418/
*/

int main()
{
    string str;
    vector<string> strVector;
    while (getline(cin, str))
    {
        strVector.push_back(str);
    }
    // get least length
    // get max length
    int leastLen = strVector[0].length(), maxLen = strVector[0].length();
    for (int i = 0; i < strVector.size(); i++)
    {
        if (strVector[i].length() < leastLen)
        {
            leastLen = strVector[i].length();
        }
        if (strVector[i].length() > maxLen)
        {
            maxLen = strVector[i].length();
        }
    }
    // output least
    for (int i = 0; i < strVector.size(); i++)
    {
        if (strVector[i].length() == leastLen)
        {
            cout << strVector[i] << endl;
        }
    }
    // output max
    for (int i = 0; i < strVector.size(); i++)
    {
        if (strVector[i].length() == maxLen)
        {
            cout << strVector[i] << endl;
        }
    }
    return 0;
}