#include <iostream>
#include <fstream>
#include <stack>
#include <algorithm>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1698/
*/

int main()
{
    fstream f("./abc.c", ios::in);
    string sentence;
    stack<string> strStack;
    // stack to store /* */ and //
    bool annotation = false;
    while (getline(f, sentence))
    {
        bool noNewLine = false;
        // sentence = sentence + '\n';
        for (int i = 0; i < sentence.length(); i++)
        {
            if (sentence[i] == '/')
            {
                // block annotation
                if ((i + 1) < sentence.length() && sentence[i + 1] == '*')
                {
                    annotation = true;
                    continue;
                }
                // line annotation
                else if ((i + 1) < sentence.length() && sentence[i + 1] == '/')
                {
                    cout << endl;
                    noNewLine = true;
                    break;
                }
            }
            // end of block annotaion
            else if (sentence[i] == '*' && (i + 1) < sentence.length() && sentence[i + 1] == '/')
            {
                annotation = false;
                i++;
                noNewLine = true;
                break;
            }

            else if (!annotation && !noNewLine)
            {
                cout << sentence[i];
            }
        }
        
        if (!annotation && !noNewLine)
        {
            cout << endl;
        }
    }
    return 0;
}