#include <iostream>
#include <cstring>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1401/
*/

class Node
{
public: 
    char c;
    Node *lchild = nullptr;
    Node *rchild = nullptr;
};

void visit(Node *node)
{
    if (node != nullptr)
    {
        cout << node->c;
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

Node* buildBinaryTree(Node *root, string preOrder, string inOrder)
{
    // break the recursive
    if (preOrder.length() == 0 || inOrder.length() == 0)
    {
        return nullptr;
    }
    // set root node 
    root->c = preOrder[0];
    int rootIndex = inOrder.find(preOrder[0]);
    string lPreOrder = preOrder.substr(1, rootIndex);
    string rPreOrder = preOrder.substr(1 + rootIndex, preOrder.length() - 1 - rootIndex);
    string lInOrder = inOrder.substr(0, rootIndex);
    string rInOrder = inOrder.substr(rootIndex + 1, inOrder.length() - 1 - rootIndex);
    
    // build left and right child Binary Tree
    root->lchild = buildBinaryTree(new Node, lPreOrder, lInOrder);
    root->rchild = buildBinaryTree(new Node, rPreOrder, rInOrder);

    return root;
}

int main()
{
    string preOrderStr;
    string inOrderStr;
    while (cin >> preOrderStr >> inOrderStr)
    {
        Node *root = new Node;
        // build a tree(root) from pre order and in order
        root = buildBinaryTree(root, preOrderStr, inOrderStr);
        // post order traversal
        postOrder(root);
        cout << endl;
    }
    return 0;
}