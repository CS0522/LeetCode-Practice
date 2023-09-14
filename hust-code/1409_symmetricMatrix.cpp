#include <iostream>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1409/
*/

int main()
{
    int n;
    while (cin >> n)
    {
        // initialize
        int **matrix = new int*[n];
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        // judge symmetric or not
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] != matrix[j][i])
                {
                    flag = false;
                    break;
                }
            }
        }
        // print
        if (flag)
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