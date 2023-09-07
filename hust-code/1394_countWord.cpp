#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1394/
*/

int main()
{
    string sentence;
    // input(include space)
    while (getline(cin, sentence))
    {
        int count = 0;
        for (int i = 0; i < sentence.length(); i++)
        {
            // a space or a dot
            if (sentence[i] == ' ' || sentence[i] == '.')
            {
                // 离谱。这里有的样例 dot 前还有空格
                if (count != 0)
                {
                    cout << count << " ";
                }
                count = 0;
                
                if (sentence[i] == '.')
                {
                    // jump out of the loop
                    break;
                }
            }
            // a word
            else
            {
                count++;
            }
        }
    }

    return 0;
}