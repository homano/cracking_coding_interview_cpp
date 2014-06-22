//13_1 write a method to print the last k lines of a file

#include <iostream>
#include <fstream>
using namespace std;

void printLastK(ifstream &fin, int k){
	string lines[k];
	string tmp;
	int line = 0;
	while (getline(fin, tmp)){
		lines[line%k] = tmp;
		++line;
	}
	int start, cnt;
	if(line < k){
		start = 0;
		cnt = line;
	}
	else {
		start = line % k;
		cnt = k;
	}
	for (int i = 0; i < cnt; ++i)
	{
		cout << lines[(i+start)%k] << endl;
	}
}

int main(){
	ifstream fin("addressbook.txt");
	int k =4;
	printLastK(&fin, k);
	return 0;
}