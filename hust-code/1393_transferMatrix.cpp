#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1393/
*/

int main()
{
    int n;
    while (cin >> n)
    {
        /*
        // initialize a matrix
        int **matrix = new int*[n];
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new int[n];
        }
        // input 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        // transfer and output
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[j][i] << " ";
            }
            cout << endl;
        }
        */
        // initialize
        vector<vector<int> > matrix;
        for (int i = 0; i < n; i++)
        {
            vector<int> row;
            for (int j = 0; j < n; j++)
            {
                int newVal;
                cin >> newVal;
                row.push_back(newVal);
            }
            matrix.push_back(row);
        }
        // print
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[j][i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}