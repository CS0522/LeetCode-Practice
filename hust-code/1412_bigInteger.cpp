#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1412/
*/

class BigInteger
{
public:
    string num;
    // 1 <= length <= 1000
    int length;
};

// 比较函数
bool cmp(BigInteger a, BigInteger b)
{
    // 从小到大
    // 若长度相同，则按字典排序
    if (a.length == b.length)
    {
        return a.num < b.num;
    }
    // 若长度不同，则按大整数长度排序
    else 
    {
        return a.length < b.length;
    }
}

int main()
{
    int N;
    while (cin >> N)
    {
        // vector
        vector<BigInteger> numVector;
        while (N-- > 0)
        {
            string readNum;
            cin >> readNum;
            BigInteger newNum;
            newNum.num = readNum;
            newNum.length = readNum.length();
            // push into vector
            numVector.push_back(newNum);
        }
        // sort
        sort(numVector.begin(), numVector.end(), cmp);

        // print
        for (int i = 0; i < numVector.size(); i++)
        {
            cout << numVector[i].num << endl;
        }
    }

    return 0;
}