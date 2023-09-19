#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1898/
*/

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> numVector;
        // input
        while (n-- > 0)
        {
            int num;
            cin >> num;
            numVector.push_back(num);
        }
        // output
        sort(numVector.begin(), numVector.end());
        for (int i = 0; i < numVector.size(); i++)
        {
            cout << numVector[i] << " ";
        }
        cout << endl;
        // without duplicate
        int len = unique(numVector.begin(), numVector.end()) - numVector.begin();
        for (int i = 0; i < len; i++)
        {
            cout << numVector[i] << " ";
        }
        cout << endl;
        /*
        // set 自动去重排序
        set<int, less<int> > numSet;
        // input
        while (n-- > 0)
        {
            int num;
            cin >> num;
            numSet.insert(num);
        }
        // output
        for (set<int>::iterator it = numSet.begin(); it != numSet.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
        */
    }
    return 0;
}