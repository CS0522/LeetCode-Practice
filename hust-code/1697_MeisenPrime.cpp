#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1697/
*/

// bool isPrime(long num)
// {
//     long sqr = sqrt(num);
//     for (long i = 2; i <= sqr; i++)
//     {
//         if (num % i == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// 素数筛法
// 返回素数列表
void siftPrime(long n)
{
    // n 个数的长度，初始每个都是 true
    bool *primeArray = new bool[n + 1];
    fill(primeArray, primeArray + n + 1, true);
    primeArray[0] = false;
    primeArray[1] = false;
    long sqr = sqrt(n);
    for (long i = 2; i <= sqr; i++)
    {
        if (primeArray[i] == true)
        {
            // i 的倍数都是合数，翻转为 false
            for (long j = i + i; j <= n; j += i)
            {
                primeArray[j] = false;
            }
            // 判断该数是否符合梅森素数
            if (pow(2, i) - 1 <= n)
            {
                if (primeArray[i] && primeArray[(int)pow(2, i) - 1])
                {
                    cout << "M(" << i << ")=" << pow(2, i) - 1 << endl;
                }
            }
        }
    }
}

int main()
{
    long n;
    while (cin >> n)
    {
        // get prime number list
        siftPrime(n);
    }
    return 0;
}