#include <iostream>
#define ROW 4
#define COL 5
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1403/
*/

int main()
{
    int matrix[ROW][COL];
    while (true)
    {
        // input
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                cin >> matrix[i][j];
            }
        }
        // new matrix to store biggest and second biggest index
        int index[2][COL];
        // traverse
        for (int col = 0; col < COL; col++)
        {
            int large1Index = 0;
            // large1Index
            for (int row = 0; row < ROW; row++)
            {
                if (matrix[row][col] > matrix[large1Index][col])
                {
                    large1Index = row;
                }
            }
            int large2Index = large1Index == 0 ? 1 : 0;
            // large2Index
            for (int row = 0; row < ROW; row++)
            {
                if (matrix[row][col] > matrix[large2Index][col] && row != large1Index)
                {
                    large2Index = row;
                }
            }
            // 保存在 index 数组中
            // 保持行值从小到大的顺序
            index[0][col] = large1Index < large2Index ? large1Index : large2Index;
            index[1][col] = large1Index > large2Index ? large1Index : large2Index;
        }
        // output
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                cout << matrix[index[i][j]][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}