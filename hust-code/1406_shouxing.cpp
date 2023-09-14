#include <iostream>
#include <cmath>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1406/
*/

int main()
{
    int n;
    while (cin >> n)
    {
        int pown = n * n;
        int mod = 10;
        int lowBit = pown % mod;
        bool flag = false;
        while (pown >= mod)
        {
            if (lowBit == n)
            {
                flag = true;
                break;
            }
            mod = mod * 10;
            lowBit = pown % mod;
        }
        if (flag == true)
        {
            cout << "Yes!" << endl;
        }
        else
        {
            cout << "No!" << endl;
        }
    }
    return 0;
}