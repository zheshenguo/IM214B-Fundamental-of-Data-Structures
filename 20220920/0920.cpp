#include <iostream>
#include <cstdlib>
using namespace std;

// declare findmax function
void findmax(int *, int);

int main(void)
{
	int m[6] = { 5, 2, 6, 3, 1, 4 };
	findmax(m, 6);

	system("PAUSE");
	return(0);
}

// use pointers to find the maximum value in an array
void findmax(int * m, int n)
{
	int max = *m;
	for (int i = 0; i < n; i++)
	{
		if (max < *(m + i))
		{
			max = *(m + i);
		}
	}
	cout << "maximum value: " << max << endl;
}
