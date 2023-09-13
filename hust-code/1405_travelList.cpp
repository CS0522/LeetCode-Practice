#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1405/
*/

bool cmp(int a, int b)
{
    return a < b;
}

class Node
{
public:
    int num;
    Node *next = nullptr;
};

void createList(Node *&list, vector<int> nums)
{
    Node *p = list;
    for (int i = 0; i < nums.size(); i++)
    {
        Node *temp = new Node;
        temp->num = nums[i];
        p->next = temp;
        p = temp;
    }
}

void printList(Node *&list)
{
    Node *p = list->next;
    while (p != nullptr)
    {
        cout << p->num << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> nums;
        int newNum;
        // list
        Node *list = new Node;

        while (n-- > 0)
        {
            cin >> newNum;
            nums.push_back(newNum);
        }
        // 先排序 vector
        sort(nums.begin(), nums.end(), cmp);
        // 建立 List
        createList(list, nums);
        // print
        printList(list);
    }
    return 0;
}