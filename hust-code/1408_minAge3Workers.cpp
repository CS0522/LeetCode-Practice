#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1408/
*/

class Worker
{
public:
    int id;
    string name;
    int age;
};

// 关键字顺序：年龄>工号>姓名，从小到大
bool cmp(Worker a, Worker b)
{
    if (a.age == b.age)
    {
        if (a.id == b.id)
        {
            return a.name < b.name;
        }
        else
        {
            return a.id < b.id;
        }
    }
    else
    {
        return a.age < b.age;
    }
}

int main()
{
    int N;
    while (cin >> N)
    {
        int n = N;
        vector<Worker> workerVector;
        while (n-- > 0)
        {
            Worker newWorker;
            cin >> newWorker.id >> newWorker.name >> newWorker.age;
            workerVector.push_back(newWorker);
        }
        // sort
        sort(workerVector.begin(), workerVector.end(), cmp);
        // output
        int printNum = N > 3 ? 3 : N;
        for (int i = 0; i < printNum; i++)
        {
            cout << workerVector[i].id << " " << workerVector[i].name << " " << workerVector[i].age << endl;
        }
    }
    return 0;
}