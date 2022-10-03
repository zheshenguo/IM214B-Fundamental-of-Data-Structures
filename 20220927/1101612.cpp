#include <iostream>
#include <cstdlib>

using namespace std;

void SelectionSort(int *num, int len);

int main(void)
{
	int len = 0;
	cout << "請輸入陣列空間:";
	cin >> len;
	int* num = new int[len];

	cout << "請輸入陣列資料:";
	for (int i = 0; i < len; i++)
	{
		cin >> *(num + i);
	}

	cout << "原本的陣列資料:\n";
	for (int i = 0; i < len; i++)
	{
		cout << *(num + i) << " ";
	}
	cout << "\n";

	SelectionSort(num, len);

	cout << "排序後的資料:\n";
	for (int i = 0; i < len; i++)
	{
		cout << *(num + i) << " ";
	}
	cout << "\n";
	return 0;
}

void SelectionSort(int* num, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < len; j++)
		{
			if (num[j] < num[min_idx])
			{
				min_idx = j;
			}
		}
		swap(num[min_idx], num[i]);
	}
}

