#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1396/
*/

class Node
{
public:
    int num;
    Node *lchild = nullptr;
    Node *rchild = nullptr;
};

// return father node's value
// 用 father 记录当前的 father node 的值
int insert(Node *&root, int newVal, int father)
{
    if (root == nullptr)
    {
        root = new Node;
        root->num = newVal;
        return father;
    }
    if (newVal < root->num)
    {
        return insert(root->lchild, newVal, root->num);
    }
    else if (newVal > root->num)
    {
        return insert(root->rchild, newVal, root->num);
    }
}

int main()
{
    int N;
    int newVal;
    while (cin >> N)
    {
        // store results
        vector<int> results;
        // first node
        Node *root = new Node;
        cin >> newVal;
        root->num = newVal;
        N -= 1;
        // no father node: -1
        results.push_back(-1);

        while (N-- > 0)
        {
            cin >> newVal;
            results.push_back(insert(root, newVal, -1));
        }
        // print
        for (int i = 0; i < results.size(); i++)
        {
            cout << results[i] << endl;
        }
    }
    return 0;
}