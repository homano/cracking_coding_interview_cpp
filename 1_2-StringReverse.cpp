#include <iostream>
#include <cstring>

using namespace std;

void swap(char &a, char &b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}

void reverse1(char *s)
{
	int len = strlen(s);
	for (int i = 0; i < len/2; ++i)
	{
		swap(s[i],s[len-i-1]);
	}
}

void reverse2(char *s)
{
	if(!s) return;
	char *p = s, *q = s;
	while(*q)
		++q;
	--q;
	while(p<q)
		swap(*p++, *q--);
}

int main()
{
	char s[] = "shu123456";
    reverse2(s);
	cout << s << endl;
	return 0;
}