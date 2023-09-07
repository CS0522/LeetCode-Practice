#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1399/
*/

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> numVector;
        while (n-- > 0)
        {
            int num;
            cin >> num;
            numVector.push_back(num);
        }
        // sort
        sort(numVector.begin(), numVector.end(), cmp);

        // print
        for (int i = 0; i < numVector.size(); i++)
        {
            cout << numVector[i] << " ";
        }
        cout << endl;
    }

    return 0;
}