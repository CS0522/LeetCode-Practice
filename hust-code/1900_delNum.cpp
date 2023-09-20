#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1900/
*/

int findMin(string &subStr)
{
    int minIndex = 0;
    for (int i = 0; i < subStr.length(); i++)
    {
        if (subStr[i] < subStr[minIndex])
        {
            minIndex = i;
        }
    }
    return minIndex;
}

int main()
{
    string a;
    int n;
    while (cin >> a >> n)
    {
        vector<char> res;
        // 记录区间内的最小数的 index
        int **sectionMin = new int*[a.length()];
        // 初始化
        for (int i = 0; i < a.length(); i++)
        {
            sectionMin[i] = new int[a.length()];
        }
        // 获取区间内的最小数的 index
        for (int i = 0; i < a.length(); i++)
        {
            for (int j = i; j < a.length(); j++)
            {
                string subStr = a.substr(i, j - i + 1);
                sectionMin[i][j] = findMin(subStr) + i;
            }
        }

        // 记录循环次数
        int count = a.length() - n;
        int minIndex = 0;
        while (count-- > 0)
        {
            // 要选择一个数，区间范围是上一个最小 index 到距离串尾 count 个字符的区间
            minIndex = sectionMin[minIndex + 1][a.length() - 1 - count];
            // 每次在区段内选择最小的数
            res.push_back(a[minIndex]);
        }
        // 输出 res
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i];
        }
        cout << endl;
    }
    return 0;
}