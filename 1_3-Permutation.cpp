// given two strings, write a method to determine if one is the permutation of the other
#include <iostream>

using namespace std;

bool Permutation(string s1, string s2)
{
	if (s1.length() != s2.length())
	{
		return false;
	}
	int letters[256] = {0};
	for (int i = 0; i < s1.length(); ++i)
	{
		int t = (int)s1[i];
		letters[t]++;
	}
	for (int i = 0; i < s2.length(); ++i)
	{
		int t = (int)s2[i];
		if (--letters[t] < 0)
			return false;
	}
	return true;
}

int main()
{
	string s1 = "I love you1";
	string s2 = "you love I";
	cout << Permutation(s1, s2) << endl;
	return 0;
}