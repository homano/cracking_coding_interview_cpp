
#include <iostream>
#include <cstring>

using namespace std;

bool isUnique1(string s)
{
	bool a[256];
	memset(a, 0, 256);
	int t = s.length();
	for (int i = 0; i < t; ++i)
	{
		int v = (int)s[i];
		if(a[v]) return false;
		a[v] = true;
	}
	return true;
}

bool isUnique2(string s)
{
	int check = 0;
	int t = s.length();
	for (int i = 0; i < t; ++i)
	{
		int v = (int)(s[i] - 'a');
		if(check & (1 << v)) return false;
		check |= 1 << v;
	}
	return true;

}

int main()
{
	string s = "shuipiaiaia";
	cout << isUnique1(s) << endl;
	return 0;
}