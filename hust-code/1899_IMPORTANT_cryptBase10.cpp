#include <iostream>
using namespace std;

/*
https://noobdream.com/DreamJudge/Issue/page/1899/
*/

int main()
{
	long long n;
	while(cin >> n)
	{
		long long e = n & 0x000f0f0f;
		long long p = n & 0x0f000000;
		long long x = n - e - p;
		long long res = (e << 8) + (p >> 24) + x;
		cout << res << endl;
	}
}