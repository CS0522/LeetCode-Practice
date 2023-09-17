#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1416/
*/

void calFactorial(int num, vector<int> &fatorialArray)
{
    fatorialArray.push_back(fatorialArray[num - 1] * num);
}

int main()
{
    int n;
    while (cin >> n)
    {
        int y1 = 0, y2 = 0;
        vector<int> fatorialArray;
        // 0 != 0
        fatorialArray.push_back(1);
        // 计算阶乘和 y1，y2
        for (int i = 1; i <= n; i++)
        {
            calFactorial(i, fatorialArray);
            // 奇数 y1
            if (i % 2 != 0)
            {
                y1 += fatorialArray[i];
            }
            // 偶数 y2
            else
            {
                y2 += fatorialArray[i];
            }
        }
        // print
        cout << y1 << " " << y2 << endl;
    }
    return 0;
}