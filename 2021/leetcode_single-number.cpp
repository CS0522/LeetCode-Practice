/*给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
示例 1:
输入: [2,2,1]
输出: 1
示例 2:
输入: [4,1,2,1,2]
输出: 4*/

/*
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
class SingleNumber
{
    private:
        map<int,int>num_array;
    public:
        SingleNumber()
        {
            cout<<"Input the values:(Input 0 to stop) "<<endl;
            int temp;
            cin>>temp;
            while(temp)
            {
                num_array.insert(pair<int,int>(temp,0));
                cin>>temp;
            }
        }
        void singleFunction();
};
void SingleNumber::singleFunction()
{
    map<int,int>::iterator iter1;
    map<int,int>::iterator iter2;
    for (iter1=num_array.begin();iter1!=num_array.end();iter1++)
    {
        for (iter2=++iter1;iter2!=num_array.end();iter2++)
        {
            if (iter2->first==iter1->first)
            {
                iter1->second++;
                iter2->second++;
            }
        }
    }
    int index=0;
    for (iter1=num_array.begin();iter1!=num_array.end();iter1++)
    {
        if (iter1->second==0)
        {
            index=1;
            cout<<"The single number is: "<<iter1->first<<endl;
        }
    }
    if (index==0)
    {
        cout<<"No single number. "<<endl;
    }
}
int main()
{
    SingleNumber obj;
    obj.singleFunction();
    system("pause");
    return 0;
}
*/
