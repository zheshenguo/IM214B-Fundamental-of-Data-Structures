#include <iostream>
#include <fstream>

using namespace std;

int BinarySearch(int* a, int x, int left, int right)
{
	// 在排序好的陣列a[left], …, a[right]中找出x
	if (left <= right)
	{
		int middle = (left + right) / 2;

		if (x < a[middle])
		{
			return BinarySearch(a, x, left, middle - 1);
		}
		else if (x > a[middle])
		{
			return BinarySearch(a, x, middle + 1, right);
		}
		else
		{
			return middle;
		}
	}
	// 結束if
	return -1; // 沒找到
}


int main()
{
	// 讀入排好續的整數檔至陣列中
	int const num = 10; //因為陣列的長度必為固定的值 因此將num設定為int const(常數的int變數)
	int a[num];
	ifstream input("test.txt", ios::in);//檔案以輸入方式開啟(檔案資料輸入到記憶體)，括號內為檔案路徑

	if (!input)
	{
		cerr << "Can not open file test.txt." << endl;  //標準錯誤裝置(standard error device)
		return 0;
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			input >> a[i];
		}
		input.close();
	}

	int searchValue; // 要搜尋的值
	cout << "Enter the search value: ";
	cin >> searchValue;  // input searchValue
	int result = BinarySearch(a, searchValue, 0, num);

	cout << "All value : ";
	for (int i = 0; i < num; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	if (result == -1) // 陣列中找不到搜尋值searchValue
		cout << "The search value " << searchValue << " is NOT in the array a. \n";
	else // 搜尋值searchValue所在的位置
		cout << "The index number of search value " << searchValue << " is " << result << " in the array a. \n";
	system("PAUSE");
	return 0;
}