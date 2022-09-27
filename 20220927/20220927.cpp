#include <iostream>
#include <cstdlib>

using namespace std;

void SelectionSort(int *num, int len);

int main(void)
{
	int len = 0;
	cout << "�п�J�}�C�Ŷ�:";
	cin >> len;
	int* num = new int[len];

	cout << "�п�J�}�C���:";
	for (int i = 0; i < len; i++)
	{
		cin >> *(num + i);
	}

	cout << "�쥻���}�C���:\n";
	for (int i = 0; i < len; i++)
	{
		cout << *(num + i) << " ";
	}
	cout << "\n";

	SelectionSort(num, len);

	cout << "�Ƨǫ᪺���:\n";
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

