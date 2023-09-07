#include <iostream>
#include <stack>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1417/
*/

int main()
{
    stack<int> numStack;
    int n;
    while (cin >> n)
    {
        while (n > 0)
        {
            int m = n % 8;
            numStack.push(m);
            n = n / 8;
        }
        // print
        int result = 0;
        while (!numStack.empty())
        {
            result *= 10;
            result += numStack.top();
            numStack.pop();
        }
        cout << result << endl;
    }
    return 0;
}