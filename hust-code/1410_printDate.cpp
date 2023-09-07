#include <iostream>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1410/
*/

int main()
{
    // month 数组，判断该月是 31 天还是 30 天以及闰年、平年
    int monthday[13][2] = {{0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, 
                            {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};

    int year, n;
    while (cin >> year >> n)
    {
        // 判断是否为闰年
        int flag = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 1 : 0;
        
        int month = 1, day = 0;
        // 循环 ++
        for (; n != 0; n--)
        {
            day += 1;
            if (day > monthday[month][flag])
            {
                day = 1;
                month += 1;
            }
            if (month > 12)
            {
                month = 1;
                year += 1;
            }
        }

        // print
        printf("%04d-%02d-%02d\n", year, month, day);
    }

    return 0;
}
