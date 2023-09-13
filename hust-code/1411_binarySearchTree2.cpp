#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1411/
*/

class Node
{
public:
    int num;
    Node *lchild = nullptr;
    Node *rchild = nullptr;
};

// 插入节点
void insert(Node *&root, int newVal)
{
    // empty tree, create a new tree
    if (root == nullptr)
    {
        root = new Node;
        root->num = newVal;
        root->lchild = nullptr;
        root->rchild = nullptr;
        return;
    }
    // insert
    if (newVal < root->num)
    {
        insert(root->lchild, newVal);
    }
    else if (newVal > root->num)
    {
        insert(root->rchild, newVal);
    }
}

void visit(Node *root)
{
    if (root != nullptr)
    {
        cout << root->num << " ";
    }
}

void preOrder(Node *root)
{
    if (root != nullptr)
    {
        visit(root);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

void inOrder(Node *root)
{
    if (root != nullptr)
    {
        inOrder(root->lchild);
        visit(root);
        inOrder(root->rchild);
    }
}

void postOrder(Node *root)
{
    if (root != nullptr)
    {
        postOrder(root->lchild);
        postOrder(root->rchild);
        visit(root);
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        Node *root = nullptr;
        int newVal;
        // 循环接收输入节点 num
         while (n-- > 0)
        {
            cin >> newVal;
            insert(root, newVal);
        }
        // print
        preOrder(root);
        cout << endl;
        inOrder(root);
        cout << endl;
        postOrder(root);
        cout << endl;
    }
    return 0;
}