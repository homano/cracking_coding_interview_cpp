// replace all spaces in a string with a series of characters e.g. "%20" and assuming that
//there are two methods of doing this
// 1. one is to use character array by which you can
// process in place. In that case, first of all, you need to determine the number of spaces,
//, then work the character array backwards for spaces replacement because
// we have extra buffer in the end so we don't need to worry about the overwriting.
// 2. use the string directly, then we should return a new copy of the string.


#include <iostream>
#include <cstring>
using namespace std;

string SpaceReplacement1(string s)
{
	string news = "";
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == ' ')
			news += "%20";
		else news += s[i];
	}
	return news;
}

void SpaceReplacement2(char* s)
{
	int len = strlen(s);
	// count is the number of spaces
	int count = 0;
	for (int i = 0; i < len; ++i)
	{
		if (s[i] == ' ')
        {
             ++count;
        }
       
	}
	// newlen is the new length of the new character array
	int newlen = len + count * 2;
	s[newlen] = '\0';
	for (int i = len - 1; i >= 0; --i)
	{
		if (s[i] == ' ')
		{
			s[newlen - 1] = '0';
			s[newlen - 2] = '2';
			s[newlen - 3] = '%';
			newlen -= 3;
		}
		else
		{
			s[newlen - 1] = s[i];
			newlen -= 1;
		}
	}
}

int main()
{
	char s[] = "I love you";
	string s1 = "I love you";
    SpaceReplacement2(s);
	cout << s << endl;
	cout << SpaceReplacement1(s1) << endl;
	return 0;
}