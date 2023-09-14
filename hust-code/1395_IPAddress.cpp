#include <iostream>
#include <cstring>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1395/
*/

bool isInRange(int num)
{
    if (num >= 0 && num <= 255)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValid(string &ipAddress)
{
    // 标记是否合法
    bool flag = true;
    // 每一段的数
    string numStr = "";
    // get numbers
    for (int i = 0; i <= ipAddress.length(); i++)
    {
        if (ipAddress[i] == '.' || (i == ipAddress.length()))
        {
            // 判断该段的数是否合法
            // stoi() 转换为字符串
            flag = isInRange(stoi(numStr));
            if (flag == false)
            {
                return flag;
            }
            else
            {
                numStr = "";
            }
        }
        else
        {
            numStr = numStr + ipAddress[i];
        }
    }

    return flag;
}

int main()
{
    string ipAddress;
    while (cin >> ipAddress)
    {
        cout << (isValid(ipAddress) ? "Yes!" : "No!") << endl;
    }
    return 0;
}