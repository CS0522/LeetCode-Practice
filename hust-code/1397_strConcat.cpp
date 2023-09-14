#include <iostream>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1397/
不使用任何字符串库函数
*/

string concatStr(string &str1, string &str2)
{
    string str3;
    str3 = str1 + str2;

    return str3;
}

int main()
{
    string str1;
    string str2;
    while (cin >> str1 >> str2)
    {
        cout << concatStr(str1, str2) << endl;
    }
    return 0;
}