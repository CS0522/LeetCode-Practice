#include <iostream>
#include <vector>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1415/
*/

int main()
{
    string str;
    while (cin >> str)
    {
        // 用 char 的 asic 码作下标
        vector<vector<int> > loc(300);
        // 标记是否已输出
        int flag[300] = {false};
        for (int i = 0; i < str.length(); i++)
        {
            loc[str[i]].push_back(i);
        }
        // print
        for (int i = 0; i < str.length(); i++)
        {
            if (loc[str[i]].size() > 1 && flag[str[i]] == false)
            {
                flag[str[i]] = true;
                for (int j = 0; j < loc[str[i]].size(); j++)
                {
                    cout << (j == 0 ? "" : ",") << str[i] << ":" << loc[str[i]][j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}