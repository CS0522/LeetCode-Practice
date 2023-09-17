#include <iostream>
#include <cstring>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1398/
*/

class BigNum
{
public:
    int value[1001] = {0};
    int length;
};

void strToBigNum(string &num, BigNum &bigNum)
{
    // set length
    bigNum.length = num.length();
    // set value（反向，方便进位）
    for (int i = bigNum.length - 1; i >= 0; i--)
    {
        bigNum.value[bigNum.length - 1 - i] = num[i] - '0';
    }
}

void plusOp(BigNum &bigNum1, BigNum &bigNum2, BigNum &result)
{
    int maxLen = (bigNum1.length > bigNum2.length) ? bigNum1.length : bigNum2.length;
    // 进位
    int carry = 0;
    for (int i = 0; i < maxLen; i++)
    {
        result.value[i] = (bigNum1.value[i] + bigNum2.value[i]) % 10 + carry;
        carry = (bigNum1.value[i] + bigNum2.value[i]) / 10;
    }
    // set length and carry
    result.value[maxLen] = carry;
    result.length = (carry == 1) ? ++maxLen : maxLen;
    carry = 0;
}

int main()
{
    string num1, num2;
    while (cin >> num1 >> num2)
    {
        // transfer string into int array
        BigNum bigNum1, bigNum2, result;
        strToBigNum(num1, bigNum1);
        strToBigNum(num2, bigNum2);
        plusOp(bigNum1, bigNum2, result);
        // print
        for (int i = result.length - 1; i >= 0; i--)
        {
            cout << result.value[i];
        }
        cout << endl;
    }
    return 0;
}