#include <iostream>
#include <cstring>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1719/
*/

int main()
{
    string sentence;
    while (getline(cin, sentence))
    {
        int countChar = 0, countWord = 0;
        // 用 asic 码作下标
        int countTimes[300] = {0};
        for (int i = 0; i < sentence.length(); i++)
        {
            // 统计字符
            if (sentence[i] != ' ')
            {
                countChar += 1;
                countTimes[sentence[i]] += 1;
            }
            // 统计单词
            else
            {
                countWord += 1;
            }
        }
        countWord += 1;
        // 最多出现次数
        int maxCount = 0;
        for (int i = 0; i < 300; i++)
        {
            if (countTimes[i] > maxCount)
            {
                maxCount = countTimes[i];
            }
        }
        // print
        cout << countChar << endl;
        cout << countWord << endl;
        for (int i = 0; i < 300; i++)
        {
            if (countTimes[i] == maxCount)
            {
                cout << (char)i << " ";
            }
        }
        cout << endl << maxCount << endl;
    }
    return 0;
}