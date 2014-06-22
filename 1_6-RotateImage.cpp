// given an image represented by NxN matrix, if each pixel is represented by 4 bytes, can you
// rotate the image by 90 degrees and do this in place?

#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

void RotateImage(int a[][4], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int k = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = k;
		}
	}
	// for clockwise rotation, switch the columns, while for counterclokwise, switch the rows
	for (int i = 0; i < n/2; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int k = a[j][i];
			a[j][i] = a[j][n-1-i];
			a[j][n-1-i] = k;
		}
	}
    
}

int main()
{
	int a[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
	RotateImage(a, 4);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			cout << setw(4) << a[i][j];
        cout << endl;
	}
	return 0;
}