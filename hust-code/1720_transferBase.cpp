#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1720/
*/

/* output
10 2
122
00000000 00000000 00000000 01111010
*/

map<char, int> baseMap;

// 第一行输出该十二进制数每一位对应的十进制数（由高位到低位，以空格隔开）
// 第二行输出该十二进制数对应的十进制数
// 返回 10 进制数
int output1(string &base12)
{
    int base10 = 0;
    // traverse
    for (int i = 0; i < base12.length(); i++)
    {
        // character
        if (base12[i] >= 'a' && base12[i] <= 'b')
        {
            cout << baseMap[base12[i]] << " ";
            // add to base10
            base10 = base10 * 12 + baseMap[base12[i]];
        }
        // number
        else
        {
            cout << base12[i] << " ";
            // add to base10
            base10 = base10 * 12 + (base12[i] - '0');
        }
    }
    cout << endl;
    // print base10
    cout << base10 << endl;

    return base10;
}

// 第三行输出转换后的十进制数在内存中的每个二进制位（共4个字节，每字节之间空格隔开）
void output2(int base10)
{
    int base2[32] = {0};
    // 记录当前第几位
    int curBit = 0;
    while (base10 > 0)
    {
        base2[curBit] = base10 % 2;
        base10 /= 2;
        curBit++;
    }
    // 倒序输出
    for (int i = 31; i >= 0; i--)
    {
        if (i % 8 == 7 && i != 31)
        {
            cout << " ";
        }
        cout << base2[i];
    }
    cout << endl;
}

int main()
{
    // 设置 mapping
    baseMap.insert({{'a', 10}, {'b', 11}});
    string base12;
    while (cin >> base12)
    {
        int base10 = output1(base12);
        output2(base10);
    }
    return 0;
}