// given you have a method isSubstring checking if one string is a substring of another
// write a method to deterimine is s2 is a rotation of s using only call to isSubstring


#include <iostream>
#include <string>
using namespace std;

// check is string s2 is a substring of string s1
bool isSubstring(string s1, string s2)
{
	if(s1.find(s2) != string::npos)
		return true;
	return false;
}

// check if s2 is a rotation of s2
bool Rotation(string s1, string s2)
{
	return isSubstring(s1+s1, s2);
}

int main()
{
	string s1 = "waterbottle";
	string s2 = "aterbottlew";
	cout << Rotation(s1, s2) << endl;
	return 0;
}