#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1413/
*/

/*
主要问题：数值范围会很大，需要用到 long 型
*/

/* 递归方式
lon upstair(int totalStep)
{
    if (totalStep == 1)
    {
        return 1;
    }
    else if (totalStep == 2)
    {
        return 2;
    }
    else
    {
        return (upstair(totalStep - 1) + upstair(totalStep - 2));
    }
}

int main()
{
    int N;
    while (cin >> N)
    {
        cout << upstair(N) << endl;
    }
    return 0;
}
*/

// 栈
void upstair(int totalStep)
{
    // 当前阶梯
    int curStep = 2;
    // stack
    stack<long> stepStack;
    stepStack.push(1);
    stepStack.push(2);
    while (curStep < totalStep)
    {
        // 取上面两个（不删除，看作 N-1, N-2），相加后结果压入栈
        long a = stepStack.top();
        stepStack.pop();
        long b = stepStack.top();
        stepStack.push(a);
        stepStack.push(a + b);
        curStep += 1;
    }
    // print
    if (totalStep == 0)
    {
        cout << 0 << endl;
    }
    else if (totalStep == 1)
    {
        cout << 1 << endl;
    }
    else 
    {
        cout << stepStack.top() << endl;
    }
}

int main()
{
    int N;
    while (cin >> N)
    {
        upstair(N);
    }
    return 0;
}