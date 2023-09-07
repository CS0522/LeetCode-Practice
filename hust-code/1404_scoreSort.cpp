#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1404/
*/

class Student
{
public:
    string name;
    int age;
    int score;
};

bool cmp(Student a, Student b)
{
    if (a.score == b.score)
    {
        if (a.name == b.name)
        {
            return a.age < b.age;
        }
        else
        {
            return a.name < b.name;
        }
    }
    return a.score < b.score;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<Student> studentVector;
        while (n-- > 0)
        {  
            string _name;
            int _age, _score;
            cin >> _name >> _age >> _score;
            Student newStudent;
            newStudent.name = _name;
            newStudent.age = _age;
            newStudent.score = _score;

            studentVector.push_back(newStudent);
        }

        // sort
        sort(studentVector.begin(), studentVector.end(), cmp);

        // print
        for (vector<Student>::iterator it = studentVector.begin(); it != studentVector.end(); it++)
        {
            cout << it->name << " " << it->age << " " << it->score << endl;
        }
    }
    return 0;
}