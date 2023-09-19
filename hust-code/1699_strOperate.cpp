#include <iostream>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1699/
*/

/*
原文：aD
密文：cF
c  11100011  227
F  01000110  70
*/

// 明文变密文
void transfer(string origin, string &cipher, int *&base10Array)
{
    for (int i = 0; i < origin.length(); i++)
    {
        char asciiCode = origin[i];
        // 后移 2 位
        asciiCode = asciiCode + 2;
        // 如果偏移后超过字母字符
        if (asciiCode > 'Z' && asciiCode < 'a' || asciiCode > 'z')
        {
            asciiCode -= 26;
        }

        cipher = cipher + asciiCode;
        base10Array[i] = (int)asciiCode;
    }
}

void decToBin(int *&base10Array, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << (char)base10Array[i] << "  ";

        int bin[8] = {0};
        int num = (int)base10Array[i];
        int count1Num = 0;
        for (int j = 7; num > 0 && j >= 0; j--)
        {
            bin[j] = num % 2;
            num = num / 2;
            if (bin[j] == 1)
            {
                count1Num += 1;
            }
        }
        // 如果偶数个 1，最高位改为 1
        if (count1Num % 2 == 0)
        {
            bin[0] = 1;
            base10Array[i] += 128;
        }
        
        // output binary array
        for (int k = 0; k < 8; k++)
        {
            cout << bin[k];
        }
        cout << "  " << (int)base10Array[i] << endl;
    }
}

int main()
{
    string origin;
    while (cin >> origin)
    {
        // 密文
        string cipher = "";
        // 存放 10 进制数
        int *base10Array = new int[origin.length()];
        transfer(origin, cipher, base10Array);
        // output
        cout << "原文：" << origin << endl;
        cout << "密文：" << cipher << endl;
        decToBin(base10Array, origin.length());
    }
    return 0;
}