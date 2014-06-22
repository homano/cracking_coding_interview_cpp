// if an element in an M x N matrix is zero, then its entire row and column are set to zero

// given an image represented by NxN matrix, if each pixel is represented by 4 bytes, can you
// rotate the image by 90 degrees and do this in place?

#include <iostream>
#include <iomanip>
using namespace std;

void zero(int a[][4], int n)
{
	bool row[n], col[4];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (a[i][j] == 0)
			{
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
    
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (row[i] || col[j])
			{
				a[i][j] = 0;
			}
		}
	}
    
}

int main()
{
	int a[4][4] = {{1,2,0,4}, {0,6,7,8}, {9,10,11,12}, {13,14,15,16}};
	zero(a, 4);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	return 0;
}