#include <iostream>
#include <cstring>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1414/
*/

bool isHuiwenStr(string &inputStr)
{
    bool flag = true;
    int strLen = inputStr.length();
    for (int i = 0; i <= strLen / 2; i++)
    {
        if (inputStr[i] != inputStr[strLen - i - 1])
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    string inputStr;
    while (getline(cin, inputStr))
    {
        bool flag = isHuiwenStr(inputStr);
        cout << (flag ? "Yes!" : "No!") << endl;
    }
    return 0;
}