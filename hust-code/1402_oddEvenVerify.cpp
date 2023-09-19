#include <iostream>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1402/
*/

void verifyChar(char target)
{
    int asciiCode = (int)target;
    // dec to bin
    int bin[8] = {0};
    int count1 = 0;
    for (int i = 7; asciiCode > 0 && i >= 0; i--)
    {
        bin[i] = asciiCode % 2;
        asciiCode /= 2;
        if (bin[i] == 1)
        {
            count1 += 1;
        }
    }
    // 奇校验
    if (count1 % 2 == 0)
    {
        bin[0] = 1;
    }
    // output
    for (int i = 0; i < 8; i++)
    {
        cout << bin[i];
    }
    cout << endl;
}

int main()
{
    string str;
    while (cin >> str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            verifyChar(str[i]);
        }
    }
    return 0;
}