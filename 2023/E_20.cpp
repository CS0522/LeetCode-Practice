/**
 * 20. 有效的括号
 * https://leetcode.cn/problems/valid-parentheses/
*/
#include <iostream>
#include <stack>
#include <map>

using namespace std;

class Solution
{
    public:
        bool isValid(string s) 
        {
        // 初始化栈
        stack<char> tempStack;
        // 初始化 map
        map<char, char> tempMap = 
        {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };
        // 循环遍历string
        for (int i = 0; i < s.size(); i++)
        {
            // 如果 s[i] 是左括号，加入栈
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                tempStack.push(s[i]);
            }
            // 如果 s[i] 是右括号，进行匹配
            else
            {
                if (!tempStack.empty())
                {
                    // 如果栈弹出的括号不匹配，返回 false
                    if (s[i] != tempMap[tempStack.top()])
                    {
                        return false;
                    }
                    // pop
                    tempStack.pop();
                }
                // 栈空，返回false
                else 
                {
                    return false;
                }
            }
        }
        // 若栈非空，返回 false
        return tempStack.empty();
    }
};

int main()
{
    Solution solution;
    // test
    string testArray[] = {"(){}[]", "]", "(({{}}))", "({)}"};
    for (int i = 0; i < sizeof(testArray) / sizeof(testArray[0]); i++)
    {
        cout << solution.isValid(testArray[i]) << endl;
    }
    
    system("pause");
    return 0;
}