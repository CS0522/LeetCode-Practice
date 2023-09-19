#include <iostream>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1407/
*/

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        int **matrix = new int*[m + 1];
        // init
        for (int i = 0; i <= m; i++)
        {
            matrix[i] = new int[n + 1];
        }
        // input
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        // 求出最大值下标和每行的总和
        for (int i = 1; i <= m; i++)
        {
            int maxIndex = 1;
            int rowSum = 0;
            for (int j = 1; j <= n; j++)
            {
                rowSum += matrix[i][j];
                // 不用等号以确保是下标最小的最大值
                if (matrix[i][j] > matrix[i][maxIndex])
                {
                    // 移动最大值下标
                    maxIndex = j;
                }
            }
            // 总和替代最大值
            matrix[i][maxIndex] = rowSum;
        }
        // print
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}