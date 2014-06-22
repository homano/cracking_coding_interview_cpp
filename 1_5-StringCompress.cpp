//compress string into letters followed by repeated numbers. e.g aabbcc is a2b2c2
//if the compressed string is not smaller than the original, then return the original


#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string IntToString(int num){
	stringstream ss;
	ss << num;
	string str = ss.str();
	return str;
}

int StringToInt(string str){
    
	//int value = atoi(str.c_str());
    stringstream ss(str);
    int value;
    ss >> value;
	return value;
}

string CharToString(char num){
	stringstream ss;
	ss << num;
	string str = ss.str();
	return str;
}

char StringToChar(string str){
    
	//int value = atoi(str.c_str());
    stringstream ss(str);
    char value;
    ss >> value;
	return value;
}

// this method is slower because concatenation is slow
string StringCompress1(string s)
{
	string news = "";
	char last = s[0];
	int count = 1;
	for (int i = 1; i < s.length(); ++i)
	{
		if (s[i] == last)
		{
			count++;/* code */
		}
		else
		{
			news += CharToString(last) + IntToString(count);
			last = s[i];
			count = 1;
		}
	}
	news += CharToString(last) + IntToString(count);
	if (news.length() >= s.length())
		return s;
	else
		return news;
}

int countCompression(string s)
{
	char last =  s[0];
	int size = 0;
	int count = 1;
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i] == last)
		{
			count++;
		}
		else
		{
			last = s[i];
			size += 1 + IntToString(count).length();
			count = 1;
		}
	}
	size += 1 + IntToString(count).length();
	return size;
}
// this method is faster because append method is faster
string StringCompress2(string s)
{
	int size = countCompression(s);
	if (size > s.length())
		return s;
	string news = "";
	char last = s[0];
	int count = 1;
	for (int i = 1; i < s.length(); ++i)
	{
		if (s[i] == last)
		{
			count++;/* code */
		}
		else
		{
			news.append(CharToString(last));
			news.append(IntToString(count));
			last = s[i];
			count = 1;
		}
	}
	news.append(CharToString(last));
	news.append(IntToString(count));
	return news;
}


int main()
{
	string s = "IIII  yyyyyyyy";
    cout << StringCompress2(s) << endl;
	return 0;
}