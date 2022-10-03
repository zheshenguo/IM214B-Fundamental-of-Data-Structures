#include <iostream>
#include <fstream>

using namespace std;

int BinarySearch(int* a, int x, int n)
{
	// �b�ƧǦn���}�Ca[left], �K, a[right]����Xx
	int left = 0, right = n; //n = 10
	while (left <= right)
	{
		// �٦�����
		int middle = (left + right) / 2;
		if (x < a[middle])
			right = middle - 1;
		else if (x > a[middle])
			left = middle + 1;
		else
			return middle;
	}
	// while�j�鵲��
	return -1; // �S���
}


int main()
{
	// Ū�J�Ʀn�򪺾���ɦܰ}�C��
	int const num = 10; //�]���}�C�����ץ����T�w���� �]���Nnum�]�w��int const(�`�ƪ�int�ܼ�)
	int a[num];
	ifstream input("test.txt", ios::in);//�ɮץH��J�覡�}��(�ɮ׸�ƿ�J��O����)�A�A�������ɮ׸��|

	if (!input)
	{
		cerr << "Can not open file test.txt." << endl;  //�зǿ��~�˸m(standard error device)
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

	int searchValue; // �n�j�M����
	cout << "Enter the search value: ";
	cin >> searchValue;  // input searchValue
	int result = BinarySearch(a, searchValue, num);

	cout << "All value : ";
	for (int i = 0; i < num; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	if (result == -1) // �}�C���䤣��j�M��searchValue
		cout << "The search value " << searchValue << " is NOT in the array a. \n";
	else // �j�M��searchValue�Ҧb����m
		cout << "The index number of search value " << searchValue << " is " << result << " in the array a. \n";
	system("PAUSE");
	return 0;
}